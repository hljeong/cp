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

const int inf = 1e9 + 7;

int lg(int x) {
  if (x < 0) x = -x - 1;
  int l = 0;
  while (x) {
    ++l;
    x >>= 1;
  }
  return l;
}

int main() {
  int n, c; cin >> n >> c;
  vi x(n); for (int i = 0; i < n; ++i) cin >> x[i];
  vc<vi> dp(n, vi(62, inf));
  vi best(n, inf);
  int lgx0 = lg(x[0]);
  for (int i = lgx0 + !!x[0]; i <= 30; ++i) {
    ckmin(dp[0][i], c + i);
    ckmin(best[0], dp[0][i]);
  }
  for (int i = lgx0; i <= 30; ++i) {
    ckmin(dp[0][31 + i], c + i);
    ckmin(best[0], dp[0][31 + i]);
  }
  for (int i = 1; i < n; ++i) {
    int lgxi = lg(x[i]), lgd = lg(x[i] - x[i - 1]) + (x[i] != x[i - 1]);
    // cout << i << ": " << lgxi << ' ' << lgd << endl;
    for (int j = lgd; j <= 30; ++j) {
      ckmin(dp[i][j], best[i - 1] + c + j);
      ckmin(dp[i][j], dp[i - 1][j] + j);
      ckmin(best[i], dp[i][j]);// && (cout << i << ' ' << j << ' ' << best[i] << endl);
    }
    for (int j = lgxi; j <= 30; ++j) {
      ckmin(dp[i][31 + j], best[i - 1] + c + j);
      ckmin(dp[i][31 + j], dp[i - 1][31 + j] + j);
      ckmin(best[i], dp[i][31 + j]);// && (cout << i << ' ' << (31 + j) << ' ' << best[i] << endl);
    }
  }
  // for (int i = 0; i < n; ++i) cout << best[i] << " \n"[i == n - 1];
  cout << best[n - 1] << endl;
}
