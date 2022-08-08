#include <bits/stdc++.h>
#define A first
#define B second
using namespace std;
using ll = long long;
using vi = vector<int>;

const int maxn = 1e4 + 5, maxw = 105, maxh = 105, mod = 1e9 + 7;
int dp[maxw][maxn];

int main() {
  int n, w, h;
  cin >> n >> w >> h;
  if (n > w * h) n = w * h;
  dp[0][0] = 1;
  for (int i = 0; i < w; ++i) {
    for (int j = 0; j <= h; ++j) {
      for (int k = 0; k <= n - j; ++k) {
        dp[i + 1][k + j] += dp[i][k];
        if (dp[i + 1][k + j] >= mod) dp[i + 1][k + j] -= mod;
      }
    }
  }
  int ans = 0;
  for (int i = 0; i <= n; ++i) {
    ans += dp[w][i];
    if (ans >= mod) ans -= mod;
  }
  cout << (ans - n / w - 1 + mod) % mod << endl;
}