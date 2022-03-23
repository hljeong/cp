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

const int maxn = 405;
const ll inf = 1e18;
ll a[maxn], s[maxn], dp[maxn][maxn];

int main() {
  int n;
  cin >> n;
  for (int i = 0; i < maxn; ++i) for (int j = 0; j < maxn; ++j) dp[i][j] = inf;
  for (int i = 0; i < n; ++i) cin >> a[i], s[i + 1] = s[i] + a[i], dp[i][i] = 0;
  for (int l = 1; l < n; ++l) {
    for (int i = 0; i < n - l; ++i) {
      for (int j = i; j < i + l; ++j) {
        ckmin(dp[i][i + l], dp[i][j] + dp[j + 1][i + l] + s[i + l + 1] - s[i]);
      }
    }
  }
  cout << dp[0][n - 1] << endl;
}