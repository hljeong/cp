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

void dfs(graph &c, int u, vi &mx, vc<bool> &vis, vi &lbl, vc<vi> &scc, graph &g, vi &spot, mii &cnt, function<int(int, int)> &ind, function<pii(int)> &invind, function<bool(int, int)> &ib, vi &river) {
  for (int v : scc[u]) {
    if (!river[v]) continue;
    int i, j; tie(i, j) = invind(v);
    if (ib(i - 1, j) && spot[ind(i - 1, j)]) {
      if (!cnt[ind(i - 1, j)]++) ++mx[u];
    }
    if (ib(i, j - 1) && spot[ind(i, j - 1)]) {
      if (!cnt[ind(i, j - 1)]++) ++mx[u];
    }
    if (ib(i + 1, j) && spot[ind(i + 1, j)]) {
      if (!cnt[ind(i + 1, j)]++) ++mx[u];
    }
    if (ib(i, j + 1) && spot[ind(i, j + 1)]) {
      if (!cnt[ind(i, j + 1)]++) ++mx[u];
    }
  }
  vis[u] = true;
  for (int v : c[u]) {
    // cout << u << " -> " << v << endl;
    mx[v] += mx[u];
    dfs(c, v, mx, vis, lbl, scc, g, spot, cnt, ind, invind, ib, river);
  }
  for (int v : scc[u]) {
    if (!river[v]) continue;
    int i, j; tie(i, j) = invind(v);
    if (ib(i - 1, j) && spot[ind(i - 1, j)]) --cnt[ind(i - 1, j)];
    if (ib(i, j - 1) && spot[ind(i, j - 1)]) --cnt[ind(i, j - 1)];
    if (ib(i + 1, j) && spot[ind(i + 1, j)]) --cnt[ind(i + 1, j)];
    if (ib(i, j + 1) && spot[ind(i, j + 1)]) --cnt[ind(i, j + 1)];
  }
}

vi indegree(graph &g) {
  int n = g.size(); vi indeg(n);
  for (int i = 0; i < n; ++i) for (int j : g[i]) ++indeg[j];
  return indeg;
}

vi kahn(graph &g, vi &indeg) {
  int n = g.size(); vi sorted; queue<int> q;
  for (int i = 0; i < n; ++i) if (!indeg[i]) q.push(i);
  while (q.size()) {
    int i = q.front(); q.pop();
    sorted.pb(i);
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
  int r, c; cin >> r >> c;
  vc<string> mp(r);
  graph g(r * c);
  vi spot(r * c), river(r * c);
  function<int(int, int)> ind = [&](int i, int j) {return i * c + j;};
  function<pii(int)> invind = [&](int k) {return make_pair(k / c, k % c);};
  function<bool(int, int)> ib = [&](int i, int j) {return 0 <= i && i < r && 0 <= j && j < c;};
  for (int i = 0; i < r; ++i) {
    cin >> mp[i];
    for (int j = 0; j < c; ++j) {
      if (mp[i][j] == '#') spot[ind(i, j)] = 1;
      else if (mp[i][j] == '^') {
        if (i) g.cto(ind(i, j), ind(i - 1, j));
        river[ind(i, j)] = 1;
      }
      else if (mp[i][j] == '>') {
        if (j < c - 1) g.cto(ind(i, j), ind(i, j + 1));
        river[ind(i, j)] = 1;
      }
      else if (mp[i][j] == 'v') {
        if (i < r - 1) g.cto(ind(i, j), ind(i + 1, j));
        river[ind(i, j)] = 1;
      }
      else if (mp[i][j] == '<') {
        if (j) g.cto(ind(i, j), ind(i, j - 1));
        river[ind(i, j)] = 1;
      }
    }
  }
  vc<vi> scc = kosaraju(g);
  int nc = scc.size();
  vi lbl(r * c);
  for (int i = 0; i < nc; ++i) for (int j : scc[i]) lbl[j] = i;
  graph cmp(nc);
  for (int i = 0; i < r * c; ++i) {
    for (int j : g[i]) {
      int u = lbl[i], v = lbl[j];
      if (u != v && !cmp.w[v][u]) cmp.cto(v, u);
    }
  }
  vi ord = kahn(cmp);
  vi mx(nc);
  int ret = 0;
  vc<bool> vis(nc);
  mii cnt;
  for (int id = 0; id < nc; ++id) {
    int i = ord[id];
    if (!vis[i]) dfs(cmp, i, mx, vis, lbl, scc, g, spot, cnt, ind, invind, ib, river);
    ckmax(ret, mx[i]);
  }
  for (int i = 0; i < nc; ++i) {
    int x, y; tie(x, y) = invind(scc[i][0]);
    // cout << x << ", " << y << ": " << mx[i] << endl;
  }
  cout << ret << endl;
}
