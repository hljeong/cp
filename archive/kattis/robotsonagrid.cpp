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

const ll md = (1ll << 31) - 1;

struct dsu {
  vi par, sz;

  dsu(int n) : par(vi(n)), sz(vi(n)) {
    for (int i = 0; i < n; ++i) { par[i] = i; sz[i] = 1; }
  }

  int find(int i) {
    return par[i] == i ? i : (par[i] = find(par[i]));
  }

  bool combine(int i, int j) {
    // cout << "(" << (i / 7) << ", " << (i % 7) << ") -> (" << (j / 7) << ", " << (j % 7) << ")" << endl;
    i = find(i); j = find(j);
    if (i != j) {
      if (sz[i] < sz[j]) swap(i, j);
      par[j] = i; sz[i] += sz[j];
    }
    return i != j;
  }
};

// grid dp + dsu
int main() {
  cin.tie(0) -> sync_with_stdio(0);

  int n; cin >> n;
  vc<string> m(n);
  for (int i = 0; i < n; ++i) cin >> m[i];
  dsu d(n * n);
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      if (m[i][j] == '#') continue;
      if (i < n - 1 && m[i + 1][j] == '.') {
        d.combine(i * n + j, (i + 1) * n + j);
      }
      if (j < n - 1 && m[i][j + 1] == '.') {
        d.combine(i * n + j, i * n + (j + 1));
      }
    }
  }
  vc<vll> dp(n, vll(n));
  vc<vi> vis(n, vi(n));
  dp[0][0] = 1;
  vis[0][0] = 1;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      if (m[i][j] == '#') continue;
      if (i < n - 1) {
        dp[i + 1][j] += dp[i][j];
        vis[i + 1][j] |= vis[i][j];
        if (dp[i + 1][j] >= md) dp[i + 1][j] -= md;
      }
      if (j < n - 1) {
        dp[i][j + 1] += dp[i][j];
        vis[i][j + 1] |= vis[i][j];
        if (dp[i][j + 1] >= md) dp[i][j + 1] -= md;
      }
    }
  }
  // cout << d.find(0) << " " << d.find(n * n - 1) << endl;
  if (vis[n - 1][n - 1]) {
    cout << dp[n - 1][n - 1] << endl;
  } else if (d.find(0) == d.find(n * n - 1)) {
    cout << "THE GAME IS A LIE" << endl;
  } else {
    cout << "INCONCEIVABLE" << endl;
  }
}
