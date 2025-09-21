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

int main() {
  int n, m;
  cin >> n >> m;
  vi a(m);
  // sorted? distinct?
  for (int i = 0; i < m; ++i) cin >> a[i];
  sort(a.begin(), a.end());
  int l = a[0] - 1, r = n - a[m - 1]; 
  priority_queue<int> pq;
  for (int i = 1; i < m; ++i) pq.push(a[i] - a[i - 1] - 1);
  int t = 0;
  vc<vi> dp(4, vi(2, -(1e9 + 7)));
  dp[0][0] = 0;
  while (pq.size()) {
    vc<vi> ndp(4, vi(2, -(1e9 + 7)));
    ckmax(ndp[0][0], dp[0][0] + max(0, pq.top() - 2 * t - 1));
    ckmax(ndp[0][1], dp[0][1] + max(0, pq.top() - 2 * (t - 1) - 1));
    if (pq.top() - 2 * t == 1) ckmax(ndp[0][1], dp[0][0] + 1);
    ckmax(ndp[1][0], dp[0][0] + max(0, l - t) + max(0, pq.top() - 2 * (t + 1) - 1));
    ckmax(ndp[1][0], dp[1][0] + max(0, pq.top() - 2 * (t + 1) - 1));
    ckmax(ndp[1][1], dp[0][1] + max(0, l - (t - 1)) + max(0, pq.top() - 2 * t - 1));
    ckmax(ndp[1][1], dp[1][1] + max(0, pq.top() - 2 * t - 1));
    if (pq.top() - 2 * (t + 1) == 1) ckmax(ndp[1][1], dp[1][0] + 1);
    ckmax(ndp[2][0], dp[0][0] + max(0, r - t) + max(0, pq.top() - 2 * (t + 1) - 1));
    ckmax(ndp[2][0], dp[2][0] + max(0, pq.top() - 2 * (t + 1) - 1));
    ckmax(ndp[2][1], dp[0][1] + max(0, r - (t - 1)) + max(0, pq.top() - 2 * t - 1));
    ckmax(ndp[2][1], dp[2][1] + max(0, pq.top() - 2 * t - 1));
    if (pq.top() - 2 * (t + 1) == 1) ckmax(ndp[2][1], dp[2][0] + 1);
    ckmax(ndp[3][0], dp[0][0] + max(0, l - t) + max(0, r - (t + 1)) + max(0, pq.top() - 2 * (t + 2) - 1));
    ckmax(ndp[3][0], dp[0][0] + max(0, r - t) + max(0, l - (t + 1)) + max(0, pq.top() - 2 * (t + 2) - 1));
    ckmax(ndp[3][0], dp[1][0] + max(0, r - (t + 1)) + max(0, pq.top() - 2 * (t + 2) - 1));
    ckmax(ndp[3][0], dp[2][0] + max(0, l - (t + 1)) + max(0, pq.top() - 2 * (t + 2) - 1));
    ckmax(ndp[3][0], dp[3][0] + max(0, pq.top() - 2 * (t + 2) - 1));
    ckmax(ndp[3][1], dp[0][1] + max(0, l - (t - 1)) + max(0, r - t) + max(0, pq.top() - 2 * (t + 1) - 1));
    ckmax(ndp[3][1], dp[0][1] + max(0, r - (t - 1)) + max(0, l - t) + max(0, pq.top() - 2 * (t + 1) - 1));
    ckmax(ndp[3][1], dp[1][1] + max(0, r - t) + max(0, pq.top() - 2 * (t + 1) - 1));
    ckmax(ndp[3][1], dp[2][1] + max(0, l - t) + max(0, pq.top() - 2 * (t + 1) - 1));
    ckmax(ndp[3][1], dp[3][1] + max(0, pq.top() - 2 * (t + 1) - 1));
    if (pq.top() - 2 * (t + 2) == 1) ckmax(ndp[3][1], dp[3][0] + 1);
    t += 2;
    pq.pop();
    dp = ndp;
    /* 
    for (int i = 0; i < 4; ++i) {
      for (int j = 0; j < 2; ++j) cout << dp[i][j] << ' ';
      cout << endl;
    }
    cout << endl;
    /**/
  }
  int ans = max(l + max(0, r - 1), max(0, l - 1) + r);
  for (int i = 0; i < 4; ++i) for (int j = 0; j < 2; ++j) ckmax(ans, dp[i][j]);
  cout << ans << endl;
}
