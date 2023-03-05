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

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

int randi(int mn, int mx) {
  return uniform_int_distribution<int>(mn, mx + 1)(rng);
}

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

using phash_mint = modint<1000000009>;
const phash_mint B1 = 998244353, B2 = 1000000007;
vc<phash_mint> pB1, pB2;

struct phash {
  pair<phash_mint, phash_mint> v;

  phash() : v({0, 0}) {}
  phash(int _v) : v({_v, _v}) {}
  phash(int v1, int v2) : v({v1, v2}) {}

  bool operator==(const phash &o) const { return v == o.v; }
  friend bool operator!=(const phash &a, const phash &b) { return !(a == b); }
  friend bool operator<(const phash &a, const phash &b) { return a.v < b.v; }
   
  phash& operator+=(const phash &o) { v.A += o.v.A; v.B += o.v.B; return *this; } 
  phash& operator-=(const phash &o) { v.A -= o.v.A; v.B += o.v.B; return *this; }
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
  pB1 = vc<phash_mint>(n + 1);
  pB2 = vc<phash_mint>(n + 1);
  pB1[0] = pB2[0] = 1;
  for (int i = 1; i <= n; ++i) {
    pB1[i] = pB1[i - 1] * B1;
    pB2[i] = pB2[i - 1] * B2;
  }
}

// https://rng-58.blogspot.com/2017/02/hashing-and-probability-of-collision.html
void iso_thash(graph &g, int i, int p, int d, vi &x, vc<phash> &h) {
  h[i] = 1;
  for (int j : g[i]) {
    if (j == p) continue;
    iso_thash(g, j, i, d + 1, x, h);
    h[i] *= x[d] + h[j];
  }
}

int check(graph &g, int i, int p, vc<phash> &h) {
  map<phash, int> f;
  for (int j : g[i]) {
    if (j == p) continue;
    ++f[h[j]];
  }
  int ocnt = 0;
  for (int j : g[i]) {
    if (j == p) continue;
    if (f[h[j]] & 1)
      if (++ocnt > f[h[j]] || !check(g, j, i, h)) return 0;
  }
  return 1;
}

int main() {
  cin.tie(0) -> sync_with_stdio(0);
  init_phash(200005);

  int t; cin >> t;
  while (t--) {
    int n; cin >> n;
    graph g(n, n - 1);
    vi x(n);
    for (int i = 0; i < n; ++i) x[i] = randi(1, 998244352);
    vc<phash> h(n);
    iso_thash(g, 0, -1, 0, x, h);
    cout << (check(g, 0, -1, h) ? "YES" : "NO") << endl;
  }
}
