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
using gr = vc<vi>;

template<class T> bool ckmin(T &a, const T &b) { return b < a ? a = b, 1 : 0; }
template<class T> bool ckmax(T &a, const T &b) { return a < b ? a = b, 1 : 0; }

const int inf = 1e9 + 7;
const int mod = inf;
const ll infll = 0x3f3f3f3f3f3f3f3fll;

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
  int n, m, a, b; cin >> n >> m >> a >> b;
  function<int(int, int)> ind = [&](int i, int j) {
    return i * m + j;
  };
  vi f(n * m);
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      char c; cin >> c;
      f[ind(i, j)] = c != '.';
    }
  }
  fsgraph g(1 + n * m + 1);
  for (int i = 0; i < n * m; ++i) {
    if (f[i]) {
      g.cto(1 + i, 1 + n * m, b);
      g.rev();
    } else {
      g.cto(0, 1 + i, b);
      g.rev();
    }
    int x = i / m, y = i % m;
    if (x < n - 1) {
      g.cto(1 + i, 1 + ind(x + 1, y), a);
      g.cto(1 + ind(x + 1, y), 1 + i, a);
    }
    if (y < m - 1) {
      g.cto(1 + i, 1 + ind(x, y + 1), a);
      g.cto(1 + ind(x, y + 1), 1 + i, a);
    }
  }
  cout << dinic(g, 0, 1 + n * m);
}
