#include <bits/stdc++.h>
#define A first
#define B second
#define vc vector
#define pb push_back
#define endl '\n'
using namespace std;
using ll = long long; using ld = long double;
using vi = vc<int>; using vll = vc<ll>;
using si = set<int>; using sll = set<ll>;
using pi = pair<int, int>; using pll = pair<ll, ll>;
using qi = queue<int>; using mi = map<int, int>;

template<class T> bool ckmin(T &a, const T &b) { return b < a ? a = b, 1 : 0; }
template<class T> bool ckmax(T &a, const T &b) { return a < b ? a = b, 1 : 0; }

const int inf = 1e9 + 7;
const int mod = inf;
const ll infll = 0x3f3f3f3f3f3f3f3fll;

int mid(int l, int r) {
  return l + (r - l) / 2;
}

template<typename T, size_t N>
struct sgt {
  vc<T> val;
  function<T(const T&, const T&)> merge, update;

  sgt(function<T(const T&, const T&)> merge, function<T(const T&, const T&)> update) : val(4 * N + 5), merge(merge), update(update) {}

  sgt(const vc<T> &a, function<T(const T&, const T&)> merge, function<T(const T&, const T&)> update) : val(4 * N + 5), merge(merge), update(update) {
    build(a);
  }

  void pull(int u) {
    val[u] = merge(val[u << 1], val[u << 1 | 1]);
  }

  void build(const vc<T> &a, int u = 1, int l = 0, int r = N - 1) {
    if (l >= a.size()) return;
    if (l == r) val[u] = a[l];
    else {
      int m = mid(l, r);
      build(a, u << 1 , l, m);
      build(a, u << 1 | 1, m + 1, r);
      pull(u);
    }
  }

  void upd(int i, const T &x, int u = 1, int l = 0, int r = N - 1) {
    if (l == r) val[u] = update(val[u], x);
    else {
      int m = mid(l, r);
      if (i <= m) upd(i, x, u << 1, l, m);
      else upd(i, x, u << 1 | 1, m + 1, r);
      pull(u);
    }
  }

  T qry(int i, int j, int u = 1, int l = 0, int r = N - 1) {
    if (j < l || r < i) return ~0;
    if (i <= l && r <= j) return val[u];
    int m = mid(l, r);
    return merge(qry(i, j, u << 1, l, m), qry(i, j, u << 1 | 1, m + 1, r));
  }

  int minst_r(function<bool(T&, int, int)> pred, int i, int j, int u, int l, int r, T &acc) {
    if (r < i) return -1;
    if (j < l) return j + 1;
    T v = merge(acc, val[u]);
    if (i <= l && r <= j && !pred(v, i, r)) {
      acc = merge(acc, val[u]);
      if (r == j) return j + 1;
      return -1;
    }
    if (l == r) return l;

    int m = mid(l, r), ret;
    if (~(ret = minst_r(pred, i, j, u << 1, l, m, acc))) return ret;
    return minst_r(pred, i, j, u << 1 | 1, m + 1, r, acc);
  }

  int minst(function<bool(T&, int, int)> pred, int i = 0, int j = N - 1) {
    T acc = ~0;
    return minst_r(pred, i, j, 1, 0, N - 1, acc);
  }
};

int main() {
  cin.tie(0) -> sync_with_stdio(0);

  function<int(const int&, const int&)> merge = [&](const int& a, const int& b) {
    return a & b;
  };
  sgt<int, 200005> tr(merge, merge);
  int t; cin >> t;
  while (t--) {
    int n; cin >> n;
    vi a(n); for (int i = 0; i < n; ++i) cin >> a[i];
    tr.build(a);
    int q; cin >> q;
    while (q--) {
      int l, k; cin >> l >> k; --l;
      function<bool(int&, int, int)> pred = [&](int& val, int x, int y) {
        return val < k;
      };
      if (a[l] < k) cout << -1 << ' ';
      else cout << tr.minst(pred, l, n - 1) << ' ';
    }
    cout << endl;
  }
}
