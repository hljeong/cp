#include <bits/stdc++.h>
#define A first
#define B second
#define vc vector
using namespace std;
using ll = long long;
using vi = vc<int>;
using vll = vc<ll>;
using pii = pair<int, int>;

template<class T> bool ckmin(T& a, const T& b) { return b < a ? a = b, 1 : 0; }
template<class T> bool ckmax(T& a, const T& b) { return a < b ? a = b, 1 : 0; }

int main() {
  int n, m;
  cin >> n >> m;
  vc<vi> g(n, vi());
  vi indeg(n);
  for (int i = 0; i < m; ++i) {
    int u, v;
    cin >> u >> v, --u, --v;
    g[u].push_back(v);
    ++indeg[v];
  }
  queue<int> q;
  for (int i = 0; i < n; ++i) {
    if (!indeg[i]) q.push(i);
  }
  vi sorted;
  while (q.size()) {
    int i = q.front();
    q.pop();
    sorted.push_back(i);
    for (int j : g[i]) if (!--indeg[j]) q.push(j);
  }
  vi dp(n);
  int ans = 0;
  for (int i = 0; i < n; ++i) {
    for (int j : g[sorted[i]]) ckmax(dp[j], dp[sorted[i]] + 1);
    ckmax(ans, dp[sorted[i]]);
  }
  cout << ans << endl;
}