#include <bits/stdc++.h>
#define A first
#define B second
#define vc vector
#define pb push_back
using namespace std;
using ll = long long; using ld = long double;
using vi = vc<int>; using vll = vc<ll>;
using si = set<int>; using sll = set<ll>;
using pii = pair<int, int>; using pll = pair<ll, ll>;
using mii = map<int, int>;

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

  void cto(int from, int to, ll weight) { adj[from].pb(to); w[from][to] += weight; }
  void cto(int from, int to) { cto(from, to, 1); }
  void c(int from, int to) { cto(from, to); cto(to, from); }
  void c(int from, int to, ll weight) { cto(from, to, weight); cto(to, from, weight); }

  vi operator[](int u) { return adj[u]; }
  vc<vi>::iterator begin() { return adj.begin(); }
  vc<vi>::const_iterator begin() const { return adj.begin(); }
  vc<vi>::iterator end() { return adj.end(); }
  vc<vi>::const_iterator end() const { return adj.end(); }
  int size() const { return adj.size(); }
};

int main() {
  int n, m; cin >> n >> m;
  graph g(n);
  for (int i = 0; i < m; ++i) {
    int u, v; cin >> u >> v; --u; --v;
    g.c(u, v);
  }
  vi a(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
    --a[i];
  }
  vi bread(n);
  int ret = 0;
  for (int t = 0; t < n; ++t) {
    deque<int> bfs; bfs.pb(a[0]);
    vi vis(n), grp(n, n);
    grp[0] = 0;
    for (int i = 0; i < n; ++i) {
      int u = a[i]; vis[u] = 1;
      while (bfs.size() && vis[bfs.front()]) bfs.pop_front();
      if (!bread[u] && bfs.size() && (bread[bfs.front()] || grp[u] > grp[bfs.front()])) ret += (bread[u] = 1);
      for (int v : g[u]) {
        if (vis[v]) continue;
        if (bread[v]) bfs.push_front(v);
        else {
          bfs.pb(v);
          grp[v] = i + 1;
        }
      }
    }
  }
  cout << ret << endl;
}
