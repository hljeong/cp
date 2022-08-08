#include <bits/stdc++.h>
#define A first
#define B second
using namespace std;
using ll = long long;
using ld = long double;
using vi = vector<int>;

int main() {
  int k, n;
  scanf("%d %d", &k, &n);
  ++k;
  vi s(n + 1), p(n + 1), sz(n + 1);
  vector<vi> g(n + 1, vi());
  for (int i = 1; i <= n; ++i) {
    int r;
    scanf("%d %d %d", &s[i], &p[i], &r);
    g[r].push_back(i);
  }
  for (int i = n; i >= 0; --i) {
    sz[i] = 1;
    for (int j : g[i]) sz[i] += sz[j];
  }
  auto check = [&](ld r) {
    vector<vector<ld>> dp(n + 1);
    for (int i = n; i >= 0; --i) {
      int nsz = min(k, sz[i]);
      dp[i].resize(nsz + 1);
      fill(dp[i].begin(), dp[i].end(), -1e18);
      dp[i][1] = p[i] - r * s[i];
      for (int j : g[i]) for (int knd = dp[j].size(); ~knd; --knd) for (int l = nsz; l >= knd; --l) dp[i][l] = max(dp[i][l], dp[i][l - knd] + dp[j][knd]);
    }
    return dp[0][k] >= 0;
  };
  ld ans = 0.001;
  for (ld l = 0.001, r = 10000; r - l >= 0.0005; ) {
    double m = l + (r - l) / 2;
    if (check(m)) {
      ans = m;
      l = m;
    } else r = m;
  }
  printf("%Lf", ans);
}