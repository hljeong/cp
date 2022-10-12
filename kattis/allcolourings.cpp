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

// unsolved
// idea: bitmask on subset of edges with same-colored vertices, then contract graph and count k-colorings in the contracted graph
// (counting k-colorings is difficult)

const int mod = 1e9 + 9;

using dsu = pair<vi, vi>;

int find(dsu &d, int i) {
  return d.A[i] == i ? i : (d.A[i] = find(d, d.A[i]));
}

bool combine(dsu &d, int i, int j) {
  i = find(d, i); j = find(d, j);
  if (i != j) {
    if (d.B[i] < d.B[j]) swap(i, j);
    d.A[j] = i; d.B[i] += d.B[j];
    return true;
  }
  return false;
}

int solve(vc<set<int>> &g, int k) {
  ll ans = 1;
  int n = g.size();
  cout << n << endl;
  for (int i = 0; i < n; ++i) {
    for (int j : g[i]) {
      cout << j << ' ';
    }
    int bad = 0;
    set<int> v;
    for (int j : g[i]) {
      if (j > i) continue;
      v.insert(j);
      int not_good = 0;
      for (int j2 : g[j]) {
        if (v.find(j2) != v.end()) continue;
        not_good = 1;
      }
      bad += not_good;
    }
    cout << "bad: " << bad << " contrib: " << max(0, k - bad) << endl;
    ans *= max(0, k - bad);
    ans %= mod;
  }
  cout << endl;
  return (int) ans;
}

int main() {
  int n, m, k; cin >> n >> m >> k;
  vc<vi> g(n, vi());
  vc<pii> e(m);
  for (int i = 0; i < m; ++i) {
    int u, v; cin >> u >> v; --u; --v;
    g[u].push_back(v);
    g[v].push_back(u);
    e[i].A = u;
    e[i].B = v;
  }
  vi ans(m + 1);
  for (int mask = 0; mask < (1 << m); ++mask) {
    int pcnt = __builtin_popcount(mask);
    vi par(n), sz(n);
    dsu d = {par, sz};
    for (int i = 0; i < n; ++i) {
      d.A[i] = i;
      d.B[i] = 1;
    }
    for (int i = 0; i < m; ++i) {
      if ((mask & (1 << i))) combine(d, e[i].A, e[i].B);
    }
    int id = 0;
    map<int, int> mp;
    for (int i = 0; i < n; ++i) {
      if (mp.find(find(d, i)) == mp.end()) {
        mp[find(d, i)] = id++;
      }
    }
    vc<set<int>> ng(id, set<int>());
    for (int i = 0; i < m; ++i) {
      int u = mp[find(d, e[i].A)], v = mp[find(d, e[i].B)];
      if (u == v) continue;
      ng[u].insert(v);
      ng[v].insert(u);
    }
    ans[pcnt] += solve(ng, k);
    if (ans[pcnt] >= mod) ans[pcnt] -= mod;
  }
  for (int i = 0; i <= m; ++i) cout << ans[i] << " \n"[i == m];
}
