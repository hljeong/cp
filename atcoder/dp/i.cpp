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

const int maxn = 3005;
ld p[maxn], dp[2][2 * maxn];

int main() {
  int n;
  cin >> n;
  for (int i = 0; i < n; ++i) {
    cin >> p[i];
  }
  dp[0][3000] = 1;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < 2 * maxn - 1; ++j) {
      dp[i & 1 ^ 1][j] = (1 - p[i]) * dp[i & 1][j + 1];
    }
    for (int j = 1; j < 2 * maxn; ++j) {
      dp[i & 1 ^ 1][j] += p[i] * dp[i & 1][j - 1];
    }
  }
  ld ans = 0;
  for (int i = 3001; i < 2 * maxn; ++i) {
    ans += dp[n & 1][i];
  }
  cout << setprecision(9) << ans << endl; 
}