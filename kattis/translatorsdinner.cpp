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

// official sol
// https://2016.bapc.eu/media/filer_public/2016/09/30/bapc2016-preliminaries-solutions.pdf

using dsu = pair<vi, vi>;

int find(dsu &d, int i) {
  return d.A[i] == i ? i : (d.A[i] = find(d, d.A[i]));
}

bool unite(dsu &d, int i, int j) {
  i = find(d, i); j = find(d, j);
  if (i != j) {
    if (d.B[i] < d.B[j]) swap(i, j);
    d.A[j] = i; d.B[i] += d.B[j];
    return true;
  }
  return false;
}

int main() {
  int n, m; cin >> n >> m;
  vc<set<int>> g(n), t(n);
  map<pii, int> p2i;
  dsu d = {vi(n), vi(n, 1)};
  iota(d.A.begin(), d.A.end(), 0);
  for (int i = 0; i < m; ++i) {
    int u, v; cin >> u >> v;
    p2i[{u, v}] = p2i[{v, u}] = i;
    g[u].insert(v);
    g[v].insert(u);
    if (unite(d, u, v)) {
      t[u].insert(v);
      t[v].insert(u);
    }
  }
  // has to be stack not queue??? why???
  stack<int> q; vc<pii> ans;
  for (int i = 0; i < n; ++i) if (t[i].size() == 1) q.push(i);
  while (q.size()) {
    int i = q.top(); q.pop();
    if (t[i].size() != 1) continue;
    else if (g[i].size() == 1) {
      int j = *(g[i].begin());
      t[i].clear(); t[j].erase(i);
      if (t[j].size() == 1) q.push(j);
    } else if (g[i].size() == 2) {
      auto it = g[i].begin();
      int a = *(it++), b = *it, j = *(t[i].begin());
      ans.push_back({p2i[{i, a}], p2i[{i, b}]});
      g[i].clear(); g[a].erase(i); g[b].erase(i);
      t[i].clear(); t[j].erase(i);
      if (t[j].size() == 1) q.push(j);
    } else {
      auto it = g[i].begin();
      int a, b, te = *(t[i].begin());
      if ((*it) == te) ++it;
      a = *(it++);
      if ((*it) == te) ++it;
      b = *it;
      ans.push_back({p2i[{i, a}], p2i[{i, b}]});
      g[i].erase(a); g[i].erase(b); g[a].erase(i); g[b].erase(i);
      q.push(i);
    }
  }
  if (2 * ans.size() < m) cout << "impossible" << endl;
  else for (pii p : ans) cout << p.A << ' ' << p.B << endl;
}



/* using fse = vc<pair<int, pair<int, ll>>>;
using fsg = pair<vi, pair<fse, int>>;

void add_edge(fsg &g, int u, int v, ll w) {
  g.B.A[g.B.B].A = g.A[u]; g.B.A[g.B.B].B.A = v; g.B.A[g.B.B].B.B = w;
  g.A[u] = g.B.B++;
}

bool bfs(fsg &g, int s, int t, vi &cur, vi &lvl) {
  fill(lvl.begin(), lvl.end(), -1); lvl[s] = 0;
  for (int i = 0; i < g.A.size(); ++i) cur[i] = g.A[i];
  queue<int> q; q.push(s);
  while (q.size()) {
    int p = q.front(); q.pop();
    for (int e = g.A[p]; e; e = g.B.A[e].A) {
      int to = g.B.A[e].B.A; ll v = g.B.A[e].B.B;
      if (v && lvl[to] == -1) {
        lvl[to] = lvl[p] + 1;
        q.push(to);
      }
    }
  }
  return lvl[t] != -1;
}

ll dfs(fsg &g, int p, int t, ll f, vi &cur, vi &lvl) {
  if (p == t) return f;
  ll r = f;
  for (int e = cur[p]; e && r; e = g.B.A[e].A) {
    cur[p] = e;
    int to = g.B.A[e].B.A; ll v = g.B.A[e].B.B;
    if (v && lvl[to] == lvl[p] + 1) {
      ll c = dfs(g, to, t, min(v, r), cur, lvl);
      r -= c; g.B.A[e].B.B -= c; g.B.A[e ^ 1].B.B += c;
    }
  }
  return f - r;
}

ll dinic(fsg &g, int s, int t) {
  ll ans = 0, inf = 0x3f3f3f3f3f3f3f3fll;
  vi lvl(g.A.size()), cur(g.A.size());
  while (bfs(g, s, t, cur, lvl)) ans += dfs(g, s, t, inf, cur, lvl);
  return ans;
}

int main() {
  int n, m; cin >> n >> m;
  fsg g = {vi(2 * m + 2), {fse(4 * m + 4 * m * n), 2}};
  vc<pii> t(m);
  for (int i = 0; i < m; ++i) {
    cin >> t[i].A >> t[i].B;
    add_edge(g, 0, 1 + i, 1); add_edge(g, 1 + i, 0, 0);
    add_edge(g, 1 + m + i, 1 + m + m, 1); add_edge(g, 1 + m + m, 1 + m + i, 0);
    for (int j = 0; j < i; ++j) {
      if (t[i].A == t[j].A || t[i].A == t[j].B || t[i].B == t[j].A || t[i].B == t[j].B) {
        add_edge(g, 1 + j, 1 + m + i, 1); add_edge(g, 1 + m + i, 1 + j, 0);
      }
    }
  }
  int match = (int) dinic(g, 0, 1 + m + m);
  if (!(m & 1) && 2 * match >= m) {
    vc<pii> ans; set<int> seen;
    for (int i = 0; i < m; ++i) {
      if (seen.find(i) != seen.end()) continue;
      seen.insert(i);
      for (int e = g.A[1 + i]; e; e = g.B.A[e].A) {
        int to = g.B.A[e].B.A; ll v = g.B.A[e].B.B;
        if (!to) continue;
        if (!v && seen.find(to - (1 + m)) == seen.end()) {
          ans.push_back({i, to - (1 + m)});
          seen.insert(to - (1 + m));
        }
      }
    }
    for (pii p : ans) cout << p.A << ' ' << p.B << endl;
  } else cout << "impossible" << endl;
} */



/* const int maxn = 205;
int n, m, gn, head[3 * maxn], edges[16 * maxn][3], eid = 2; 

void add_edge(int u, int v, int w, int id) {
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
      int vol = edges[eg][1];
      if (vol > 0 && lvl[to] == -1) {
        lvl[to] = lvl[p] + 1;
        q.push(to);
      }
    }
  }
  return lvl[t] != -1;
}

int dfs(int p, int flow, int t, vi &cur, vi &lvl) {
  if (p == t)
    return flow;
  int rmn = flow;
  for (int eg = cur[p]; eg && rmn; eg = edges[eg][2]) {
    cur[p] = eg;
    int to = (int) edges[eg][0];
    int vol = edges[eg][1];
    if (vol > 0 && lvl[to] == lvl[p] + 1) {
      int c = dfs(to, min(vol, rmn), t, cur, lvl);
      rmn -= c;
      edges[eg][1] -= c;
      edges[eg ^ 1][1] += c;
    }
  }
  return flow - rmn;
}

int dinic(int s, int t) {
  int ans = 0;
  vi lvl(gn), cur(gn);
  while (bfs(lvl, s, t, cur))
    ans += dfs(s, gn, t, cur, lvl);
  return ans;
}

int main() {
  cin >> n >> m;
  gn = 2 + 2 * m;
  map<int, set<int>> l2p;
  for (int i = 0; i < m; ++i) {
    int a, b;
    cin >> a >> b;
    l2p[a].insert(i);
    l2p[b].insert(i);
  }
  for (int i = 0; i < n; ++i) {
    for (int j : l2p[i]) {
      for (int k : l2p[i]) if (j != k) {
        add_edge(1 + j, 1 + m + k, 1, eid++);
        add_edge(1 + m + k, 1 + j, 0, eid++);
      }
    }
  }
  for (int i = 0; i < m; ++i) {
    add_edge(0, 1 + i, 1, eid++);
    add_edge(1 + i, 0, 0, eid++);
    add_edge(1 + m + i, 1 + m + m, 1, eid++);
    add_edge(1 + m + m, 1 + m + i, 0, eid++);
  }
  int match = dinic(0, 1 + m + m); 
  if (match != m || m & 1) {
    cout << "impossible" << endl;
  } else {
    vc<bool> used(m); 
    for (int i = 0; i < m; ++i) {
      if (!used[i]) {
        for (int eg = head[1 + i]; eg; eg = edges[eg][2]) {
          if (!edges[eg][1] && edges[eg][0] >= 1 + m && !used[edges[eg][0] - (1 + m)]) {
            cout << i << ' ' << edges[eg][0] - (1 + m) << endl;
            used[i] = used[edges[eg][0] - (1 + m)] = true;
            break;
          }
        }
      }
    }
  }
} */