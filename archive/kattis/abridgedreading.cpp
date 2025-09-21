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
template<class T> bool ckmax(T &a, const T &b) { return b > a ? a = b, 1 : 0; }

const int inf = 1e9 + 7;
const int mod = inf;
const ll infll = 0x3f3f3f3f3f3f3f3fll;

void solve(vc<vi> &g, int i, vi &p, vc<pii> &dp) {
  if (!g[i].size()) {
    dp[i].A = p[i];
    return;
  }
  for (int j : g[i]) {
    solve(g, j, p, dp);
    ckmin(dp[i].B, dp[i].A + dp[j].A);
    ckmin(dp[i].A, p[i] + dp[j].A);
    ckmin(dp[i].B, p[i] + dp[j].B);
  }
}

int main() {
  int n, m; cin >> n >> m;
  vi p(n + 1); for (int i = 1; i <= n; ++i) cin >> p[i];
  vc<vi> g(n + 1);
  vi indeg(n + 1);
  for (int i = 0; i < m; ++i) {
    int u, v; cin >> u >> v;
    g[u].pb(v);
    ++indeg[v];
  }
  for (int i = 1; i <= n; ++i) if (!indeg[i]) g[0].pb(i);
  vc<pii> dp(n + 1, {inf, inf});
  solve(g, 0, p, dp);
  cout << dp[0].B << endl;
}