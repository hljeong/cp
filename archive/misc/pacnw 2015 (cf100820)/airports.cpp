#include <bits/stdc++.h>
#define vc vector
using namespace std;
using ll = long long;
using vi = vc<int>;
using vll = vc<ll>;

struct Dinic{
  struct Edge{
    int to, rev;
    ll c, oc;
    ll flow() { return max(oc - c, 0ll); }
  };
  vector<int> lvl, ptr, q;
  vector<vector<Edge>> adj;
  Dinic(int n) : lvl(n), ptr(n), q(n), adj(n) {}
  void addEdge(int a, int b, ll c, ll rcap = 0){
    adj[a].push_back({b, adj[b].size(), c, c});
    adj[b].push_back({a, adj[a].size()-1, rcap, rcap});
  }
  ll dfs(int v, int t, ll f){
    if(v == t || !f) return f;
    for(int& i = ptr[v]; i < adj[v].size(); i++){
      Edge& e = adj[v][i];
      if(lvl[e.to] == lvl[v] + 1)
        if(ll p = dfs(e.to, t, min(f, e.c))){
          e.c -= p, adj[e.to][e.rev].c += p;
          return p;
        }
    }
    return 0;
  }
  ll maxFlow(int s, int t){
    ll flow = 0; q[0] = s;
    for(int L = 0; L < 31; L++) do{
      lvl = ptr = vi(q.size());
      int qi = 0, qe = lvl[s] = 1;
      while(qi < qe && !lvl[t]){
        int v = q[qi++];
        for(Edge e : adj[v])
          if(!lvl[e.to] && e.c >> (30 - L))
            q[qe++] = e.to, lvl[e.to] = lvl[v] + 1;
      }
      while(ll p = dfs(s, t, LLONG_MAX)) flow += p;
    } while(lvl[t]);
    return flow;
  }
};

int main() {
  int n, m; cin >> n >> m;
  vll p(n); for (int i = 0; i < n; ++i) cin >> p[i];
  vc<vll> t(n, vll(n)), d(n, vll(n));
  for (int i = 0; i < n; ++i)
    for (int j = 0; j < n; ++j) {
      cin >> t[i][j];
      d[i][j] = t[i][j];
      if (i != j) {
        t[i][j] += p[j];
        d[i][j] += p[j];
      }
    }
  for (int k = 0; k < n ; ++k)
    for (int i = 0; i < n; ++i)
      for (int j = 0; j < n; ++j)
        if (d[i][k] + d[k][j] < d[i][j])
          d[i][j] = d[i][k] + d[k][j];
  Dinic dinic(1 + m + m + 1);
  vc<array<int, 3>> fl(m);
  for (int i = 0; i < m; ++i) {
    int s, f, ti; cin >> s >> f >> ti; --s; --f;
    fl[i] = {s, f, ti};
  }
  for (int i = 0; i < m; ++i) {
    dinic.addEdge(0, 1 + i, 1);
    dinic.addEdge(1 + m + i, 1 + m + m, 1);
    for (int j = 0; j < m; ++j) {
      // cout << i << ' ' << j << ' ' << fl[j][2] << ' ' << fl[i][2] + t[fl[i][0]][fl[i][1]] + d[fl[i][1]][fl[j][0]] << endl;
      // cout << t[fl[i][0]][fl[i][1]] << ' ' << d[fl[i][1]][fl[j][0]] << endl;
      if (fl[j][2] >= fl[i][2] + t[fl[i][0]][fl[i][1]] + d[fl[i][1]][fl[j][0]]) {
        dinic.addEdge(1 + i, 1 + m + j, 1);
      }
    }
  }
  cout << (m - dinic.maxFlow(0, 1 + m + m)) << endl;
}