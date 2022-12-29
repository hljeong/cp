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
using gr = vc<vi>; using wgr = vc<vc<pii>>;

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

vll dijkstra(graph &g, int s) {
  int n = g.size(); vll d(n, infll);
  priority_queue<pair<ll, int>> q;
  d[s] = 0; q.push({0, s});
  while (q.size()) {
    auto p = q.top(); q.pop(); int u = p.B;
    if (-p.A > d[u]) continue;
    for (int v : g[u]) if (ckmin(d[v], d[u] + g.w[u][v])) q.push({-d[v], v});
  }
  return d;
}

template<class T> T minst(function<bool(T)> pred, T i, T j) {
  T ret = j + 1;
  for (T l = i, r = j, m; l <= r; ) {
    if (pred(m = l + (r - l) / 2)) r = (ret = m) - 1;
    else l = m + 1;
  }
  return ret;
}

using job = array<int, 3>;

int main() {
  int n, m; cin >> n >> m;
  graph g(n);
  for (int i = 0; i < m; ++i) {
    int u, v, d; cin >> u >> v >> d; --u; --v;
    g.c(u, v, d);
  }
  int k; cin >> k;
  vc<job> jb(k);
  map<int, vll> dist;
  dist[0] = dijkstra(g, 0);
  for (int i = 0; i < k; ++i) {
    cin >> jb[i][0] >> jb[i][1] >> jb[i][2]; --jb[i][1];
    dist[jb[i][1]] = dijkstra(g, jb[i][1]);
  }
  vc<vll> w(k, vll(k)), d(k, vll(k));
  for (int i = 0; i < k; ++i) {
    // ll wait = 0, trip = 0;
    ll wait = -infll, trip = 0;
    int last = 0;
    for (int j = i; j < k; ++j) {
      trip += dist[last][jb[j][1]];
      // wait += trip - jb[j][0];
      ckmax(wait, trip - jb[j][0]);
      last = jb[j][1];
      w[i][j] = wait;
      d[i][j] = trip + dist[last][0];
      // cout << i << ", " << j << ": " << w[i][j] << ", " << d[i][j] << endl;
    }
  }
  /* 
  vll dp(k + 1, infll), dpt(k + 1);
  dp[0] = 0;
  for (int i = 0; i < k; ++i) {
    for (int j = 0; j <= i; ++j) {
      ll departure = max((ll) jb[i][2], dpt[j]);
      // if (ckmin(dp[i + 1], dp[j] + w[j][i] + (i - j + 1) * departure)) {
      if (ckmin(dp[i + 1], max(dp[j], w[j][i] + departure))) {
        dpt[i + 1] = departure + d[j][i];
      }
    }
    // cout << dp[i + 1] << " @ " << dpt[i + 1] << endl;
  }
  */
  function<bool(ll)> pred = [&](ll wait) {
    vll dp(k + 1, infll);
    dp[0] = 0;
    for (int i = 0; i < k; ++i) {
      for (int j = 0; j <= i; ++j) {
        ll depart = max((ll) jb[i][2], dp[j]);
        if (depart + w[j][i] > wait) continue;
        ckmin(dp[i + 1], depart + d[j][i]);
      }
    }
    return dp[k] < infll;
  };
  cout << minst(pred, 0ll, infll) << endl;
}
