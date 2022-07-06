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

// editorial sol

int main() {
  int n, m; cin >> n >> m;
  vc<vi> g(n), rg(n); 
  for (int i = 0; i < m; ++i) {
    int u, v; cin >> u >> v; --u; --v;
    g[u].push_back(v);
    rg[v].push_back(u);
  }
  vi d(n, 1e9 + 7), bad(n);
  d[n - 1] = 0;
  for (int i = 0; i < n; ++i) for (int j : g[i]) ++bad[i];
  priority_queue<pii> pq;
  pq.push({0, n - 1});
  while (pq.size()) {
    pii p = pq.top(); pq.pop(); int i = p.B, dist = -p.A; 
    if (dist > d[i]) continue;
    for (int j : rg[i]) {
      --bad[j];
      if (ckmin(d[j], d[i] + bad[j] + 1)) pq.push({-d[j], j});
    }
  }
  cout << d[0] << endl;
}