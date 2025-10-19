#include "../misc/tmpl.cc"
#include "graph.cc"

namespace kosaraju {

void dfs(Graph &g, int u, vi &vis, vi &order) {
  vis[u] = 1;
  for (int v : g[u]) if (!vis[v])
    dfs(g, v, vis, order);
  order.pb(u);
}

void label(Graph &g, int u, vi &vis, vi &order, vi &lbl, int id) {
  vis[u] = 1;
  lbl[u] = id;
  for (int v : g[u]) if (!vis[v])
    label(g, v, vis, order, lbl, id);
  order.pb(u);
}

}

vec<vi> scc(Graph &g, vi &label) {
  size_t n = g.size();
  vi vis(n), order;
  for (int u = 0; u < n; u++) if (!vis[u])
    kosaraju::dfs(g, u, vis, order);
  reverse(order.begin(), order.end());

  vec<vi> comps;
  fill(vis.begin(), vis.end(), 0);
  Graph g_t = g.transpose();
  for (int u : order) if (!vis[u]) {
    int id = comps.size();
    comps.pb({});
    kosaraju::dfs(g_t, u, vis, comps.back());
    for (int v : comps.back()) label[v] = id;
  }

  return comps;
}

vec<vi> scc(Graph &g) {
  vi _(g.size());
  return scc(g, _);
}
