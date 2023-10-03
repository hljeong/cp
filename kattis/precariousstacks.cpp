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

template<size_t N>
struct sgt {
  ll id = 0;
  vll val, lz;

  sgt() : val(4 * N + 5, id), lz(4 * N + 5, id) {}

  sgt(vi &a) : val(4 * N + 5, id), lz(4 * N + 5, id) { build(a); }

  ll merge(ll a, ll b) { return max(a, b); }

  ll update(ll a, ll b) { return max(a, b); }

  int mid(int l, int r) { return l + (r - l) / 2; }

  void pull(int u) { val[u] = merge(val[u << 1], val[u << 1 | 1]); }

  void push(int u, int l, int r) {
    if (lz[u] == id) return;
    ckmax(val[u],lz[u]);
    if (l != r) {
      lz[u << 1] = update(lz[u << 1], lz[u]);
      lz[u << 1 | 1] = update(lz[u << 1 | 1], lz[u]);
    }
    lz[u] = id;
  }

  void build(vi &a, int u = 1, int l = 0, int r = N - 1) {
    push(u, l, r);
    if (l > a.size()) return;
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
    push(u, l, r);
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
  cin.tie(0) -> sync_with_stdio(0);

  int n; cin >> n;
  si comp;
  vc<pi> drop;
  for (int i = 0; i < n; ++i) {
    int x, s; cin >> x >> s;
    comp.insert(x);
    comp.insert(x + s - 1);
    drop.pb({x, s});
  }
  mi inv; int id = 0;
  for (int x : comp) inv[x] = id++;
  sgt<200005> t;
  for (int i = 0; i < n; ++i) {
    auto [x, s] = drop[i];
    int l = inv[x], r = inv[x + s - 1];
    t.upd(l, r, t.qry(l, r) + s);
    cout << t.qry(0, id - 1) << endl;
  }
}
