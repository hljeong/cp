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
template<class T> bool ckmax(T &a, const T &b) { return b > a ? a = b, 1 : 0; }

const int inf = 1e9 + 7;
const int mod = inf;
const ll infll = 0x3f3f3f3f3f3f3f3fll;

using graph = vc<vi>;

void dfs(graph &g, int i, vc<bool> &vis, vi &ordered) {
  vis[i] = true;
  for (int j : g[i])
    if (!vis[j])
      dfs(g, j, vis, ordered);
  ordered.pb(i);
}

vc<vi> kosaraju(graph &g) {
  int n = g.size();
  vi ordered;
  vc<bool> vis(n);
  for (int i = 0; i < n; ++i)
    if (!vis[i])
      dfs(g, i, vis, ordered);
  graph transpose(n);
  for (int i = 0; i < n; ++i)
    for (int j : g[i])
      transpose[j].pb(i);
  reverse(ordered.begin(), ordered.end());
  vc<vi> scc;
  fill(vis.begin(), vis.end(), false);
  for (int i : ordered) {
    if (vis[i]) continue;
    vi comp;
    dfs(transpose, i, vis, comp);
    scc.pb(comp);
  }
  return scc;
}

ll solve(vc<si> &g, int i, vc<bool> &vis) {
  ll ret = 1;
  vis[i] = true;
  for (int j : g[i]) {
    ret = (ret * (solve(g, j, vis) + 1)) % mod;
  }
  return ret;
}

int main() {
  int n; cin >> n;
  graph g(n);
  for (int i = 0; i < n; ++i) {
    int j; cin >> j; --j;
    g[j].pb(i);
  }
  vc<vi> scc = kosaraju(g);
  int m = scc.size();
  vi lbl(n);
  for (int i = 0; i < m; ++i)
    for (int j : scc[i])
      lbl[j] = i;
  vc<si> f(m);
  for (int i = 0; i < n; ++i) {
    for (int j : g[i]) {
      if (lbl[i] != lbl[j]) f[lbl[i]].insert(lbl[j]);
    }
  }
  vc<bool> vis(m);
  ll ret = 1;
  for (int i = 0; i < m; ++i) {
    if (vis[i]) continue;
    ret = (ret * (solve(f, i, vis) + 1)) % mod;
  }
  cout << ((ret + mod - 1) % mod) << endl;
}