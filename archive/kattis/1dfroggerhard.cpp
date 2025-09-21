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

vc<si> g;
vc<bool> vis;

void kosaraju_dfs(int i, vi &ordered) {
  vis[i] = true;
  for (int j : g[i])
    if (!vis[j]) {
      // cout << i << " -> " << j << endl;
      kosaraju_dfs(j, ordered);
    }
  ordered.pb(i);
}

vc<vi> kosaraju() {
  int n = g.size();
  vis = vc<bool>(n);
  vi ordered;
  for (int i = 0; i < n; ++i)
    if (!vis[i])
      kosaraju_dfs(i, ordered);
  vc<si> t(n);
  for (int i = 0; i < n; ++i)
    for (int j : g[i])
      t[j].insert(i);
  reverse(ordered.begin(), ordered.end());
  vc<vi> scc;
  fill(vis.begin(), vis.end(), false);
  swap(g, t);
  for (int i : ordered) {
    if (vis[i]) continue;
    vi comp;
    kosaraju_dfs(i, comp);
    scc.pb(comp);
  }
  swap(g, t);
  return scc;
}

int main() {
  int n; cin >> n;
  vi a(n); for (int i = 0; i < n; ++i) cin >> a[i];
  g = vc<si>(n);
  for (int i = 0; i < n; ++i) {
    int j = i + a[i];
    if (0 <= j && j < n) {
      g[i].insert(j);
    }
  }
  vc<vi> comps = kosaraju();
  int nc = comps.size();
  vi lbl(n), sz(nc);
  vc<si> scc(nc), rscc(nc);
  for (int i = 0; i < nc; ++i) {
    for (int j : comps[i]) {
      lbl[j] = i;
      ++sz[i];
    }
  }
  for (int i = 0; i < n; ++i) {
    for (int j : g[i]) {
      if (lbl[i] != lbl[j]) {
        scc[lbl[i]].insert(lbl[j]);
        rscc[lbl[j]].insert(lbl[i]);
      }
    }
  }
  vll dp(nc);
  for (int i = 0; i < nc; ++i) {
    dp[i] += sz[i];
    for (int j : scc[i]) {
      dp[j] += dp[i];
    }
  }
  ll ret = 0;
  vc<bool> v(nc);
  const function<void(int, mii&)> dfs = [&](int i, mii &f) {
    v[i] = true;
    for (int j : comps[i]) {
      if (!f[a[j]]++) ret += dp[i];
    }
    for (int j : rscc[i]) {
      dfs(j, f);
    }
    for (int j : comps[i]) --f[a[j]];
  };
  for (int i = nc - 1; i >= 0; --i) {
    if (!v[i]) {
      mii f;
      dfs(i, f);
    }
  }
  cout << ret << endl;
}
