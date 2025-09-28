#include "../misc/tmpl.cc"

struct dsu {
  vi p, sz;
  dsu(int n) : p(n), sz(n, 1) { for (int i = 0; i < n; i++) p[i] = i; }
  int find(int u) { return (u == p[u]) ? u : (p[u] = find(p[u])); }
  bool combine(int u, int v) {
    if ((u = find(u)) == (v = find(v))) return false;
    if (sz[u] < sz[v]) swap(u, v);
    p[v] = u; sz[u] += sz[v];
    return true;
  }
};
