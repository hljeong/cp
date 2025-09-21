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

vll dijkstra(graph &g, int s) {
  int n = g.size(); vll d(n, infll);
  priority_queue<pair<ll, int>> q;
  d[s] = 0; q.push({0, s});
  while (q.size()) {
    auto p = q.top(); q.pop(); int u = p.B;
    if (p.A > d[u]) continue;
    for (int v : g[u]) if (ckmin(d[v], d[u] + g.w[u][v])) q.push({-d[v], v});
  }
  return d;
}

int main() {
  int n, m, f, s, t; cin >> n >> m >> f >> s >> t;
  graph roads(n), rroads(n), flights(n);
  for (int i = 0; i < m; ++i) {
    int u, v, c; cin >> u >> v >> c;
    roads.c(u, v, c);
    rroads.c(v, u, c);
  }
  vll ds = dijkstra(roads, s), dt = dijkstra(rroads, t);
  ll ans = ds[t];
  for (int i = 0; i < f; ++i) {
    int u, v; cin >> u >> v;
    ckmin(ans, ds[u] + dt[v]);
  }
  cout << ans << endl;
}
