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

const int maxn = 35, maxm = 35, maxk = 55;

int dp[maxn][maxm][maxk];

int main() {
  for (int i = 1; i <= 30; ++i) {
    for (int j = 1; j <= 30; ++j) {
      for (int k = 1; k <= 50; ++k) {
        dp[i][j][k] = i * j == k ? 0 : 1e9 + 7;
        for (int i1 = 1; i1 < i; ++i1) {
          for (int k1 = 0; k1 <= k; ++k1) {
            ckmin(dp[i][j][k], dp[i1][j][k1] + dp[i - i1][j][k - k1] + j * j);
          }
        }
        for (int j1 = 1; j1 < j; ++j1) {
          for (int k1 = 0; k1 <= k; ++k1) {
            ckmin(dp[i][j][k], dp[i][j1][k1] + dp[i][j - j1][k - k1] + i * i);
          }
        }
      }
    }
  }
  int t;
  cin >> t;
  while (t--) {
    int n, m, k;
    cin >> n >> m >> k;
    cout << dp[n][m][k] << endl;
  }
}