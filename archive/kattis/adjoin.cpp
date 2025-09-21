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

pii dfs(graph &g, int i, int p, vc<bool> &vis, int d = 0) {
  vis[i] = true;
  pii ret = {d, i};
  for (int j : g[i]) {
    if (j == p) continue;
    ckmax(ret, dfs(g, j, i, vis, d + 1));
  }
  return ret;
}

int diam(graph &g, int i, vc<bool> &vis) {
  int j = dfs(g, i, -1, vis).B;
  return dfs(g, j, -1, vis).A;
}

int main() {
  int c, l; cin >> c >> l;
  graph g(c);
  for (int i = 0; i < l; ++i) {
    int u, v; cin >> u >> v;
    g.c(u, v);
  }
  vi dia;
  vc<bool> vis(c);
  for (int i = 0; i < c; ++i) {
    if (!vis[i]) dia.pb(diam(g, i, vis));
  }
  sort(dia.rbegin(), dia.rend());
  if (dia.size() == 1) {
    cout << dia[0] << endl;
  } else if (dia.size() == 2) {
    cout << max(dia[0], (dia[0] + 1) / 2 + 1 + (dia[1] + 1) / 2) << endl;
  } else {
    cout << max(dia[0], max((dia[0] + 1) / 2 + 1 + (dia[1] + 1) / 2, (dia[1] + 1) / 2 + 2 + (dia[2] + 1) / 2)) << endl;
  }
}
