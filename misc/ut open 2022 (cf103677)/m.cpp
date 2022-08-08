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

const int maxn = 1005;
int n, m, gn, head[8 * maxn], r[maxn], g[maxn], s[maxn], eid = 2;
ll edges[8 * maxn][3]; 

void add_edge(int u, int v, ll w, int id) {
  edges[id][0] = v;
  edges[id][1] = w;
  edges[id][2] = head[u];
  head[u] = id;
}

bool bfs(vi &lvl, int s, int t, vi &cur) {
  fill(lvl.begin(), lvl.end(), -1);
  lvl[s] = 0;
  for (int i = 0; i < gn; ++i) {
    cur[i] = head[i];
  }
  queue<int> q;
  q.push(s);
  while (q.size()) {
    int p = q.front();
    q.pop();
    for (int eg = head[p]; eg != 0; eg = edges[eg][2]) {
      int to = (int) edges[eg][0];
      ll vol = edges[eg][1];
      if (vol > 0 && lvl[to] == -1) {
        lvl[to] = lvl[p] + 1;
        q.push(to);
      }
    }
  }
  return lvl[t] != -1;
}

ll dfs(int p, ll flow, int t, vi &cur, vi &lvl) {
  if (p == t)
    return flow;
  ll rmn = flow;
  for (int eg = cur[p]; eg != 0 && rmn != 0; eg = edges[eg][2]) {
    cur[p] = eg;
    int to = (int) edges[eg][0];
    ll vol = edges[eg][1];
    if (vol > 0 && lvl[to] == lvl[p] + 1) {
      ll c = dfs(to, min(vol, rmn), t, cur, lvl);
      rmn -= c;
      edges[eg][1] -= c;
      edges[eg ^ 1][1] += c;
    }
  }
  return flow - rmn;
}

ll dinic(int s, int t) {
  ll ans = 0;
  vi lvl(gn), cur(gn);
  while (bfs(lvl, s, t, cur))
    ans += dfs(s, (ll) (1e14 + 7), t, cur, lvl);
  return ans;
}

int main() {
  cin >> n >> m;
  gn = 1 + 2 * n + 1;
  ll ans = 0;
  for (int i = 0; i < n; ++i) {
    cin >> r[i];
    add_edge(0, 1 + 2 * i, r[i], eid++);
    add_edge(1 + 2 * i, 0, 0, eid++);
  }
  for (int i = 0; i < n; ++i) {
    cin >> g[i];
    add_edge(1 + 2 * i + 1, gn - 1, g[i], eid++);
    add_edge(gn - 1, 1 + 2 * i + 1, 0, eid++);
  }
  for (int i = 0; i < m; ++i) {
    int u, v;
    cin >> u >> v >> s[i], --u, --v;
    ans += s[i];

    add_edge(1 + 2 * u, 1 + 2 * v + 1, s[i], eid++);
    add_edge(1 + 2 * v + 1, 1 + 2 * u, 0, eid++);
  }
  cout << ans - dinic(0, gn - 1) << endl;
}