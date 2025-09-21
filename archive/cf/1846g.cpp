#include <bits/stdc++.h>
#define A first
#define B second
#define vc vector
#define pb push_back
#define endl '\n'
using namespace std;
using ll = long long; using ld = long double;
using vi = vc<int>; using vll = vc<ll>;
using si = set<int>; using sll = set<ll>;
using pi = pair<int, int>; using pll = pair<ll, ll>;
using qi = queue<int>; using mi = map<int, int>;

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
  graph(int n, int m, int off = 1) : adj(n, vi()), w(n, map<int, ll>()) {
    for (int i = 0, u, v; i < m; ++i) {
      cin >> u >> v; u -= off; v -= off;
      c(u, v);
    }
  }

  void cto(int from, int to, ll weight) { adj[from].pb(to); if (w[from][to]) ckmin(w[from][to], weight); else w[from][to] = weight; }
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

vll sp(graph &g, int s) {
  int n = g.size(); vll d(n, infll);
  priority_queue<pair<ll, int>> q;
  d[s] = 0; q.push({0, s});
  while (q.size()) {
    auto p = q.top(); q.pop(); int u = p.B;
    if (-p.A > d[u]) continue;
    for (int v : g[u]) if (ckmin(d[v], d[u] + g.w[u][v])) q.push({-d[v], v});
  }
  return d;
}

int main() {
  cin.tie(0) -> sync_with_stdio(0);

  int t; cin >> t;
  while (t--) {
    int n, m; cin >> n >> m;
    string sr; cin >> sr;
    int s = stoi(sr, 0, 2);
    graph g(1 << n);
    for (int i = 0; i < m; ++i) {
      int w; cin >> w;
      string remr, addr;
      cin >> remr >> addr;
      int rem = stoi(remr, 0, 2);
      int add = stoi(addr, 0, 2);
      for (int j = 0; j < (1 << n); ++j) {
        g.cto(j, (j & (~rem)) | add, w);
      }
    }
    vll d = sp(g, s);
    if (d[0] > infll / 2) cout << -1 << endl;
    else cout << d[0] << endl;
  }
}
