#include <bits/stdc++.h>
#define A first
#define B second
using namespace std;
using ll = long long;
using vi = vector<int>;

template<class T> bool ckmin(T& a, const T& b) { return b < a ? a = b, 1 : 0; }
template<class T> bool ckmax(T& a, const T& b) { return a < b ? a = b, 1 : 0; }

int main() {
  int n;
  cin >> n;
  vi h(n + 1);
  for (int i = 0; i < n; ++i) cin >> h[i];
  vi dp(n + 1, 0x3f3f3f3f);
  dp[0] = 0;
  for (int i = 0; i < n - 1; ++i) {
    ckmin(dp[i + 1], dp[i] + abs(h[i + 1] - h[i]));
    ckmin(dp[i + 2], dp[i] + abs(h[i + 2] - h[i]));
  }
  cout << dp[n - 1] << endl;
}