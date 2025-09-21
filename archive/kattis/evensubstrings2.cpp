#include <bits/stdc++.h>
#define A first
#define B second
#define vc vector
#define pb push_back
using namespace std;
using ll = long long; using ld = long double;
using vi = vc<int>; using vll = vc<ll>;
using si = set<int>; using sll = set<ll>;
using pii = pair<int, int>; using mii = map<int, int>;

template<class T> bool ckmin(T &a, const T &b) { return b < a ? a = b, 1 : 0; }
template<class T> bool ckmax(T &a, const T &b) { return a < b ? a = b, 1 : 0; }

const int inf = 1e9 + 7;
const int mod = inf;
const ll infll = 0x3f3f3f3f3f3f3f3fll;

using a64 = array<ll, 64>;

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
    if (l > a.size()) return;
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
    if (j < l || r < i) return T();
    if (i <= l && r <= j) return val[u];
    int m = mid(l, r);
    return merge(qry(i, j, u << 1, l, m), qry(i, j, u << 1 | 1, m + 1, r));
  }

  int minst_r(function<bool(T&, int, int)> pred, int i, int j, int u, int l, int r, T &acc) {
    if (r < i) return -1;
    if (j < l) return j + 1;
    if (i <= l && r <= j && !pred(merge(acc, val[u]), i, r)) {
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
    T acc = T();
    return minst_r(pred, i, j, 1, 0, N - 1, acc);
  }
};

using T = pair<array<a64, 2>, pair<ll, int>>;

T ch2s(char c) {
  int x = 1 << (c - 'a');
  T ret;
  ret.A[0][x] = ret.A[1][x] = 1;
  ret.B.A = 0;
  ret.B.B = x;
  return ret;
}

int main() {
  string s; cin >> s;
  int n = s.length();
  vc<T> b(n);
  for (int i = 0; i < n; ++i) b[i] = ch2s(s[i]);
  sgt<T, (int) (2e5 + 5)> st(
    b, 
    (function<T(const T&, const T&)>) [&](const T &a, const T &b) {
      T ret;
      for (int i = 0; i < 64; ++i) {
        ret.A[0][i] = a.A[0][i] + b.A[0][i ^ a.B.B]; // prefix freq
        ret.A[1][i] = b.A[1][i] + a.A[1][i ^ b.B.B]; // suffix freq
        ret.B.A += a.A[1][i] * b.A[0][i]; // count 0
      }
      ret.B.A += a.B.A + b.B.A;
      ret.B.B = a.B.B ^ b.B.B; // sum
      return ret;
    }, 
    (function<T(const T&, const T&)>) [&](const T &a, const T &b) {
      return b;
    }
  );
  int q; cin >> q;
  while (q--) {
    int t; cin >> t;
    if (t == 1) {
      int l, r; cin >> l >> r; --l; --r;
      cout << st.qry(l, r).B.A << endl;
    } else {
      int i; string x; cin >> i >> x; --i;
      st.upd(i, ch2s(x[0]));
    }
  }
}
