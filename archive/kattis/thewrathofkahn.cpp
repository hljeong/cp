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
template<class T> bool ckmax(T &a, const T &b) { return a < b ? a = b, 1 : 0; }

const int inf = 1e9 + 7;
const int mod = inf;
const ll infll = 0x3f3f3f3f3f3f3f3fll;

// https://codeforces.com/blog/entry/74977?#comment-594320

struct fsgraph {
  int eid = 2, last_u;
  vi head, nxt, v;
  vll w;

  fsgraph(int n) : head(n), nxt(2), v(2), w(2) {}

  void cto(int from, int to, ll weight) {
    nxt.pb(head[from]); v.pb(to); w.pb(weight);
    head[last_u = from] = eid++;
  }
  
  void cto(int from, int to) {cto(from, to, infll);}
  void rev() {cto(v[eid - 1], last_u, 0);}

  int operator[](int u) {return head[u];}
  vi::iterator begin() {return head.begin();}
  vi::const_iterator begin() const {return head.begin();}
  vi::iterator end() {return head.end();}
  vi::const_iterator end() const {return head.end();}
  int size() const {return head.size();}
};

bool bfs(fsgraph &g, int s, int t, vi &cur, vi &lvl) {
  fill(lvl.begin(), lvl.end(), -1); lvl[s] = 0;
  for (int i = 0; i < g.size(); ++i) cur[i] = g[i];
  queue<int> q; q.push(s);
  while (q.size()) {
    int u = q.front(); q.pop();
    for (int e = g[u]; e; e = g.nxt[e]) {
      int v = g.v[e]; ll w = g.w[e];
      if (w && !~lvl[v]) {
        lvl[v] = lvl[u] + 1;
        q.push(v);
      }
    }
  }
  return ~lvl[t];
}

ll dfs(fsgraph &g, int u, int t, ll f, vi &cur, vi &lvl) {
  if (u == t) return f;
  ll r = f;
  for (int e = cur[u]; e && r; e = g.nxt[e]) {
    cur[u] = e;
    int v = g.v[e]; ll w = g.w[e];
    if (w && lvl[v] == lvl[u] + 1) {
      ll c = dfs(g, v, t, min(w, r), cur, lvl);
      r -= c; g.w[e] -= c; g.w[e ^ 1] += c;
    }
  }
  return f - r;
}

ll dinic(fsgraph &g, int s, int t) {
  ll ans = 0;
  vi lvl(g.size()), cur(g.size());
  while (bfs(g, s, t, cur, lvl)) ans += dfs(g, s, t, infll, cur, lvl);
  return ans;
}

int main() {
  int n, m; cin >> n >> m;
  vc<vll> g(n, vll(n));
  for (int i = 0; i < m; ++i) {
    int u, v; cin >> u >> v;
    g[u][v] = 1;
  }
  for (int k = 0; k < n; ++k) {
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < n; ++j) {
        g[i][j] |= g[i][k] & g[k][j];
      }
    }
  }
  vi indeg(n);
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      if (g[i][j]) ++indeg[j];
    }
  }
  queue<int> q;
  for (int i = 0; i < n; ++i) if (!indeg[i]) q.push(i);
  while (q.size()) {
    int i = q.front(); q.pop();
    for (int j = 0; j < n; ++j) {
      if (g[i][j] && !--indeg[j]) q.push(j);
    }
  }
  int bad = 0;
  for (int i = 0; i < n; ++i) {
    if (indeg[i]) {
      ++bad;
      for (int j = 0; j < n; ++j) {
        g[i][j] = g[j][i] = 0;
      }
    }
  }
  /* 
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      cout << g[i][j] << " \n"[j == n - 1];
    }
  }
  */ 
  fsgraph fg(1 + n + n + 1);
  for (int i = 0; i < n; ++i) {
    fg.cto(0, 1 + i, 1);
    fg.rev();
    for (int j = 0; j < n; ++j) {
      if (g[i][j]) {
        fg.cto(1 + i, 1 + n + j, 1);
        fg.rev();
      }
    }
    fg.cto(1 + n + i, 1 + n + n, 1);
    fg.rev();
  }
  cout << n - bad - dinic(fg, 0, 1 + n + n) << endl;
}
