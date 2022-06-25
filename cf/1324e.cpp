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
  int n, h, l, r, ans = 0;
  cin >> n >> h >> l >> r;
  vi a(n), p(n + 1);
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
    p[i + 1] = p[i] + a[i];
  }
  vc<vi> dp(n + 1, vi(n + 1, -n));
  dp[0][0] = 0;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j <= i + 1; ++j) {
      int nt = ((p[i + 1] - j) % h + h) % h, gain = l <= nt && nt <= r ? 1 : 0;
      ckmax(dp[i + 1][j], dp[i][j] + gain);
      if (j) ckmax(dp[i + 1][j], dp[i][j - 1] + gain);
      ckmax(ans, dp[i + 1][j]);
    }
  }
  cout << ans << endl;
}