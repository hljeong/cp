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

// upsolve, editorial sol
// binary search, greedy from bottom
// if can fit below then do so, otherwise move up and deal w later
int main() {
  cin.tie(0) -> sync_with_stdio(0);

  int t; cin >> t;
  while (t--) {
    int n; cin >> n;
    graph g(n, n - 1);
    int k; cin >> k;
    vi a(n, -1), a_tmp(n);
    // a[i] = 0-based order, -1 if empty
    for (int i = 0; i < k; ++i) {
      int j; cin >> j; a[j - 1] = i;
    }
    // returns -1 if bad, otherwise longest possible path
    function<int(int, int)> check = [&](int i, int p) {
      int len = 0;
      for (int j : g[i]) {
        if (j == p) continue;
        int slen = check(j, i);
        if (!~slen) return -1;
        ckmax(len, slen);
      }
      // has chip to deal with
      if (~a_tmp[i]) {
        // can fit in bottom
        if (len >= a_tmp[i]) {
          return 0;
        // can push to parent
        } else if (p != -1 && !~a_tmp[p]) {
          a_tmp[p] = a_tmp[i] - 1;
          return 0;
        // otherwise bad
        } else {
          return -1;
        }
      }
      // no chip to deal with, maximize length
      return 1 + len;
    };
    int ret = 0;
    for (int l = 0, r = n - k; l <= r; ) {
      int m = l + (r - l) / 2;
      // a_tmp[i] = moves needed, -1 if empty
      for (int i = 0; i < n; ++i) {
        if (~a[i]) {
          a_tmp[i] = m / k + (a[i] < m % k);
        } else a_tmp[i] = -1;
      }
      if (~check(0, -1)) {
        ret = m;
        l = m + 1;
      } else r = m - 1;
    }
    cout << ret << endl;
  }
}
