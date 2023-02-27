#include <bits/stdc++.h>
#define A first
#define B second
#define vc vector
#define pb push_back
using namespace std;
using ll = long long; using ld = long double;
using vi = vc<int>; using vll = vc<ll>;
using si = set<int>; using sll = set<ll>;
using pii = pair<int, int>; using pll = pair<ll, ll>;
using mii = map<int, int>;

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

void solve(graph &g, int i, vi &vis, vc<vi> &dp, vi &id) {
  dp[i][id[i]] = 1;
  vis[i] = 1;
  for (int j : g[i]) {
    if (!vis[j]) solve(g, j, vis, dp, id);
    ckmin(dp[i][1], 1 + dp[j][1]);
    ckmin(dp[i][2], 1 + dp[j][2]);
    ckmin(dp[i][3], 1 + dp[j][3]);
  }
  ckmin(dp[i][3], dp[i][1] + dp[i][2] - 1);
}

int main() {
  int h, w; cin >> h >> w;
  graph g(9903);
  vc<vi> mp(h, vi(w));
  for (int i = 0; i < h; ++i) {
    for (int j = 0; j < w; ++j) {
      cin >> mp[i][j];
    }
  }
  for (int i = 0; i < h - 1; ++i) {
    for (int j = 0; j < w; ++j) {
      if (mp[i][j] != mp[i + 1][j] && !g.w[mp[i + 1][j]][mp[i][j]]) {
        g.cto(mp[i + 1][j], mp[i][j]);
      }
    }
  }
  for (int i = 0; i < w; ++i) {
    if (!g.w[0][mp[h - 1][i]]) g.cto(0, mp[h - 1][i]);
  }
  /*
  for (int i = 0; i < 14; ++i) {
    cout << i << ": ";
    for (int j : g[i]) cout << j << ' ';
    cout << endl;
  }
  */
  int t = 0;
  vi id(9903);
  for (int i = 0; i < w; ++i) {
    if (!id[mp[0][i]]) id[mp[0][i]] = 1 << t++;
  }
  /*
  for (int i = 0; i < 14; ++i) {
    cout << id[i] << " \n"[i == 13];
  }
  */
  vi vis(9903);
  vc<vi> dp(9903, vi(4, inf));
  solve(g, 0, vis, dp, id);
  /*
  for (int i = 0; i < 14; ++i) {
    cout << i << ": ";
    for (int j = 0; j <= 3; ++j) {
      cout << dp[i][j] << " \n"[j == 3];
    }
  }
  */
  cout << (dp[0][(1 << t) - 1] - 1) << endl;
}
