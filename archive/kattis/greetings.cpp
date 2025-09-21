#include <bits/stdc++.h>
#define A first
#define B second
using namespace std;
using ll = long long;
using vi = vector<int>;

const int maxn = 15, maxm = 1 << maxn;
ll dp[maxn + 1][maxm], wst[maxm], w[maxn], h[maxn], q[maxn];

int main() {
  int n, k;
  cin >> n >> k;
  for (int i = 0; i < n; ++i) cin >> w[i] >> h[i] >> q[i];
  for (int m = 0; m < 1 << n; ++m) {
    ll maxh = 0, maxw = 0, sumq = 0;
    for (int i = 0; i < n; ++i) if ((m >> i) & 1) {
      if (h[i] > maxh) maxh = h[i];
      if (w[i] > maxw) maxw = w[i];
      sumq += q[i];
      wst[m] -= q[i] * h[i] * w[i];
    }
    wst[m] += sumq * maxh * maxw;
  }
  memset(dp, 0x3f, sizeof(dp));
  dp[0][0] = 0;
  for (int i = 0; i < k; ++i) {
    for (int m = 0; m < 1 << n; ++m) {
      int im = (1 << n) - 1 - m;
      for (int sm = im; sm; sm = (sm - 1) & im) {
        if (dp[i + 1][m | sm] > dp[i][m] + wst[sm]) dp[i + 1][m | sm] = dp[i][m] + wst[sm];
      }
      if (dp[i + 1][m] > dp[i][m]) dp[i + 1][m] = dp[i][m];
    }
  }
  // cout << "ans ";
  cout << dp[k][(1 << n) - 1] << endl;
}
