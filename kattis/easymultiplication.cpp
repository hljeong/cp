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

int main() {
  int n; cin >> n;
  while (n --> 0) {
    int m; cin >> m;
    if (m == 1) {
      cout << 0 << endl;
      continue;
    }
    graph g(m);
    for (int i = 0; i < m; ++i) {
      g.cto(i, (i << 1) % m, 0);
      g.cto(i, (i << 1 | 1) % m, 1);
    }
    vll d(m, infll);
    priority_queue<pair<ll, int>> q;
    d[1] = 0; q.push({0, 1});
    while (q.size()) {
      auto p = q.top(); q.pop(); int u = p.B;
      if (-p.A > d[u]) continue;
      for (int v : g[u]) {
        if (ckmin(d[v], d[u] + g.w[u][v])) {
          q.push({-d[v], v});
        }
      }
    }
    queue<int> bfs;
    vi bd(m, inf), p(m, -1);
    bd[1] = 0;
    bfs.push(1);
    while (bfs.size()) {
      int u = bfs.front(); bfs.pop();
      int v = (u << 1) % m;
      if (d[v] == d[u] + g.w[u][v] && ckmin(bd[v], bd[u] + 1)) {
        bfs.push(v);
        p[v] = u;
      }
      v = (u << 1 | 1) % m;
      if (d[v] == d[u] + g.w[u][v] && ckmin(bd[v], bd[u] + 1)) {
        bfs.push(v);
        p[v] = u;
      }
    }
    int cur = 0, ind = 0;
    vi ret;
    while (p[cur] != -1) {
      if (g.w[p[cur]][cur] == 1) ret.pb(ind);
      cur = p[cur];
      ++ind;
    }
    ret.pb(ind);
    for (int i = 0; i < ret.size(); ++i) cout << ret[i] << " \n"[i == ret.size() - 1];
  }
}
