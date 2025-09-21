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
using gr = vc<vi>; using wgr = vc<vc<pii>>;

template<class T> bool ckmin(T &a, const T &b) { return b < a ? a = b, 1 : 0; }
template<class T> bool ckmax(T &a, const T &b) { return a < b ? a = b, 1 : 0; }

const int inf = 1e9 + 7;
const int mod = inf;
const ll infll = 0x3f3f3f3f3f3f3f3fll;

struct dsu {
  vi par, sz;

  dsu(int n) : par(vi(n)), sz(vi(n)) {
    for (int i = 0; i < n; ++i) { par[i] = i; sz[i] = 1; }
  }

  int find(int i) {
    return par[i] == i ? i : (par[i] = find(par[i]));
  }

  bool combine(int i, int j) {
    i = find(i); j = find(j);
    if (i != j) {
      if (sz[i] < sz[j]) swap(i, j);
      par[j] = i; sz[i] += sz[j];
    }
    return i != j;
  }
};

struct graph {
  vc<vi> adj;
  vc<map<int, ll>> w;

  graph(int n) : adj(n, vi()), w(n, map<int, ll>()) {}
  graph(const graph &g) : adj(g.adj), w(g.w) {}

  void cto(int from, int to, ll weight) {adj[from].pb(to); w[from][to] += weight;}
  void cto(int from, int to) {cto(from, to, 1);}
  void c(int from, int to) {cto(from, to); cto(to, from);}
  void c(int from, int to, ll weight) {cto(from, to, weight); cto(to, from, weight);}

  vi operator[](int u) {return adj[u];}
  vc<vi>::iterator begin() {return adj.begin();}
  vc<vi>::const_iterator begin() const {return adj.begin();}
  vc<vi>::iterator end() {return adj.end();}
  vc<vi>::const_iterator end() const {return adj.end();}
  int size() const {return adj.size();}
};

int main() {
  int n, m, q; cin >> n >> m >> q;
  graph g(n);
  map<pii, bool> good;
  for (int i = 0; i < m; ++i) {
    int u, v; cin >> u >> v;
    g.c(u, v);
    good[{u, v}] = good[{v, u}] = true;
  }
  vc<pair<int, pii>> qs;
  while (q--) {
    int t, u, v; cin >> t >> u >> v;
    qs.push_back({t, {u, v}});
    if (!t) {
      good[{u, v}] = good[{v, u}] = false;
    }
  }
  dsu d(n);
  for (const auto &e : good) {
    if (e.B) d.combine(e.A.A, e.A.B);
  }
  vc<string> ret;
  for (int i = qs.size() - 1; i >= 0; --i) {
    auto qry = qs[i];
    int t = qry.A, u = qry.B.A, v = qry.B.B;
    if (t) {
      if (d.find(u) == d.find(v)) {
        ret.push_back("safe");
      } else {
        ret.push_back("unsafe");
      }
    } else {
      d.combine(u, v);
    }
  }
  for (int i = ret.size() - 1; i >= 0; --i) {
    cout << ret[i] << endl;
  }
}
