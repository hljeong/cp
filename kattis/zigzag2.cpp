#include <bits/stdc++.h>
#define A first
#define B second
#define vc vector
#define pb push_back
using namespace std;
using ll = long long; using ld = long double;
using vi = vc<int>; using vll = vc<ll>;
using si = set<int>; using sll = set<ll>;
using pii = pair<int, int>; using pll = pair<ll, ll>;
using mii = map<int, int>;

template<class T> bool ckmin(T &a, const T &b) { return b < a ? a = b, 1 : 0; }
template<class T> bool ckmax(T &a, const T &b) { return a < b ? a = b, 1 : 0; }

const int inf = 1e9 + 7;
const int mod = inf;
const ll infll = 0x3f3f3f3f3f3f3f3fll;

template<size_t N>
struct sgt {
  ll id = -inf;
  vll val, lz;

  sgt() : val(4 * N + 5, id), lz(4 * N + 5, id) {}

  sgt(vi &a) : val(4 * N + 5, id), lz(4 * N + 5, id) { build(a); }

  ll merge(ll a, ll b) { return max(a, b); }

  ll update(ll a, ll b) { return max(a, b); }

  int mid(int l, int r) { return l + (r - l) / 2; }

  void pull(int u) { val[u] = merge(val[u << 1], val[u << 1 | 1]); }

  void push(int u, int l, int r) {
    if (lz[u] == id) return;
    ckmax(val[u], lz[u]);
    if (l != r) {
      lz[u << 1] = update(lz[u << 1], lz[u]);
      lz[u << 1 | 1] = update(lz[u << 1 | 1], lz[u]);
    }
    lz[u] = id;
  }

  void build(vi &a, int u = 1, int l = 0, int r = N - 1) {
    if (l >= a.size()) return;
    if (l == r) val[u] = a[l];
    else {
      int m = mid(l, r);
      build(a, u << 1 , l, m);
      build(a, u << 1 | 1, m + 1, r);
      pull(u);
    }
  }

  void upd(int i, int j, ll x, int u = 1, int l = 0, int r = N - 1) {
    push(u, l, r);
    if (j < l || r < i) return;
    if (i <= l && r <= j) {
      lz[u] = x; push(u, l, r);
    } else {
      int m = mid(l, r);
      upd(i, j, x, u << 1, l, m);
      upd(i, j, x, u << 1 | 1, m + 1, r);
      pull(u);
    }
  }

  void upd(int i, ll x) {
    upd(i, i, x);
  }

  ll qry(int i, int j, int u = 1, int l = 0, int r = N - 1) {
    if (j < l || r < i) return id;
    if (i <= l && r <= j) return val[u];
    int m = mid(l, r);
    return merge(qry(i, j, u << 1, l, m), qry(i, j, u << 1 | 1, m + 1, r));
  }
  
  ll qry(int i) {
    return qry(i, i);
  }
};

int main() {
  int n, ret = 1; cin >> n;
  vi a(1000000);
  sgt<1000000> d(a), u(a);
  for (int i = 0; i < n; ++i) {
    int k; cin >> k; --k;
    int nu = 1 + d.qry(0, k - 1);
    int nd = 1 + u.qry(k + 1, 999999);
    d.upd(k, nd); u.upd(k, nu);
    ckmax(ret, nd); ckmax(ret, nu);
    int cnt = 0;
  }
  cout << ret << endl;
}
