#ifndef TMPL
#define TMPL
#include <bits/stdc++.h>
#define A first
#define B second
#define pb push_back
#define endl '\n'
#define tT template <class T
#define tTU tT, class U
using namespace std;
tT> using vc = vector<T>;
tT, int N> using ar = array<T, N>;
using ll = long long; using ld = long double;
using vi = vc<int>; using vll = vc<ll>;
using si = set<int>; using sll = set<ll>;
using pi = pair<int, int>; using pll = pair<ll, ll>;
using qi = queue<int>;
using mii = map<int, int>;
using str = string;

tT> ostream &operator<<(ostream &os, const vc<T> &a) {
  for (int i = 0, n = a.size(); i < n; i++) os << (i ? " " : "") << a[i];
  return os;
}

tT, size_t N> ostream &operator<<(ostream &os, const ar<T, N> &a) {
  for (int i = 0; i < N; i++) os << (i ? " " : "") << a[i];
  return os;
}

tTU> istream& operator>>(istream &i, pair<T, U> &p) { return i >> p.A >> p.B; }

tT> T rd() { T x; cin >> x; return x; }

tT> vc<T> rda(int n) {
  vc<T> v(n);
  for (int i = 0; i < n; i++) cin >> v[i];
  return v;
}

int ri() { return rd<int>(); }
ll rll() { return rd<ll>(); }
str rs() { return rd<str>(); }
vi ria(int n) { return rda<int>(n); }
vll rlla(int n) { return rda<ll>(n); }

tTU> constexpr decltype(declval<T>() + declval<U>()) max(T a, U b) { return a > b ? a : b; }
tTU> constexpr decltype(declval<T>() + declval<U>()) min(T a, U b) { return a < b ? a : b; }
tTU> constexpr bool ckmin(T &a, U b) { return b < a ? a = b, 1 : 0; }
tTU> constexpr bool ckmax(T &a, U b) { return a < b ? a = b, 1 : 0; }
tT> constexpr T nth_bit(T x, int n) { return (x >> n) & 1; }
tTU> T minst(T l, T r, U pred) {
  T ans = r + 1;
  while (l <= r) {
    T m = l + (r - l) / 2;
    if (pred(m)) r = (ans = m) - 1;
    else l = m + 1;
  }
  return ans;
}
tTU> T maxst(T l, T r, U pred) {
  T ans = l - 1;
  while (l <= r) {
    T m = l + (r - l) / 2;
    if (pred(m)) l = (ans = m) + 1;
    else r = m - 1;
  }
  return ans;
}

constexpr int inf = 1e9 + 7;
constexpr int mod = inf;
constexpr ll infll = 0x3f3f'3f3f'3f3f'3f3fll;

struct dsu {
  vi p, sz;
  vll sum, chaos;
  dsu(int n) : p(n), sz(n, 1), sum(n), chaos(n) { for (int i = 0; i < n; i++) p[i] = i; }
  int find(int u) { return (u == p[u]) ? u : (p[u] = find(p[u])); }
  bool combine(int u, int v) {
    if ((u = find(u)) == (v = find(v))) return false;
    if (sz[u] < sz[v]) swap(u, v);
    p[v] = u; sz[u] += sz[v];
    sum[u] += sum[v]; chaos[u] = (sum[u] + 9) / 10 * 10;
    return true;
  }
};

// ucla tryout #2 2024 virtual
// connect stuff in reverse order, recompute affected components in O(1)

void solve() {
  int n = ri();
  vi p = ria(n);
  vi perm = ria(n);
  for (int i = 0; i < n; i++) perm[i]--;
  reverse(perm.begin(), perm.end());
  ll ret = 0;
  ll tot_chaos = 0;
  int cnt = 0;
  vi vis(n);
  dsu d(n);
  for (int i = 0; i < n; i++) {
    d.sum[i] = p[i];
    d.chaos[i] = (p[i] + 9) / 10 * 10;
  }
  for (int i = 0; i < n; i++) {
    int pi = perm[i];
    cnt++;
    vis[pi] = true;
    if (pi && vis[pi - 1]) {
      cnt--;
      tot_chaos -= d.chaos[d.find(pi - 1)];
      d.combine(pi, pi - 1);
    }
    if (pi < n - 1 && vis[pi + 1]) {
      cnt--;
      tot_chaos -= d.chaos[d.find(pi + 1)];
      d.combine(pi, pi + 1);
    }
    tot_chaos += d.chaos[d.find(pi)];
    ckmax(ret, tot_chaos * cnt);
  }
  cout << ret << endl;
}

int main() {
  cin.tie(0)->sync_with_stdio(0);

  int t = 1;
  // int t = ri();
  while (t--) solve();
}

#endif
