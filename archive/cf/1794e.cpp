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
const int mod = 1e9 + 9;
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

void compute(graph &g, int i, int p, vc<pair<mint, mint>> &h, vc<mint> &p1, vc<mint> &p2) {
  h[i].A = h[i].B = 1;
  for (int j : g[i]) {
    if (j == p) continue;
    compute(g, j, i, h, p1, p2);
    h[i].A += p1[1] * h[j].A;
    h[i].B += p2[1] * h[j].B;
  }
}

void reroot(graph &g, int i, int p, vc<pair<mint, mint>> &h, set<pair<mint, mint>> &good, vi &ret, vc<mint> &p1, vc<mint> &p2) {
  if (good.count(h[i])) {
    ret.pb(i + 1);
  }
  for (int j : g[i]) {
    if (j == p) continue;
    h[i].A -= p1[1] * h[j].A;
    h[i].B -= p2[1] * h[j].B;
    h[j].A += p1[1] * h[i].A;
    h[j].B += p2[1] * h[i].B;
    reroot(g, j, i, h, good, ret, p1, p2);
    h[j].A -= p1[1] * h[i].A;
    h[j].B -= p2[1] * h[i].B;
    h[i].A += p1[1] * h[j].A;
    h[i].B += p2[1] * h[j].B;
  }
}

int main() {
  cin.tie(0) -> sync_with_stdio(0);

  vc<mint> p1(200005), p2(200005);
  p1[0] = p2[0] = 1;
  for (int i = 1; i < 200005; ++i) {
    p1[i] = p1[i - 1] * 10;
    // p1[i] = p1[i - 1] * 998244353;
    p2[i] = p2[i - 1] * 1000000007;
  }
   
  int n; cin >> n;
  pair<mint, mint> ogh;
  vi a(n - 1); for (int i = 0; i < n - 1; ++i) {
    cin >> a[i];
    ogh.A += p1[a[i]];
    ogh.B += p2[a[i]];
  }
  graph g(n, n - 1);
  set<pair<mint, mint>> good;
  for (int i = 0; i < n; ++i) {
    auto nh = ogh;
    nh.A += p1[i];
    nh.B += p2[i];
    good.insert(nh);
  }
  vc<pair<mint, mint>> h(n);
  compute(g, 0, -1, h, p1, p2);
  vi ret;
  reroot(g, 0, -1, h, good, ret, p1, p2);
  sort(ret.begin(), ret.end());
  int m = ret.size();
  cout << m << endl;
  for (int i = 0; i < m; ++i) {
    cout << ret[i] << " \n"[i == m - 1];
  }
}
