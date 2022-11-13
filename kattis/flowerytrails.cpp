#include <bits/stdc++.h>
#define A first
#define B second
#define vc vector
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

vll dijkstra(wgr &g, int src = 0, vi *backtrack = nullptr) {
  int n = g.size();
  vll dist(n, infll);
  priority_queue<pair<ll, int>> pq;
  dist[src] = 0;
  pq.push({0, src});
  while (pq.size()) {
    ll d; int i; tie(d, i) = pq.top(); d = -d; pq.pop();
    if (d > dist[i]) continue;
    for (const auto &e : g[i]) {
      int j = e.A, w = e.B;
      if (ckmin(dist[j], dist[i] + w)) {
        pq.push({-dist[j], j});
        if (backtrack) (*backtrack)[j] = i;
      }
    }
  }
  return dist;
}

int main() {
  int p, t; cin >> p >> t;
  wgr g(p, vc<pii>());
  for (int i = 0; i < t; ++i) {
    int p1, p2, l; cin >> p1 >> p2 >> l;
    g[p1].push_back({p2, l});
    g[p2].push_back({p1, l});
  }
  vll d = dijkstra(g);
  ll ret = 0;
  queue<int> bfs;
  vc<bool> vis(p);
  bfs.push(p - 1);
  vis[p - 1] = true;
  while (bfs.size()) {
    int i = bfs.front(); bfs.pop();
    for (const auto &e : g[i]) {
      int j = e.A, w = e.B;
      if (d[j] + w == d[i]) {
        ret += 2ll * w;
        if (vis[j]) continue;
        vis[j] = true;
        bfs.push(j);
      }
    }
  }
  cout << ret << endl;
}
