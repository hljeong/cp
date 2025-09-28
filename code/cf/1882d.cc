#include <bits/stdc++.h>
#define A first
#define B second
#define pb push_back
#define endl '\n'
#define tT template <typename T
#define tTU tT, class U
using namespace std;
tT > using vc = vector<T>;
using ll = long long;
using ld = long double;
using vi = vc<int>;
using vll = vc<ll>;
using si = set<int>;
using sll = set<ll>;
using pi = pair<int, int>;
using pll = pair<ll, ll>;
using qi = queue<int>;
using mi = map<int, int>;

tTU > T max(T a, U b) { return a > b ? a : b; }
tTU > T min(T a, U b) { return a < b ? a : b; }
tTU > bool ckmin(T &a, U b) { return b < a ? a = b, 1 : 0; }
tTU > bool ckmax(T &a, U b) { return a < b ? a = b, 1 : 0; }

constexpr int inf = 1e9 + 7;
constexpr int mod = 1e9 + 7;
constexpr ll infll = 0x3f3f'3f3f'3f3f'3f3fll;

// template <class... Ts> void print(string_view s, Ts... v) {
//   cout << format(s, v...);
// }
// template <class... Ts> void println(string_view s, Ts... v) {
//   print(s, v...);
//   cout << endl;
// }

tT > T read() {
  T x;
  cin >> x;
  return x;
}

int ri() { return read<int>(); }
int rll() { return read<ll>(); }

tT > T nth_bit(T x, int n) { return (x >> n) & 1; }

void solve() {
  int n = ri();
  vi a(n);
  for (int i = 0; i < n; i++)
    a[i] = ri();
  vc<vi> g(n);
  for (int i = 1; i < n; i++) {
    int u = ri() - 1, v = ri() - 1;
    g[u].pb(v);
    g[v].pb(u);
  }

  // note that when going from the bottom up, all nodes in the subtree must have
  // the same value
  // dp[u] = cost to make all nodes in subtree of u have value a[u]
  vll sz(n);
  vc<ll> dp(n);

  function<void(int, int)> dfs = [&](int u, int p) {
    for (int v : g[u]) {
      if (v == p)
        continue;
      dfs(v, u);
      sz[u] += sz[v];
      // change subtree of v to a[v] (cost = dp[v])
      // change subtree of v to a[u] (cost = (a[u] ^ a[v]) * sz[v])
      dp[u] += dp[v] + (a[u] ^ a[v]) * sz[v];
    }
    sz[u]++;
  };
  dfs(0, -1);

  vc<ll> ans(n);
  auto reroot = [&](int u, int v) {
    dp[u] -= dp[v] + (a[u] ^ a[v]) * sz[v];
    sz[u] -= sz[v];
    sz[v] += sz[u];
    dp[v] += dp[u] + (a[u] ^ a[v]) * sz[u];
  };
  dfs = [&](int u, int p) {
    ans[u] = dp[u];
    for (int v : g[u]) {
      if (v == p)
        continue;
      reroot(u, v);
      dfs(v, u);
      reroot(v, u);
    }
  };
  dfs(0, -1);

  for (int i = 0; i < n; i++)
    cout << ans[i] << " \n"[i == n - 1];
}

// each bit is independent. either set to 0 or 1
// dp[u][i][b] = min # of nodes to flip to set i-th bit in subtree of u to b
// reroot dp

int main() {
  cin.tie(0)->sync_with_stdio(0);

  int t = ri();
  while (t--) {
    solve();
    continue;

    // original solution:
    int n = ri();
    vi a(n);
    for (int i = 0; i < n; i++)
      a[i] = ri();
    vc<vi> g(n);
    for (int i = 1; i < n; i++) {
      int u = ri() - 1, v = ri() - 1;
      g[u].pb(v);
      g[v].pb(u);
    }

    vll sz(n);
    {
      function<void(int, int)> dfs = [&](int u, int p) {
        sz[u] = 1;
        for (int v : g[u]) {
          if (v == p)
            continue;
          dfs(v, u);
          sz[u] += sz[v];
        }
      };
      dfs(0, -1);
    }

    vc<vc<array<ll, 2>>> dp(n, vc<array<ll, 2>>(20));
    {
      function<void(int, int)> dfs = [&](int u, int p) {
        for (int v : g[u]) {
          if (v != p) {
            dfs(v, u);
          }
        }
        for (int i = 0; i < 20; i++) {
          int b = nth_bit(a[u], i);
          // flip all children to the same as b, then flip the whole subtree to
          // get b ^ 1
          dp[u][i][b ^ 1] = sz[u];
          for (int v : g[u]) {
            if (v == p)
              continue;
            dp[u][i][b] += dp[v][i][b];
            dp[u][i][b ^ 1] += dp[v][i][b];
          }
          // if (i <= 2) {
          //   // println("{}, {}: {} {}", u, i, dp[u][i][0], dp[u][i][1]);
          //   cout << u << ", " << i << ": " << dp[u][i][0] << " " <<
          //   dp[u][i][1]
          //        << endl;
          // }
        }
      };
      dfs(0, -1);
    }
    vll ans(n);
    {
      auto reroot = [&](int u, int v) {
        for (int i = 0; i < 20; i++) {
          int b = nth_bit(a[u], i);
          dp[u][i][b] -= dp[v][i][b];
          dp[u][i][b ^ 1] -= dp[v][i][b] + sz[v];
        }
        sz[u] -= sz[v];
        sz[v] += sz[u];
        for (int i = 0; i < 20; i++) {
          int b = nth_bit(a[v], i);
          dp[v][i][b] += dp[u][i][b];
          dp[v][i][b ^ 1] += dp[u][i][b] + sz[u];
        }
      };

      function<void(int, int)> dfs = [&](int u, int p) {
        for (int i = 0; i < 20; i++) {
          ans[u] += dp[u][i][nth_bit(a[u], i)] << i;
          // if (i <= 2) {
          //   // println("{}, {}: {} {}", u, i, dp[u][i][0], dp[u][i][1]);
          //   cout << u << ", " << i << ": " << dp[u][i][0] << " " <<
          //   dp[u][i][1]
          //        << endl;
          // }
        }
        for (int v : g[u]) {
          if (v == p)
            continue;
          reroot(u, v);
          dfs(v, u);
          reroot(v, u);
        }
      };
      dfs(0, -1);
    }
    for (int i = 0; i < n; i++)
      cout << ans[i] << " \n"[i == n - 1];
  }
}
