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

int main() {
  int t; cin >> t;
  while (t--) {
    int n; cin >> n;
    vi a(n); for (int i = 0; i < n; ++i) cin >> a[i], --a[i];
    vc<vi> d(n, vi(n, 1));
    for (int i = 0; i < n; ++i) {
      vi f(n);
      int mx = 0;
      for (int j = i; j < n; ++j) {
        ckmax(mx, ++f[a[j]]);
        d[i][j] = (((j - i) & 1) && mx <= (j - i + 1) / 2) ? 1 : 0;
      }
    }
    vi dp(n);
    for (int i = 0; i < n; ++i) {
      dp[i] = i ? d[0][i - 1] : 1;
      for (int j = 0; j < i; ++j) {
        if (a[i] == a[j] && dp[j])
          ckmax(dp[i], d[j + 1][i - 1] * (dp[j] + 1));
      }
      // cout << i << ' ' << dp[i] << endl;
    }
    int ans = dp[n - 1];
    for (int i = 0; i < n - 1; ++i) {
      ckmax(ans, dp[i] * d[i + 1][n - 1]);
    }
    cout << ans << endl;
  }
}