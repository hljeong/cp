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

const int maxn = 5e4 + 5, maxk = 505;

int n, k, dp[maxn][maxk];
ll ans = 0;
vc<vi> g(maxn);

void solve(int i = 0, int p = -1) {
  ++dp[i][0];
  for (int j : g[i]) {
    if (j == p) continue;
    solve(j, i);
    for (int l = 0; l < k; ++l) ans += (ll) dp[i][l] * dp[j][k - 1 - l];
    for (int l = 0; l < k; ++l) dp[i][l + 1] += dp[j][l];
  }
}

int main() {
  cin >> n >> k; 
  for (int i = 1; i < n; ++i) {
    int a, b;
    cin >> a >> b, --a, --b;
    g[a].push_back(b);
    g[b].push_back(a);
  }
  solve();
  cout << ans << endl;
}