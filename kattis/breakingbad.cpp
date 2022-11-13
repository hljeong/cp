#include <bits/stdc++.h>
#define A first
#define B second
#define vc vector
using namespace std;
using ll = long long; using ld = long double;
using vi = vc<int>; using vll = vc<ll>;
using si = set<int>; using sll = set<ll>;
using pii = pair<int, int>; using mii = map<int, int>;
using gr = vc<vi>;

template<class T> bool ckmin(T &a, const T &b) { return b < a ? a = b, 1 : 0; }
template<class T> bool ckmax(T &a, const T &b) { return a < b ? a = b, 1 : 0; }

const int inf = 1e9 + 7;
const int mod = inf;

bool bipartite(gr &g, int i, vi &lbl, int cur, vc<bool> &vis) {
  lbl[i] = cur;
  vis[i] = true;
  for (int j : g[i]) {
    if (vis[j]) {
      if (lbl[i] == lbl[j]) return false;
    } else if (!bipartite(g, j, lbl, cur ^ 1, vis)) {
      return false;
    }
  }
  return true;
}

bool bipartite(gr &g, vi &lbl) {
  int n = g.size();
  vc<bool> vis(n);
  for (int i = 0; i < n; ++i) if (!vis[i] && !bipartite(g, i, lbl, 0, vis)) return false;
  return true;
}

bool bipartite(gr &g) {
  int n = g.size();
  vi lbl(n);
  return bipartite(g, lbl);
}

int main() {
  int n; cin >> n;
  map<string, int> id;
  vc<string> ss(n);
  for (int i = 0; i < n; ++i) {
    string s; cin >> s;
    ss[i] = s;
    id[s] = i;
  }
  gr g(n, vi());
  vi lbl(n);
  int m; cin >> m;
  for (int i = 0; i < m; ++i) {
    string u, v; cin >> u >> v;
    g[id[u]].push_back(id[v]);
    g[id[v]].push_back(id[u]);
  }
  if (!bipartite(g, lbl)) {
    cout << "impossible" << endl;
    return 0;
  }
  for (int i = 0; i < n; ++i) {
    if (!lbl[i]) cout << ss[i] << ' ';
  }
  cout << endl;
  for (int i = 0; i < n; ++i) {
    if (lbl[i]) cout << ss[i] << ' ';
  }
  cout << endl;
}
