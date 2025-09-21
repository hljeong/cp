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
  vc<si> adj;
  vc<map<int, ll>> w;

  graph(int n) : adj(n, si()), w(n, map<int, ll>()) {}
  graph(const graph &g) : adj(g.adj), w(g.w) {}

  void cto(int from, int to, ll weight) {adj[from].insert(to); w[from][to] += weight;}
  void cto(int from, int to) {cto(from, to, 1);}
  void c(int from, int to) {cto(from, to); cto(to, from);}
  void c(int from, int to, ll weight) {cto(from, to, weight); cto(to, from, weight);}

  si operator[](int u) {return adj[u];}
  vc<si>::iterator begin() {return adj.begin();}
  vc<si>::const_iterator begin() const {return adj.begin();}
  vc<si>::iterator end() {return adj.end();}
  vc<si>::const_iterator end() const {return adj.end();}
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
  int s, e, c; cin >> s >> e >> c;
  graph g(s);
  vi gbad(s);
  for (int i = 0; i < c; ++i) {
    int s1, s2; cin >> s1 >> s2;
    g.cto(s1, s2);
  }
  for (int i = 0; i < e; ++i) {
    int ene; cin >> ene;
    gbad[ene] = 1;
  }
  vi lbl = kosaraju_label(g);
  int ncomp = 0;
  for (int i : lbl) ckmax(ncomp, i + 1);
  graph comp(ncomp);
  vi cbad(ncomp), cnt(ncomp);
  for (int i = 0; i < s; ++i) {
    cbad[lbl[i]] += gbad[i];
    ++cnt[lbl[i]];
    for (int j : g[i]) {
      if (lbl[i] != lbl[j]) comp.cto(lbl[i], lbl[j]);
    }
  }
  vi sorted = kahn(comp), ckbad(cbad), contrib(ncomp);
  int ret = 0;
  for (int i = ncomp - 1; i >= 0; --i) {
    for (int j : comp[i]) {
      ckbad[i] += ckbad[j];
    }
    if (ckbad[i]) {
      ret += cnt[i] - cbad[i];
    } else {
      ++ret;
      ++contrib[i];
      for (int j : comp[i]) {
        if (contrib[j]) { // incremental public messaging
          --ret;
          --contrib[j];
        }
      }
    }
  }
  cout << ret << endl;
}
