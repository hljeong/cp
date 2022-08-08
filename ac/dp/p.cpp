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

template<class T> bool ckmin(T& a, const T& b) { return b < a ? a = b, 1 : 0; }
template<class T> bool ckmax(T& a, const T& b) { return a < b ? a = b, 1 : 0; }

const int mod = 1e9 + 7; 

void dfs(vc<vi> &g, vc<pair<ll, ll>> &dp, int i = 0, int p = -1) {
  dp[i].A = dp[i].B = 1;
  for (int j : g[i]) {
    if (j == p) continue;
    dfs(g, dp, j, i);
    dp[i].A *= (dp[j].A + dp[j].B) % mod;
    dp[i].A %= mod;
    dp[i].B *= dp[j].A;
    dp[i].B %= mod;
  }
}

int main() {
  int n; cin >> n;
  vc<vi> g(n);
  for (int i = 1; i < n; ++i) {
    int u, v; cin >> u >> v; --u; --v;
    g[u].push_back(v);
    g[v].push_back(u);
  }
  vc<pair<ll, ll>> dp(n);
  dfs(g, dp);
  cout << (dp[0].A + dp[0].B) % mod << endl;
}