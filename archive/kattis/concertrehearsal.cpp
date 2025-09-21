#include <bits/stdc++.h>
#define A first
#define B second
#define vc vector
#define pb push_back
using namespace std;
using ll = long long; using ld = long double;
using vi = vc<int>; using vll = vc<ll>;
using si = set<int>; using sll = set<ll>;
using pii = pair<int, int>; using mii = map<int, int>;

template<class T> bool ckmin(T &a, const T &b) { return b < a ? a = b, 1 : 0; }
template<class T> bool ckmax(T &a, const T &b) { return a < b ? a = b, 1 : 0; }

const int inf = 1e9 + 7;
const int mod = inf;
const ll infll = 0x3f3f3f3f3f3f3f3fll;

struct graph {
  vc<vi> adj;
  vc<map<int, ll>> w;

  graph(int n) : adj(n, vi()), w(n, map<int, ll>()) {}
  graph(const graph &g) : adj(g.adj), w(g.w) {}

  void cto(int from, int to, ll weight) {adj[from].pb(to); w[from][to] += weight;}
  void cto(int from, int to) {cto(from, to, 1);}
  void c(int from, int to) {cto(from, to); cto(to, from);}
  void c(int from, int to, ll weight) {cto(from, to, weight); cto(to, from, weight);}

  vi operator[](int u) {return adj[u];}
  vc<vi>::iterator begin() {return adj.begin();}
  vc<vi>::const_iterator begin() const {return adj.begin();}
  vc<vi>::iterator end() {return adj.end();}
  vc<vi>::const_iterator end() const {return adj.end();}
  int size() const {return adj.size();}
};

template<class T> T minst(function<bool(T)> pred, T i, T j) {
  T ret = j + 1;
  for (T l = i, r = j, m; l <= r; ) {
    if (pred(m = l + (r - l) / 2)) r = (ret = m) - 1;
    else l = m + 1;
  }
  return ret;
}

int main() {
  int n, p, k; cin >> n >> p >> k;
  vi d(n); for (int i = 0; i < n; ++i) cin >> d[i];
  vll pre(2 * n + 1);
  for (int i = 0; i < 2 * n; ++i) pre[i + 1] = pre[i] + d[i % n];
  int cyc = p / pre[n]; p %= pre[n];
  graph g(n);
  for (int i = 0; i < n; ++i) {
    function<bool(int)> pred = [&](int j) {
      return pre[j] - pre[i] > p;
    };
    int j = minst(pred, i + 1, 2 * n) - 1;
    // cout << i << " -" << (cyc + (j >= n)) << "-> " << j << endl; 
    g.cto(i, j % n, cyc + (j >= n));
  }
  vc<vll> dp(n, vll(30));
  vc<vi> nxt(n, vi(30));
  for (int i = 0; i < n; ++i) {
    nxt[i][0] = g[i][0];
    dp[i][0] = g.w[i][nxt[i][0]];
  }
  for (int j = 1; j < 30; ++j) {
    for (int i = 0; i < n; ++i) {
      nxt[i][j] = nxt[nxt[i][j - 1]][j - 1];
      dp[i][j] = dp[i][j - 1] + dp[nxt[i][j - 1]][j - 1];
    }
  }
  ll ret = 0;
  int cur = 0;
  for (int j = 29; j >= 0; --j) {
    if (k >= (1 << j)) {
      ret += dp[cur][j];
      cur = nxt[cur][j];
      k -= 1 << j;
    }
  }
  cout << ret << endl;
}
