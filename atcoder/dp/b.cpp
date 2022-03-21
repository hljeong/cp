#include <bits/stdc++.h>
#define A first
#define B second
using namespace std;
using ll = long long;
using vi = vector<int>;

template<class T> bool ckmin(T& a, const T& b) { return b < a ? a = b, 1 : 0; }
template<class T> bool ckmax(T& a, const T& b) { return a < b ? a = b, 1 : 0; }

int main() {
  int n, k;
  cin >> n >> k;
  vi h(n + k + 1), dp(n + k + 1, 0x3f3f3f3f);
  for (int i = 0; i < n; ++i) cin >> h[i];
  dp[0] = 0;
  for (int i = 0; i < n - 1; ++i) for (int j = 1; j <= k; ++j) ckmin(dp[i + j], dp[i] + abs(h[i + j] - h[i]));
  cout << dp[n - 1] << endl;
}