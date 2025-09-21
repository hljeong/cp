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

// dp[i] = how many save from subtree if i infected

void solve(vc<vi> &g, vi &sz, vi &dp, int i = 0, int p = -1) {
  int s = 0;
  sz[i] = 1;
  for (int j : g[i]) {
    if (j == p) continue;
    solve(g, sz, dp, j, i);
    sz[i] += sz[j];
    s += dp[j];
  }
  for (int j : g[i]) {
    if (j == p) continue;
    ckmax(dp[i], s - dp[j] + sz[j] - 1);
  }
}

int main() {
  int t; cin >> t;
  while (t--) {
    int n; cin >> n;
    vc<vi> g(n); for (int i = 1; i < n; ++i) {
      int u, v; cin >> u >> v; --u; --v;
      g[u].push_back(v);
      g[v].push_back(u); 
    }
    vi sz(n), dp(n);
    solve(g, sz, dp);
    cout << dp[0] << endl;
  }
}