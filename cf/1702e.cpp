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

bool dfs(vc<vi> &g, vi &lbl, int i, int c) {
  if (lbl[i] >= 0) return lbl[i] == c;
  lbl[i] = c;
  for (int j : g[i]) {
    if (!dfs(g, lbl, j, c ^ 1)) return false;
  }
  return true;
}

int main() {
  int t; cin >> t;
  while (t--) {
    int n; cin >> n;
    bool good = true;
    vc<vi> g(n); map<int, int> f; for (int i = 0; i < n; ++i) {
      int u, v; cin >> u >> v; --u; --v;
      g[u].push_back(v);
      g[v].push_back(u);
      good &= ++f[u] <= 2;
      good &= ++f[v] <= 2;
    }
    vi lbl(n, -1);
    for (int i = 0; i < n; ++i) {
      if (lbl[i] == -1) good &= dfs(g, lbl, i, 0);
    }
    cout << (good ? "YES" : "NO") << endl;
  }
}