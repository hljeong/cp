#include <bits/stdc++.h>
#define A first
#define B second
#define vc vector
using namespace std;
using ll = long long;
using vi = vector<int>;
using vll = vector<ll>;
using pii = pair<int, int>;

template<class T> bool ckmin(T& a, const T& b) { return b < a ? a = b, 1 : 0; }
template<class T> bool ckmax(T& a, const T& b) { return a < b ? a = b, 1 : 0; }

int main() {
  string s, t;
  cin >> s >> t;
  int n = s.length(), m = t.length(), ind = 0, jnd = 0, mx = 0;
  vc<vi> dp(n + 1, vi(m + 1));
  pii last = {0, 0};
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      ckmax(dp[i + 1][j], dp[i][j]);
      ckmax(dp[i][j + 1], dp[i][j]);
      ckmax(dp[i + 1][j + 1], dp[i][j]);
      if (s[i] == t[j]) if (ckmax(dp[i + 1][j + 1], dp[i][j] + 1) && ckmax(mx, dp[i + 1][j + 1])) ind = i + 1, jnd = j + 1;
    }
  }
  string ans = "";
  while (dp[ind][jnd]) {
    while (dp[ind][jnd] == dp[ind - 1][jnd]) --ind;
    while (dp[ind][jnd] == dp[ind][jnd - 1]) --jnd;
    ans = s[--ind] + ans;
    --jnd;
  }
  cout << ans << endl;
}