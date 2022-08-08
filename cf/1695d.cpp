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

template<class T> bool ckmin(T& a, const T& b) { return b < a ? a = b, 1 : 0; }
template<class T> bool ckmax(T& a, const T& b) { return a < b ? a = b, 1 : 0; }

void dfs(vc<vi> &g, int i, int p, vi &d, vi &a) {
  int need = (p == -1 && g[i].size() <= 1) - 1;
  for (int j : g[i]) {
    if (j == p) continue;
    dfs(g, j, i, d, a);
    ++d[i];
    a[i] += a[j];
    if (!a[j]) ++need;
  }
  a[i] += max(0, need);
}

int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    vc<vi> g(n);
    int rt = -1;
    for (int i = 1; i < n; ++i) {
      int u, v;
      cin >> u >> v, --u, --v; 
      g[u].push_back(v);
      g[v].push_back(u);
    }
    for (int i = 0; i < n; ++i) if (g[i].size() > 2) rt = i;
    if (rt == -1) {
      cout << (int) (n > 1) << endl;
      continue;
    }
    vi d(n), a(n);
    dfs(g, rt, -1, d, a);
    cout << a[rt] << endl;
  }
}