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

ld eps = 1e-6;
using a3 = array<int, 3>;

// binary search on ans and check if sum(p - ans * s) >= 0 w dp
int main() {
  cin.tie(0) -> sync_with_stdio(0);

  int k, n; cin >> k >> n;
  graph g(n + 1);
  vc<a3> e(n + 1);
  for (int i = 1; i <= n; ++i) {
    cin >> e[i][0] >> e[i][1] >> e[i][2];
    g.c(e[i][2], i);
  }
  vi sz(n + 1);
  function<void(int, int)> solve_sz = [&](int i, int p) {
    sz[i] = 1;
    for (int j : g[i]) {
      if (j == p) continue;
      solve_sz(j, i);
      sz[i] += sz[j];
    }
  };
  solve_sz(0, 0);
  ld ret = 0;
  for (ld l = 0, r = 50000000; r - l > eps; ) {
    ld m = l + (r - l) / 2;
    vc<vc<ld>> dp(n + 1);
    function<void(int, int)> dfs = [&](int i, int p) {
      dp[i] = vc<ld>(sz[i] + 1, -infll);
      int cur_sz = 1;
      dp[i][1] = e[i][1] - e[i][0] * m;
      for (int j : g[i]) {
        if (j == p) continue;
        dfs(j, i);
        for (int k = cur_sz; k > 0; --k) {
          for (int l = 1; l <= sz[j]; ++l) {
            ckmax(dp[i][k + l], dp[i][k] + dp[j][l]);
          }
        }
        cur_sz += sz[j];
      }
      return sz;
    };
    dfs(0, 0);
    if (dp[0][k + 1] >= 0) l = ret = m;
    else r = m;
  }

  cout << fixed << setprecision(3) << ret << endl;
}
