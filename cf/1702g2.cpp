#include <bits/stdc++.h>
#define A first
#define B second
#define vc vector
using namespace std;
using ll = long long;
using ld = long double;
using vi = vc<int>;
using vll = vc<ll>;
using pii = pair<int, int>;

template<class T> bool ckmin(T &a, const T &b) { return b < a ? a = b, 1 : 0; }
template<class T> bool ckmax(T &a, const T &b) { return a < b ? a = b, 1 : 0; }

void dfs(vc<vi> &g, vi &dep, vc<vi> &anc, int i = 0, int p = -1) {
  if (!~p) fill(anc[i].begin(), anc[i].end(), i);
  else {
    anc[i][0] = p;
    for (int k = 1; k < 20; ++k) {
      anc[i][k] = anc[anc[i][k - 1]][k - 1];
    }
  }
  for (int j : g[i]) {
    if (j == p) continue;
    dep[j] = dep[i] + 1;
    dfs(g, dep, anc, j, i);
  }
}

int lca(vi &dep, vc<vi> &anc, int u, int v) {
  if (dep[u] > dep[v]) swap(u, v);
  for (int i = 19; i >= 0; --i) if (dep[anc[v][i]] >= dep[u]) v = anc[v][i];
  if (u == v) return u;
  for (int i = 19; i >= 0; --i) if (anc[u][i] != anc[v][i]) {
    u = anc[u][i]; v = anc[v][i];
  }
  return anc[u][0];
}

int main() {
  int n; cin >> n;
  vc<vi> g(n); for (int i = 1; i < n; ++i) {
    int u, v; cin >> u >> v; --u; --v;
    g[u].push_back(v);
    g[v].push_back(u);
  }
  vi dep(n);
  vc<vi> anc(n, vi(20));
  dfs(g, dep, anc);
  int q; cin >> q;
  while (q--) {
    int k; cin >> k;
    int end = -1, mxdep = -1;
    vi p(k); vc<pii> ps; for (int i = 0; i < k; ++i) {
      cin >> p[i]; --p[i];
      ps.push_back({-dep[p[i]], p[i]});
    }
    sort(ps.begin(), ps.end());
    int b1 = ps[0].B, b2 = -1, hi = dep[b1];
    bool good = true;
    for (int i = 1; i < k; ++i) {
      ckmin(hi, dep[ps[i].B]);
      int lc = lca(dep, anc, ps[i].B, b1);
      if (lc != ps[i].B) {
        if (!~b2) b2 = ps[i].B;
        else good &= lca(dep, anc, ps[i].B, b2) == ps[i].B;
      }
    }
    good &= (!~b2) || hi >= dep[lca(dep, anc, b1, b2)];
    cout << (good ? "YES" : "NO") << endl;
  }
}