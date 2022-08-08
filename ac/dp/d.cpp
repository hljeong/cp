#include <bits/stdc++.h>
#define A first
#define B second
using namespace std;
using ll = long long;
using vi = vector<int>;
using vll = vector<ll>;

template<class T> bool ckmin(T& a, const T& b) { return b < a ? a = b, 1 : 0; }
template<class T> bool ckmax(T& a, const T& b) { return a < b ? a = b, 1 : 0; }

int main() {
  int n, wn;
  cin >> n >> wn;
  vll w(n), v(n);
  for (int i = 0; i < n; ++i) {
    cin >> w[i] >> v[i];
  }
  vll dp(wn + 1);
  for (int i = 0; i < n; ++i) {
    for (int j = wn; j >= w[i]; --j) {
      if (!(j - w[i]) || dp[j - w[i]]) ckmax(dp[j], dp[j - w[i]] + v[i]);
    }
  }
  ll ans = dp[0];
  for (int i = 1; i <= wn; ++i) ckmax(ans, dp[i]);
  cout << ans << endl;
}