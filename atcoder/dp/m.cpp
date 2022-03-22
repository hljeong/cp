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

const int maxn = 105, maxk = 1e5 + 5, mod = 1e9 + 7;
ll a[maxn], dp[2][2 * maxk], pdp[2][2 * maxk];

int main() {
  int n, k;
  cin >> n >> k;
  for (int i = 0; i < n; ++i) cin >> a[i];
  dp[0][k] = 1;
  for (int j = 0; j < 2 * maxk; ++j) {
    pdp[0][j + 1] = dp[0][j] + pdp[0][j];
  }
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j <= k; ++j) {
      dp[i & 1 ^ 1][j] = pdp[i & 1][j + a[i] + 1] - pdp[i & 1][j] + mod;
      if (dp[i & 1 ^ 1][j] >= mod) dp[i & 1 ^ 1][j] -= mod;
    }
    // important: 2 * maxk instead of <= k
    for (int j = 0; j < 2 * maxk; ++j) {
      pdp[i & 1 ^ 1][j + 1] = dp[i & 1 ^ 1][j] + pdp[i & 1 ^ 1][j];
      if (pdp[i & 1 ^ 1][j + 1] >= mod) pdp[i & 1 ^ 1][j + 1] -= mod;
    }
  }
  cout << dp[n & 1][0] << endl;
}