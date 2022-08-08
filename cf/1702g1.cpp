#include <bits/stdc++.h>
#define A first
#define B second
#define vc vector
using namespace std;
using ll = long long;
using ld = long double;
using vi = vc<int>;
using vll = vc<ll>;
using pii = pair<int, int>;

template<class T> bool ckmin(T &a, const T &b) { return b < a ? a = b, 1 : 0; }
template<class T> bool ckmax(T &a, const T &b) { return a < b ? a = b, 1 : 0; }

void dfs(vc<vi> &g, vi &dep, vc<vi> &anc, int i = 0, int p = -1) {
  if (!~p) fill(anc[i].begin(), anc[i].end(), i);
  else {
    anc[i][0] = p;
    for (int k = 1; k < 20; ++k) {
      anc[i][k] = anc[anc[i][k - 1]][k - 1];
    }
  }
  for (int j : g[i]) {
    if (j == p) continue;
    dep[j] = dep[i] + 1;
    dfs(g, dep, anc, j, i);
  }
}

bool dfs3(vc<vi> &g, vc<bool> &vis, int i, int p) {
  int cnt = 0;
  for (int j : g[i]) {
    if (j == p) continue;
    if (vis[j]) {
      if (++cnt == 2) return false;
      if (!dfs3(g, vis, j, i)) return false;
    }
  }
  return true;
}

bool dfs2(vc<vi> &g, vc<bool> &vis, int i) {
  int cnt = 0;
  for (int j : g[i]) {
    if (vis[j]) {
      if (++cnt == 3) return false;
      if (!dfs3(g, vis, j, i)) return false;;
    }
  }
  return true;
}

int lca(vi &dep, vc<vi> &anc, int u, int v) {
  if (dep[u] > dep[v]) swap(u, v);
  for (int i = 19; i >= 0; --i) if (dep[anc[v][i]] >= dep[u]) v = anc[v][i];
  if (u == v) return u;
  for (int i = 19; i >= 0; --i) if (anc[u][i] != anc[v][i]) {
    u = anc[u][i]; v = anc[v][i];
  }
  return anc[u][0];
}

int main() {
  int n; cin >> n;
  vc<vi> g(n); for (int i = 1; i < n; ++i) {
    int u, v; cin >> u >> v; --u; --v;
    g[u].push_back(v);
    g[v].push_back(u);
  }
  vi dep(n);
  vc<vi> anc(n, vi(20));
  dfs(g, dep, anc);
  int q; cin >> q;
  while (q--) {
    int k; cin >> k;
    int end = -1, mxdep = -1;
    vi p(k); for (int i = 0; i < k; ++i) {
      cin >> p[i]; --p[i];
      if (ckmax(mxdep, dep[p[i]])) end = p[i];
    }
    int lc = -1, hi = n;
    bool good = true;
    for (int i = 0; i < k; ++i) {
      int clc = lca(dep, anc, end, p[i]);
      if (ckmin(hi, dep[clc])) lc = clc;
    }
    vc<bool> vis(n);
    vis[lc] = true;
    for (int i = 0; i < k; ++i) {
      int cur = p[i];
      while (!vis[cur]) {
        vis[cur] = true;
        cur = anc[cur][0];
      }
    }
    cout << (dfs2(g, vis, lc) ? "YES" : "NO") << endl;
  }
}