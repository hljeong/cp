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

template<class T> bool ckmin(T &a, const T &b) { return b < a ? a = b, 1 : 0; }
template<class T> bool ckmax(T &a, const T &b) { return a < b ? a = b, 1 : 0; }

int main() {
  int r; cin >> r;
  vi routines(r);
  for (int i = 0; i < r; ++i) {
    string routine; cin >> routine;
    for (char c : routine) routines[i] |= 1 << (c - 'A');
  }
  vc<vi> dp(1 << r, vi(r, 260));
  for (int i = 0; i < r; ++i) dp[1 << i][i] = 0;
  for (int i = 0; i < (1 << r); ++i) {
    for (int j = 0; j < r; ++j) {
      for (int k = 0; k < r; ++k) {
        if (i & (1 << k)) continue;
        ckmin(dp[i | (1 << k)][k], dp[i][j] + __builtin_popcount(routines[j] & routines[k]));
      }
    }
  }
  int ans = 260;
  for (int i = 0; i < r; ++i) ckmin(ans, dp[(1 << r) - 1][i]);
  cout << ans << endl;
}
