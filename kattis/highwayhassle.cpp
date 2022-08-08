#include <bits/stdc++.h>
#define A first
#define B second
using namespace std;
using ll = long long;

ll inf = 1LL << 60;

int main() {
  int T;
  cin >> T;
  while (T--) {
    int n, m, s, t;
    cin >> n >> m >> s >> t;
    vector<vector<pair<int, ll>>> g(n, vector<pair<int, ll>>());
    for (int i = 0; i < m; ++i) {
      int a, b, f;
      cin >> a >> b >> f;
      --a;
      --b;
      g[a].push_back({b, f});
      g[b].push_back({a, f});
    }
    vector<pair<int, ll>> st(s + 1);
    for (int i = 0; i < s; ++i) {
      cin >> st[i].A >> st[i].B;
      --st[i].A;
    }
    int src, dest;
    cin >> src >> dest;
    --src;
    --dest;
    st[s].A = dest;
    st[s].B = 0;
    for (int i = 0; i <= s; ++i) if (st[i].A == src) src = i;
    vector<vector<ll>> dist(s + 1, vector<ll>(n, inf));
    for (int i = 0; i <= s; ++i) {
      priority_queue<pair<ll, int>> dij;
      dist[i][st[i].A] = 0;
      dij.push({0LL, st[i].A});
      while (dij.size()) {
        auto x = dij.top();
        dij.pop();
        int cur = x.B;
        ll d = -x.A;
        if (d > dist[i][cur]) continue;
        for (auto e : g[cur]) {
          int nxt = e.A;
          ll w = e.B;
          if (dist[i][cur] + w > t) continue;
          if (dist[i][nxt] > dist[i][cur] + w) {
            dist[i][nxt] = dist[i][cur] + w;
            dij.push({-dist[i][nxt], nxt});
          }
        }
      }
    } 
    vector<vector<ll>> ng(s + 1, vector<ll>(s + 1));
    for (int i = 0; i <= s; ++i) {
      for (int j = 0; j <= s; ++j) {
        ng[i][j] = dist[i][st[j].A];
      }
    }
    vector<vector<ll>> dis(s + 1, vector<ll>(s + 1, inf));
    priority_queue<pair<ll, pair<int, int>>> pq;
    dis[src][src] = 0;
    pq.push({0LL, {src, src}});
    while (pq.size()) {
      auto x = pq.top();
      pq.pop();
      ll dista = -x.A;
      int where = x.B.A, last = x.B.B;
      if (dista > dis[where][last]) continue;
      for (int nxt = 0; nxt <= s; ++nxt) {
        ll w = ng[where][nxt];
        if (w >= inf) continue;
        ll ndis = min(dista + st[where].B * w, dista + st[last].B * min(w, t - ng[last][where]) + st[where].B * (w - min(w, t - ng[last][where])));
        if (ndis < dis[nxt][where]) {
          dis[nxt][where] = ndis;
          pq.push({-ndis, {nxt, where}});
        }
      }
    }
    ll ans = inf;
    for (int i = 0; i <= s; ++i) ans = min(ans, dis[s][i]);
    cout << ans << endl;
  }
}