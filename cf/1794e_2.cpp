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

template<int M>
struct modint {
  int v;
  explicit operator int() const { return v; }

  modint() : v(0) {}
  modint(ll _v) { 
    v = int((-M <= _v && _v < M) ? _v : _v % M);
    if (v < 0) v += M;
  }

  bool operator==(const modint &o) const { return v == o.v; }
  friend bool operator!=(const modint &a, const modint &b) { return !(a == b); }
  friend bool operator<(const modint &a, const modint &b) { return a.v < b.v; }
   
  modint& operator+=(const modint &o) { if ((v += o.v) >= M) v -= M; return *this; }
  modint& operator-=(const modint &o) { if ((v -= o.v) < 0) v += M; return *this; }
  modint& operator*=(const modint &o) { v = int((ll)v * o.v % M); return *this; }
  modint& operator/=(const modint &o) { return (*this) *= inv(o); }

  friend modint inv(const modint &x);
  friend modint pow(modint b, ll e) {
    if (e < 0) return pow(inv(b), -e);
    modint ans = 1;
    for (; e; e >>= 1, b *= b) if (e & 1) ans *= b;
    return ans;
  }
  friend modint inv(const modint &x) {
    assert(x.v != 0); 
    return pow(x, M - 2);
  }
    
  modint operator-() const { return modint(-v); }
  modint& operator++() { return *this += 1; }
  modint& operator--() { return *this -= 1; }
  friend modint operator+(modint a, const modint& b) { return a += b; }
  friend modint operator-(modint a, const modint& b) { return a -= b; }
  friend modint operator*(modint a, const modint& b) { return a *= b; }
  friend modint operator/(modint a, const modint& b) { return a /= b; }

  friend ostream& operator<<(ostream& stream, const modint& x) { stream << int(x); return stream; }
  friend istream& operator>>(istream& stream, modint& x) { stream >> x.v; return stream; }
};

using mint = modint<mod>;

const mint B1 = 10, B2 = 2000023;
vc<mint> pB1, pB2;

struct phash {
  pair<mint, mint> v;

  phash() : v({0, 0}) {}
  phash(int _v) : v({_v, _v}) {}
  phash(int v1, int v2) : v({v1, v2}) {}

  bool operator==(const phash &o) const { return v == o.v; }
  friend bool operator!=(const phash &a, const phash &b) { return !(a == b); }
  friend bool operator<(const phash &a, const phash &b) { return a.v < b.v; }
   
  phash& operator+=(const phash &o) { v.A += o.v.A; v.B += o.v.B; return *this; } 
  phash& operator-=(const phash &o) { v.A -= o.v.A; v.B -= o.v.B; return *this; }
  phash& operator*=(const phash &o) { v.A *= o.v.A; v.B *= o.v.B; return *this; }
  phash& operator/=(const phash &o) { v.A /= o.v.A; v.B /= o.v.B; return *this; }
  phash& operator<<=(const int p) { v.A *= pB1[p]; v.B *= pB2[p]; return *this; }
  phash& operator>>=(const int p) { v.A /= pB1[p]; v.B /= pB2[p]; return *this; }

  phash operator-() const { return phash(int(-v.A), int(-v.B)); }
  phash& operator++() { return *this += 1; }
  phash& operator--() { return *this -= 1; }
  friend phash operator+(phash a, const phash& b) { return a += b; }
  friend phash operator-(phash a, const phash& b) { return a -= b; }
  friend phash operator*(phash a, const phash& b) { return a *= b; }
  friend phash operator/(phash a, const phash& b) { return a /= b; }
  friend phash operator<<(phash a, int b) { return a <<= b; }
  friend phash operator>>(phash a, int b) { return a >>= b; }

  friend ostream& operator<<(ostream& stream, const phash& x) { stream << "(" << x.v.A << ", " << x.v.B << ")"; return stream; }
};

void init_phash(int n) {
  pB1 = vc<mint>(n + 1);
  pB2 = vc<mint>(n + 1);
  pB1[0] = pB2[0] = 1;
  for (int i = 1; i <= n; ++i) {
    pB1[i] = pB1[i - 1] * B1;
    pB2[i] = pB2[i - 1] * B2;
  }
}

struct graph {
  vc<vi> adj;
  vc<map<int, ll>> w;

  graph(int n) : adj(n, vi()), w(n, map<int, ll>()) {}
  graph(const graph &g) : adj(g.adj), w(g.w) {}
  graph(int n, int m, int off = 1) : adj(n, vi()), w(n, map<int, ll>()) {
    for (int i = 0, u, v; i < m; ++i) {
      cin >> u >> v; u -= off; v -= off;
      c(u, v);
    }
  }

  void cto(int from, int to, ll weight) { adj[from].pb(to); w[from][to] += weight; }
  void cto(int from, int to) { cto(from, to, 1); }
  void c(int from, int to) { cto(from, to); cto(to, from); }
  void c(int from, int to, ll weight) { cto(from, to, weight); cto(to, from, weight); }

  vi operator[](int u) { return adj[u]; }
  vc<vi>::iterator begin() { return adj.begin(); }
  vc<vi>::const_iterator begin() const { return adj.begin(); }
  vc<vi>::iterator end() { return adj.end(); }
  vc<vi>::const_iterator end() const { return adj.end(); }
  int size() const { return adj.size(); }
};

void dfs(graph &g, int i, int p, vc<phash> &h) {
  h[i] = 1;
  for (int j : g[i]) {
    if (j == p) continue;
    dfs(g, j, i, h);
    h[i] += h[j] << 1;
  }
}

void reroot(graph &g, int i, int p, set<phash> &good, vc<phash> &h, vi &ret) {
  if (good.count(h[i])) {
    ret.pb(i + 1);
  }
  for (int j : g[i]) {
    if (j == p) continue;
    h[i] -= h[j] << 1;
    h[j] += h[i] << 1;
    reroot(g, j, i, good, h, ret);
    h[j] -= h[i] << 1;
    h[i] += h[j] << 1;
  }
}

int main() {
  cin.tie(0) -> sync_with_stdio(0);
  init_phash(200005);

  int n; cin >> n;
  phash ph = 0;
  vi a(n - 1); for (int i = 0; i < n - 1; ++i) {
    cin >> a[i];
    ph += phash(1) << a[i];
  }
  set<phash> good;
  for (int i = 0; i < n; ++i) {
    good.insert(ph + (phash(1) << i));
  }
  graph g(n, n - 1);
  vc<phash> h(n);
  dfs(g, 0, -1, h);
  vi ret;
  reroot(g, 0, -1, good, h, ret);
  sort(ret.begin(), ret.end());
  int m = ret.size();
  cout << m << endl;
  for (int i = 0; i < m; ++i) cout << ret[i] << " \n"[i == m - 1];
}
