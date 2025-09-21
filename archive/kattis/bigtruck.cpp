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

int main() {
  int n; cin >> n;
  vi t(n); for (int i = 0; i < n; ++i) cin >> t[i];
  int m; cin >> m;
  vc<vc<pii>> g(n);
  for (int i = 0; i < m; ++i) {
    int a, b, d; cin >> a >> b >> d; --a; --b;
    g[a].pb({b, d});
    g[b].pb({a, d});
  }
  priority_queue<pii> q;
  vi dist(n, inf);
  dist[0] = 0;
  q.push({0, 0});
  while (q.size()) {
    pii p = q.top(); q.pop();
    int u = p.A;
    if (p.B > dist[u]) continue;
    for (pii e : g[u]) {
      int v = e.A, w = e.B;
      if (ckmin(dist[v], dist[u] + w)) {
        q.push({v, dist[v]});
      }
    }
  }
  if (dist[n - 1] == inf) {
    cout << "impossible" << endl;
    return 0;
  }
  vc<vi> dag(n);
  for (int u = 0; u < n; ++u) {
    for (pii e : g[u]) {
      int v = e.A, w = e.B;
      if (dist[v] == dist[u] + w) {
        dag[u].pb(v);
      }
    }
  }
  vi dp(n), order(n);
  dp[0] = t[0];
  for (int i = 0; i < n; ++i) order[i] = i;
  sort(order.begin(), order.end(), [&](int u, int v) {return dist[u] < dist[v];});
  for (int u : order) {
    for (int v : dag[u]) ckmax(dp[v], dp[u] + t[v]);
  }
  cout << dist[n - 1] << ' ' << dp[n - 1] << endl;
}
