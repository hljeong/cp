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

const int maxn = 305;

// state: #1s, #2s, #3s
// dp[i][j][k] = 1 + dp[i - 1][j][k] * (i / n) + dp[i + 1][j - 1][k] * (j / n)
//                 + dp[i][j + 1][k - 1] * (k / n) + dp[i][j][k] * ((i + j + k) / n)
//             = (n / s) + dp[i - 1][j][k] * (i / s) + dp[i + 1][j - 1][k] * (j / s)
//                 + dp[i][j + 1][k - 1] * (k / s)
ld dp[maxn][maxn][maxn];

int main() {
  int n, cnt1 = 0, cnt2 = 0, cnt3 = 0;
  cin >> n;
  for (int i = 0; i < n; ++i) {
    int a;
    cin >> a;
    if (a == 1) ++cnt1;
    else if (a == 2) ++cnt2;
    else ++cnt3;
  }
  for (int k = 0; k <= n; ++k) {
    for (int j = 0; j <= n; ++j) {
      if (j + k > n) break;
      for (int i = 0; i <= n; ++i) {
        int s = i + j + k;
        if (s > n) break;
        if(s) dp[i][j][k] = (ld) n / s;
        if (i) dp[i][j][k] += dp[i - 1][j][k] * i / s;
        if (j) dp[i][j][k] += dp[i + 1][j - 1][k] * j / s;
        if (k) dp[i][j][k] += dp[i][j + 1][k - 1] * k / s;
      }
    }
  }
  cout << setprecision(12) << dp[cnt1][cnt2][cnt3] << endl;
}