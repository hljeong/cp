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
using gr = vc<vi>;

template<class T> bool ckmin(T &a, const T &b) { return b < a ? a = b, 1 : 0; }
template<class T> bool ckmax(T &a, const T &b) { return a < b ? a = b, 1 : 0; }

const int inf = 1e9 + 7;
const int mod = inf;
const ll infll = 0x3f3f3f3f3f3f3f3fll;

struct fsgraph {
  int eid = 2, last_u;
  vi head, nxt, v;
  vll w;

  fsgraph(int n) : head(n), nxt(2), v(2), w(2) {}

  void cto(int from, int to, ll weight) {
    nxt.pb(head[from]); v.pb(to); w.pb(weight);
    head[last_u = from] = eid++;
  }
  
  void cto(int from, int to) {cto(from, to, infll);}
  void rev() {cto(v[eid - 1], last_u, 0);}

  int operator[](int u) {return head[u];}
  vi::iterator begin() {return head.begin();}
  vi::const_iterator begin() const {return head.begin();}
  vi::iterator end() {return head.end();}
  vi::const_iterator end() const {return head.end();}
  int size() const {return head.size();}
};

bool bfs(fsgraph &g, int s, int t, vi &cur, vi &lvl) {
  fill(lvl.begin(), lvl.end(), -1); lvl[s] = 0;
  for (int i = 0; i < g.size(); ++i) cur[i] = g[i];
  queue<int> q; q.push(s);
  while (q.size()) {
    int u = q.front(); q.pop();
    for (int e = g[u]; e; e = g.nxt[e]) {
      int v = g.v[e]; ll w = g.w[e];
      if (w && !~lvl[v]) {
        lvl[v] = lvl[u] + 1;
        q.push(v);
      }
    }
  }
  return ~lvl[t];
}

ll dfs(fsgraph &g, int u, int t, ll f, vi &cur, vi &lvl) {
  if (u == t) return f;
  ll r = f;
  for (int e = cur[u]; e && r; e = g.nxt[e]) {
    cur[u] = e;
    int v = g.v[e]; ll w = g.w[e];
    if (w && lvl[v] == lvl[u] + 1) {
      ll c = dfs(g, v, t, min(w, r), cur, lvl);
      r -= c; g.w[e] -= c; g.w[e ^ 1] += c;
    }
  }
  return f - r;
}

ll dinic(fsgraph &g, int s, int t) {
  ll ans = 0;
  vi lvl(g.size()), cur(g.size());
  while (bfs(g, s, t, cur, lvl)) ans += dfs(g, s, t, infll, cur, lvl);
  return ans;
}

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

vc<vll> fw(graph &g) {
  int n = g.size();
  vc<vll> d(n, vll(n, infll));
  for (int i = 0; i < n; ++i) {
    d[i][i] = 0;
    for (int j : g[i])
      d[i][j] = g.w[i][j];
  }
  for (int k = 0; k < n; ++k) 
    for (int i = 0; i < n; ++i)
      for (int j = 0; j < n; ++j)
        ckmin(d[i][j], d[i][k] + d[k][j]);
  return d;
}

int main() {
  int n, m, k; cin >> n >> m >> k;
  graph g(n);
  for (int i = 0; i < m; ++i) {
    int u, v, w; cin >> u >> v >> w; --u; --v;
    g.cto(u, v, w);
  }
  vc<vll> d = fw(g);
  vc<array<int, 3>> t(k);
  for (int i = 0; i < k; ++i) {
    cin >> t[i][0] >> t[i][1] >> t[i][2]; --t[i][0]; --t[i][1];
  }
  fsgraph fg(1 + k + k + 1);
  for (int i = 0; i < k; ++i) {
    fg.cto(0, 1 + i, 1); fg.rev();
    fg.cto(1 + k + i, 1 + k + k, 1); fg.rev();
  }
  for (int i = 0; i < k; ++i) {
    for (int j = 0; j < k; ++j) {
      if (i == j) continue;
      if (t[j][2] >= t[i][2] + d[t[i][0]][t[i][1]] + d[t[i][1]][t[j][0]]) {
        fg.cto(1 + i, 1 + k + j, 1); fg.rev();
      }
    }
  }
  cout << k - dinic(fg, 0, 1 + k + k) << endl;
}
