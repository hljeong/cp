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

int main() {
  int n; cin >> n;
  vi p(3 * n), ps(3 * n + 1); for (int i = 0; i < 3 * n; ++i) {
    cin >> p[i];
    ps[i + 1] = ps[i] + p[i];
  }
  vc<vc<vc<ld>>> dp(n + 1, vc<vc<ld>>(n + 1, vc<ld>(n + 1)));
  for (int i = 0; i <= n; ++i) {
    for (int j = 0; j <= n - i; ++j) {
      for (int k = 0; k <= n - i - j; ++k) {
        int l = n - i - j - k;
        int x = j + 2 * k + 3 * l;
        if (i) dp[i][j][k] += (ld) i / n * (p[x] + dp[i - 1][j + 1][k]);
        if (j) dp[i][j][k] += (ld) j / n * (p[x] + dp[i][j - 1][k + 1]);
        if (k) dp[i][j][k] += (ld) k / n * (p[x] + dp[i][j][k - 1]);
        dp[i][j][k] -= (ld) l / n * ps[x];
        ckmax(dp[i][j][k], 0.0l);
      }
    }
  }
  cout << dp[n][0][0] << endl;
}
