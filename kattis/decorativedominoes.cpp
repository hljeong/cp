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
  int n; cin >> n;
  map<int, pii> mp;
  map<pii, int> imp;
  map<pii, pii> nei;
  vi l, r;
  for (int i = 0; i < n; ++i) {
    int x1, y1, x2, y2; cin >> x1 >> y1 >> x2 >> y2;
    pii p1 = {x1, y1}, p2 = {x2, y2}; 
    imp[p1] = i << 1;
    mp[i << 1] = p1;
    imp[p2] = i << 1 | 1;
    mp[i << 1 | 1] = p2;
    nei[p1] = p2;
    nei[p2] = p1;
    if ((x1 + y1) & 1) {
      l.pb(i << 1);
      r.pb(i << 1 | 1);
    } else {
      l.pb(i << 1 | 1);
      r.pb(i << 1);
    }
  }
  fsgraph g(1 + 2 * n + 1);
  for (int i : l) {
    g.cto(0, 1 + i, 1);
    g.rev();
    pii p = mp[i];
    pii up = {p.A, p.B + 1}, right = {p.A + 1, p.B}, down = {p.A, p.B - 1}, left = {p.A - 1, p.B};
    if (up != nei[p] && imp.count(up)) {
      g.cto(1 + i, 1 + imp[up], 1);
      g.rev();
    }
    if (right != nei[p] && imp.count(right)) {
      g.cto(1 + i, 1 + imp[right], 1);
      g.rev();
    }
    if (down != nei[p] && imp.count(down)) {
      g.cto(1 + i, 1 + imp[down], 1);
      g.rev();
    }
    if (left != nei[p] && imp.count(left)) {
      g.cto(1 + i, 1 + imp[left], 1);
      g.rev();
    }
  }
  for (int i : r) {
    g.cto(1 + i, 1 + 2 * n, 1);
    g.rev();
  }
  if (dinic(g, 0, 1 + 2 * n) < n) {
    cout << "impossible" << endl;
    return 0;
  }
  vi ans(2 * n);
  int cur = 0;
  for (int i : l) {
    int u = 1 + i;
    for (int e = g[u]; e; e = g.nxt[e]) {
      if (!g.w[e]) {
        ans[u - 1] = ans[g.v[e] - 1] = cur++;
        break;
      }
    }
  }
  for (int i = 0; i < n; ++i) {
    cout << ans[i << 1] << ' ' << ans[i << 1 | 1] << endl;
  }
}
