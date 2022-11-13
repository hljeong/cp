#include <bits/stdc++.h>
#define A first
#define B second
#define vc vector
using namespace std;
using ll = long long; using ld = long double;
using vi = vc<int>; using vll = vc<ll>;
using si = set<int>; using sll = set<ll>;
using pii = pair<int, int>; using mii = map<int, int>;
using gr = vc<vc<pii>>;

template<class T> bool ckmin(T &a, const T &b) { return b < a ? a = b, 1 : 0; }
template<class T> bool ckmax(T &a, const T &b) { return a < b ? a = b, 1 : 0; }

vi indegree(const gr &g) {
  int n = g.size();
  vi indeg(n);
  for (const vc<pii> &adj : g) for (pii e : adj) ++indeg[e.A];
  return indeg;
}

vi kahn(const gr &g, vi &indeg) {
  int n = g.size();
  vi sorted;
  queue<int> q;
  for (int i = 0; i < n; ++i) if (!indeg[i]) q.push(i);
  while (q.size()) {
    int i = q.front(); q.pop();
    sorted.push_back(i);
    for (pii e : g[i]) if (!--indeg[e.A]) q.push(e.A);
  }
  return sorted;
}

vi kahn(const gr &g) {
  vi indeg = indegree(g);
  return kahn(g, indeg);
}

bool kahn_check(const gr &g) {
  int n = g.size();
  vi indeg = indegree(g);
  kahn(g, indeg);
  for (int i = 0; i < n; ++i) if (indeg[i]) return false;
  return true;
}

const int inf = 1e9 + 7;
const int mod = inf;

int main() {
  int n, m; cin >> n >> m;
  vll a(n); for (int i = 0; i < n; ++i) cin >> a[i];
  gr g(n, vc<pii>());
  for (int i = 0; i < m; ++i) {
    int u, v, w; cin >> u >> v >> w;
    g[v].push_back({ u, w });
  }
  vi sorted = kahn(g);
  for (int i : sorted) {
    for (pii e : g[i]) {
      a[e.A] += e.B * a[i];
    }
  }
  for (int i = 0; i < n; ++i) cout << a[i] << " \n"[i == n - 1];
}
