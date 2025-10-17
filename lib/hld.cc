#include "../misc/tmpl.cc"
#include "graph.cc"
#include "sgt.cc"

template <lazy Ops>
struct HeavyLightDecomposition {
  using T = Ops::T;
  using U = Ops::U;

  int n, p = 0;
  vi par, dep, sz, head, pos, end, heavy;
  SegmentTree<Ops> t;

  HeavyLightDecomposition(const Graph &g, const vec<T> &a, int r = 0)
    : n(g.size()), par(n), dep(n), sz(n), head(n), pos(n), end(n), heavy(n, -1) {
    assert(a.size() == n);
    par[r] = r;
    dfs(g, r);
    decompose(g, r, r);

    vector<T> ap(n);
    for (int i = 0; i < n; i++) ap[pos[i]] = a[i];
    t = SegmentTree<Ops>(ap);
  }

  HeavyLightDecomposition(const Graph &g, int r = 0)
    : HeavyLightDecomposition(g, vec<T>(g.size(), Ops::identity()), r) {}

  void update(int u, const U &upd) { t.update(pos[u], upd); }

  void update(int u, int v, const U &upd) {
    while (head[u] != head[v]) {
      if (dep[head[u]] > dep[head[v]]) swap(u, v);
      t.update(pos[head[v]], pos[v], upd);
      v = par[head[v]];
    }
    if (dep[u] > dep[v]) swap(u, v);
    t.update(pos[u], pos[v], upd);
  }

  void update_subtree(int u, const U &upd) { t.update(pos[u], end[u] - 1, upd); }

  T query(int u) { return t.query(pos[u]); }

  T query(int u, int v) {
    T ret = Ops::identity();
    while (head[u] != head[v]) {
      if (dep[head[u]] > dep[head[v]]) swap(u, v);
      ret = Ops::merge(t.query(pos[head[v]], pos[v]), ret);
      v = par[head[v]];
    }
    if (dep[u] > dep[v]) swap(u, v);
    return Ops::merge(t.query(pos[u], pos[v]), ret);
  }

  T query_subtree(int u) { return t.query(pos[u], end[u] - 1); }

  void dfs(const Graph &g, int u) {
    sz[u] = 1;
    int mx = 0;
    for (int v : g[u]) {
      if (v == par[u]) continue;
      par[v] = u;
      dep[v] = dep[u] + 1;
      dfs(g, v);
      sz[u] += sz[v];
      if (ckmax(mx, sz[v])) heavy[u] = v;
    }
  }

  void decompose(const Graph &g, int u, int h) {
    head[u] = h;
    pos[u] = p++;
    if (~heavy[u]) decompose(g, heavy[u], h);
    for (int v : g[u]) {
      if (v == par[u] || v == heavy[u]) continue;
      decompose(g, v, v);
    }
    end[u] = p;
  }
};
