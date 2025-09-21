#include <bits/stdc++.h>
#define A first
#define B second
#define vc vector
#define pb push_back
#define endl '\n'
using namespace std;
using ll = long long; using ld = long double;
using vi = vc<int>; using vll = vc<ll>;
using si = set<int>; using sll = set<ll>;
using pi = pair<int, int>; using pll = pair<ll, ll>;
using qi = queue<int>; using mi = map<int, int>;

template<class T> bool ckmin(T &a, const T &b) { return b < a ? a = b, 1 : 0; }
template<class T> bool ckmax(T &a, const T &b) { return a < b ? a = b, 1 : 0; }

const int inf = 1e9 + 7;
const int mod = inf;
const ll infll = 0x3f3f3f3f3f3f3f3fll;

int main() {
  cin.tie(0) -> sync_with_stdio(0);

  int t; cin >> t;
  while (t--) {
    int n, k; ll x; cin >> n >> k >> x;
    vll a(n); for (int i = 0; i < n; ++i) cin >> a[i];
    vc<vc<vll>> dp(n + 1, vc<vll>(k + 1, vll(3, -infll)));
    dp[0][0][0] = 0;
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j <= k; ++j) {
        ckmax(dp[i + 1][j][0], dp[i][j][0]);
        ckmax(dp[i + 1][j][1], dp[i][j][0] + (a[i] - x));
        ckmax(dp[i + 1][j][1], dp[i][j][1] + (a[i] - x));
        ckmax(dp[i + 1][j][2], dp[i][j][0]);
        ckmax(dp[i + 1][j][2], dp[i][j][0] + (a[i] - x));
        ckmax(dp[i + 1][j][2], dp[i][j][1] + (a[i] - x));
        ckmax(dp[i + 1][j][2], dp[i][j][2]);

        if (j < k) {
          ckmax(dp[i + 1][j + 1][0], dp[i][j][0]);
          ckmax(dp[i + 1][j + 1][1], dp[i][j][0] + (a[i] + x));
          ckmax(dp[i + 1][j + 1][1], dp[i][j][1] + (a[i] + x));
          ckmax(dp[i + 1][j + 1][2], dp[i][j][0]);
          ckmax(dp[i + 1][j + 1][2], dp[i][j][0] + (a[i] + x));
          ckmax(dp[i + 1][j + 1][2], dp[i][j][1] + (a[i] + x));
          ckmax(dp[i + 1][j + 1][2], dp[i][j][2]);
        }
      }
    }
    cout << dp[n][k][2] << endl;
  }
}
