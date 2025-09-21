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

struct graph {
  vc<vi> adj;
  vc<map<int, ll>> w;

  graph(int n) : adj(n, vi()), w(n, map<int, ll>()) {}
  graph(const graph &g) : adj(g.adj), w(g.w) {}
  graph(int n, int m, int off = 1) : adj(n, vi()), w(n, map<int, ll>()) {
    for (int i = 0, u, v; i < m; ++i) {
      cin >> u >> v; u -= off; v -= off;
      c(u, v);
    }
  }

  void cto(int from, int to, ll weight) { adj[from].pb(to); w[from][to] += weight; }
  void cto(int from, int to) { cto(from, to, 1); }
  void c(int from, int to) { cto(from, to); cto(to, from); }
  void c(int from, int to, ll weight) { cto(from, to, weight); cto(to, from, weight); }

  vi operator[](int u) { return adj[u]; }
  vc<vi>::iterator begin() { return adj.begin(); }
  vc<vi>::const_iterator begin() const { return adj.begin(); }
  vc<vi>::iterator end() { return adj.end(); }
  vc<vi>::const_iterator end() const { return adj.end(); }
  int size() const { return adj.size(); }
};

const int inf = 1e9 + 7;
const int mod = inf;
const ll infll = 0x3f3f3f3f3f3f3f3fll;

int lob(int x) {
  int ret = 0;
  while (~x & 1) {
    x >>= 1;
    ++ret;
  }
  return ret;
}

int main() {
  cin.tie(0) -> sync_with_stdio(0);

  int n, m; cin >> n >> m;
  graph g(n, m);
  vc<vi> dp(1 << n, vi(n)), bt(1 << n, vi(n, -1));
  for (int i = 0; i < n; ++i) dp[1 << i][i] = 1;
  for (int i = 1; i < (1 << n); ++i) {
    for (int j = lob(i); j < n; ++j) {
      if (!dp[i][j]) continue;
      for (int k : g[j]) {
        if (k < lob(i)) continue;
        if ((~i >> k) & 1) {
          dp[i | (1 << k)][k] = 1;
          bt[i | (1 << k)][k] = j;
        }
      }
    }
  }
  vi ret(n);
  int yes = 0;
  for (int mask = 3; mask < (1 << n); ++mask) {
    // cout << endl;
    if (__builtin_popcount(mask) < 2) continue;
    int good = 1, last = -1;
    for (int i = 0; i < n; ++i) {
      if ((~mask >> i) & 1) {
        int subgood = 0;
        for (int j : g[i]) {
          if ((mask >> j) & 1) {
            // cout << i << ' ' << j << endl;
            subgood = 1;
            break;
          }
        }
        if (!subgood) {
          good = 0;
          break;
        }
      } else if (dp[mask][i]) {
        for (int j : g[i]) {
          if (j == lob(mask)) {
            last = i;
            break;
          }
        }
      }
    }
    if (!good || last == -1) continue;
    for (int i = 0; i < n; ++i) {
      if ((~mask >> i) & 1) {
        for (int j : g[i]) if ((mask >> j) & 1) {
          ret[i] = j;
          break;
        }
      }
    }
    int cur = last;
    ret[cur] = lob(mask);
    // cout << bitset<20>(mask) << endl;
    // cout << cur << "->" << lob(mask) << endl;
    while (bt[mask][cur] != -1) {
      // cout << bitset<20>(mask) << endl;
      // cout << bt[mask][cur] << "->" << cur << endl;
      ret[bt[mask][cur]] = cur;
      mask ^= 1 << cur;
      cur = bt[mask | (1 << cur)][cur];
    }
    yes = 1;
    break;
  }
  if (yes) {
    cout << "Yes" << endl;
    for (int i = 0; i < n; ++i) cout << (ret[i] + 1) << " \n"[i == n - 1];
  } else cout << "No" << endl;
}
