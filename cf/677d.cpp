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

constexpr int inf = 1e9 + 7;
constexpr int mod = inf;
constexpr ll infll = 0x3f3f3f3f3f3f3f3fll;

// editorial sol: naive dp or bfs depending on number of transitions
// sqrt complexity
int main() {
  cin.tie(0) -> sync_with_stdio(0);

  int n, m, p; cin >> n >> m >> p;
  vc<vc<pi>> c(p);
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      int a; cin >> a; --a;
      c[a].pb({ i, j });
    }
  }
  vc<vi> dp(n, vi(m, inf));
  for (auto [i, j] : c[0]) {
    dp[i][j] = i + j;
  }
  for (int k = 1; k < p; ++k) {
    if (c[k].size() * c[k - 1].size() > n * m) {
      vc<vi> d(n, vi(m, inf));
      queue<pi> bfs;
      for (auto [i, j] : c[k - 1]) {
        d[i][j] = dp[i][j];
        bfs.push({ i, j });
      }
      while (bfs.size()) {
        auto [i, j] = bfs.front(); bfs.pop();
        if (i && ckmin(d[i - 1][j], d[i][j] + 1)) bfs.push({ i - 1, j });
        if (j && ckmin(d[i][j - 1], d[i][j] + 1)) bfs.push({ i, j - 1 });
        if (i < n - 1 && ckmin(d[i + 1][j], d[i][j] + 1)) bfs.push({ i + 1, j });
        if (j < m - 1 && ckmin(d[i][j + 1], d[i][j] + 1)) bfs.push({ i, j + 1 });
      }
      for (auto [i, j] : c[k]) {
        dp[i][j] = d[i][j];
      }
    } else {
      for (auto [pi, pj] : c[k - 1]) {
        for (auto [i, j] : c[k]) {
          ckmin(dp[i][j], dp[pi][pj] + abs(pi - i) + abs(pj - j));
        }
      }
    }
  }
  cout << dp[c[p - 1][0].A][c[p - 1][0].B] << endl;
}
