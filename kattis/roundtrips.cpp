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

void kosaraju_dfs(graph &g, int i, vc<bool> &vis, vi &ordered) {
  vis[i] = true;
  for (int j : g[i])
    if (!vis[j])
      kosaraju_dfs(g, j, vis, ordered);
  ordered.pb(i);
}

vc<vi> kosaraju(graph &g) {
  int n = g.size();
  vi ordered;
  vc<bool> vis(n);
  for (int i = 0; i < n; ++i)
    if (!vis[i])
      kosaraju_dfs(g, i, vis, ordered);
  graph transpose(n);
  for (int i = 0; i < n; ++i)
    for (int j : g[i])
      transpose.cto(j, i);
  reverse(ordered.begin(), ordered.end());
  vc<vi> scc;
  fill(vis.begin(), vis.end(), false);
  for (int i : ordered) {
    if (vis[i]) continue;
    vi comp;
    kosaraju_dfs(transpose, i, vis, comp);
    scc.pb(comp);
  }
  return scc;
}

void kosaraju_dfs_label(graph &g, int i, vc<bool> &vis, vi &label, int id) {
  vis[i] = true;
  label[i] = id;
  for (int j : g[i])
    if (!vis[j])
      kosaraju_dfs_label(g, j, vis, label, id);
}

vi kosaraju_label(graph &g) {
  int n = g.size();
  vi ordered;
  vc<bool> vis(n);
  for (int i = 0; i < n; ++i)
    if (!vis[i])
      kosaraju_dfs(g, i, vis, ordered);
  graph transpose(n);
  for (int i = 0; i < n; ++i)
    for (int j : g[i])
      transpose.cto(j, i);
  reverse(ordered.begin(), ordered.end());
  vi scc(n);
  int cur = 0;
  fill(vis.begin(), vis.end(), false);
  for (int i : ordered)
    if (!vis[i])
      kosaraju_dfs_label(transpose, i, vis, scc, cur++);
  return scc;
}

vi indegree(graph &g) {
  int n = g.size(); vi indeg(n);
  for (vi &adj : g) for (int i : adj) ++indeg[i];
  return indeg;
}

vi kahn(graph &g, vi &indeg) {
  int n = g.size(); vi sorted; queue<int> q;
  for (int i = 0; i < n; ++i) if (!indeg[i]) q.push(i);
  while (q.size()) {
    int i = q.front(); q.pop();
    sorted.push_back(i);
    for (int j : g[i]) if (!--indeg[j]) q.push(j);
  }
  return sorted;
}

vi kahn(graph &g) {
  vi indeg = indegree(g);
  return kahn(g, indeg);
}

bool kahn_check(graph &g) {
  int n = g.size(); vi indeg = indegree(g);
  kahn(g, indeg);
  for (int i = 0; i < n; ++i) if (indeg[i]) return false;
  return true;
}

int main() {
  int n, m; cin >> n >> m;
  graph g(n);
  for (int i = 0; i < m; ++i) {
    int u, v; cin >> u >> v;
    g.cto(u, v);
  }
  auto scc = kosaraju(g);
  int nc = scc.size();
  vi lbl(n), sz(nc);
  for (int i = 0; i < nc; ++i) {
    for (int j : scc[i]) {
      lbl[j] = i;
      ++sz[i];
    }
  }
  graph gc(nc);
  ll ret = 0;
  for (int i = 0; i < n; ++i) {
    for (int j : g[i]) {
      int u = lbl[i], v = lbl[j];
      if (u != v && !gc.w[u][v]) gc.cto(u, v);
      if (u != v) --ret;
    }
  }
  auto ord = kahn(gc);
  ll cur = n;
  for (int i : ord) {
    ret += sz[i] * (cur -= sz[i]);
  }
  cout << ret << endl;
}
