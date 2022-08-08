#include <bits/stdc++.h>
#define A first
#define B second
#define vc vector
using namespace std;
using ll = long long;
using vi = vector<int>;

template<class T> bool ckmin(T& a, const T& b) { return b < a ? a = b, 1 : 0; }
template<class T> bool ckmax(T& a, const T& b) { return a < b ? a = b, 1 : 0; }

int main() {
  int n;
  cin >> n;
  vi a(n), b(n), c(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i] >> b[i] >> c[i];
  }
  vc<vi> dp(n + 1, vi(3));
  for (int i = 0; i < n; ++i) {
    ckmax(dp[i + 1][0], max(dp[i][1], dp[i][2]) + a[i]);
    ckmax(dp[i + 1][1], max(dp[i][0], dp[i][2]) + b[i]);
    ckmax(dp[i + 1][2], max(dp[i][0], dp[i][1]) + c[i]);
  }
  cout << max({dp[n][0], dp[n][1], dp[n][2]});
}