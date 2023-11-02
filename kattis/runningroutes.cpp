#include <bits/stdc++.h>

using namespace std;
#define vc vector
using vi = vc<int>;

void ckmax(int& a, int b) {
  a = max(a, b);
}

// cylic dp
// dp[i][j] = best within clockwise cyclic interval [i, j]
int main() {
  int n; cin >> n;
  vc<vi> adj(n, vi(n));
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      cin >> adj[i][j];
    }
  }
  vc<vi> dp(n, vi(n));
  int ret = 0;
  for (int i = 1; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      ckmax(dp[j][(j + i) % n], adj[j][(j + i) % n] + dp[(j + 1) % n][(j + i + n - 1) % n]);
      if (i > 1) {
        for (int k = j; k != (j + i) % n; k = (k + 1) % n) {
          ckmax(dp[j][(j + i) % n], dp[j][k] + dp[(k + 1) % n][(j + i) % n]);
        }
      }
      ckmax(ret, dp[j][(j + i) % n]);
    }
  }
  // for (int i = 0; i < n; ++i) for (int j = 0; j < n; ++j) cout << dp[i][j] << " \n"[j == n - 1];
  cout << ret << endl;
}
