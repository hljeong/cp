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
  int n, c; cin >> n >> c;
  vc<pii> r(n); for (int i = 0; i < n; ++i) cin >> r[i].A >> r[i].B;
  vc<pii> dp(c + 1, {2 * 150 * 5000, 0});
  dp[0] = {0, 0};
  for (int i = 0; i < n; ++i) {
    vc<pii> ndp(c + 1, {2 * 150 * 5000, 0});
    for (int j = 0; j <= c; ++j) {
      if (j <= c - r[i].A) {
        int nrh = max(dp[j].B, r[i].B);
        if (ndp[j + r[i].A].A + ndp[j + r[i].A].B > dp[j].A + nrh) {
          ndp[j + r[i].A] = {dp[j].A, nrh};
        }
      }
      if (ndp[r[i].A].A + ndp[r[i].A].B > dp[j].A + dp[j].B + r[i].B) {
        ndp[r[i].A] = {dp[j].A + dp[j].B, r[i].B};
      }
    }
    dp = ndp;
  }
  int ans = 2 * 150 * 5000;
  for (int i = 0; i <= c; ++i) ckmin(ans, dp[i].A + dp[i].B);
  cout << ans << endl;
}
