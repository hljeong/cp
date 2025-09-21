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

  void cto(int from, int to, ll weight) {
    adj[from].pb(to);
    if (!w[from].count(to)) w[from][to] = weight;
    else ckmin(w[from][to], weight);
  }
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
  int n, k, m; cin >> n >> k >> m;
  graph g(n);
  for (int i = 0; i < m; ++i) {
    int u, v, w; cin >> u >> v >> w; --u; --v;
    g.cto(v, u, w);
  }
  // seg left, seg right, left/right endpoint, steps
  vc<vc<vc<vll>>> dp(n, vc<vc<vll>>(n, vc<vll>(2, vll(k + 1, inf))));
  for (int i = 0; i < n; ++i) {
    for (int j = i; j < n; ++j) {
      dp[i][j][0][1] = dp[i][j][1][1] = 0;
    }
  }
  for (int kk = 1; kk < k; ++kk) {
    for (int i = 0; i < n; ++i) {
      for (int j = i; j < n; ++j) {
        for (int v : g[i]) {
          if (v > j) {
            ckmin(dp[i][v][1][kk + 1], dp[i][j][0][kk] + g.w[i][v]);
          } else if (v < i) {
            ckmin(dp[v][j][0][kk + 1], dp[i][j][0][kk] + g.w[i][v]);
          }
        }
        for (int v : g[j]) {
          if (v > j) {
            ckmin(dp[i][v][1][kk + 1], dp[i][j][1][kk] + g.w[j][v]);
          } else if (v < i) {
            ckmin(dp[v][j][0][kk + 1], dp[i][j][1][kk] + g.w[j][v]);
          }
        }
      }
    }
  }
  ll ret = inf;
  for (int i = 0; i < n; ++i) {
    for (int j = i; j < n; ++j) {
      ckmin(ret, dp[i][j][0][k]);
      ckmin(ret, dp[i][j][1][k]);
    }
  }
  if (ret == inf) cout << -1 << endl;
  else cout << ret << endl;
}
