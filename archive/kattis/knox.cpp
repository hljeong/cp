#include <bits/stdc++.h>
#define A first
#define B second
#define vc vector
#define pb push_back
#define endl '\n'
using namespace std;
using ll = long long; using ld = long double;
using vi = vc<int>; using vll = vc<ll>;
using si = set<int>; using sll = set<ll>;
using pi = pair<int, int>; using pll = pair<ll, ll>;
using qi = queue<int>; using mi = map<int, int>;

template<class T> bool ckmin(T &a, const T &b) { return b < a ? a = b, 1 : 0; }
template<class T> bool ckmax(T &a, const T &b) { return a < b ? a = b, 1 : 0; }

const int inf = 1e9 + 7;
const int mod = inf;
const ll infll = 0x3f3f3f3f3f3f3f3fll;
const ld err = 1e-12;
const ld pie = 3.14159265358979;

struct fsgraph {
  int eid = 2, last_u;
  vi head, nxt, v;
  vll w;

  fsgraph(int n) : head(n), nxt(2), v(2), w(2) {}

  void cto(int from, int to, ll weight = infll) {
    nxt.pb(head[from]); v.pb(to); w.pb(weight);
    head[last_u = from] = eid++;
  }
  void rev() { cto(v[eid - 1], last_u, 0); }

  int operator[](int u) { return head[u]; }
  vi::iterator begin() { return head.begin(); }
  vi::const_iterator begin() const { return head.begin(); }
  vi::iterator end() { return head.end(); }
  vi::const_iterator end() const { return head.end(); }
  int size() const { return head.size(); }
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

// binary search + bipartite matching
int main() {
  cin.tie(0) -> sync_with_stdio(0);

  int n; cin >> n;
  vc<pair<ld, ld>> src(n);
  vc<pair<ld, ld>> sink(n);
  for (int i = 0; i < n; ++i) {
    cin >> src[i].A >> src[i].B;
  }
  for (int i = 0; i < n; ++i) {
    cin >> sink[i].A >> sink[i].B;
  }
  vc<vc<ld>> angle(n, vc<ld>(n));
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      pair<ld, ld> s2s = { sink[j].A - src[i].A, sink[j].B - src[i].B };
      // s2s . up = |s2s| cos(theta)
      ld dot_over_mag = s2s.B / sqrt(s2s.A * s2s.A + s2s.B * s2s.B);
      ld theta = acos(dot_over_mag);
      if (theta > pie / 2) theta = pie - theta;
      angle[i][j] = theta;
      // cout << (angle[i][j] * 180 / pie) << " \n"[j == n - 1];
    }
  }

  ld ret = pie / 2;
  ld l = 0, r = pie / 2;
  for (int _ = 0; _ < 80; ++_) {
    ld w = l + (r - l) / 2;
    fsgraph g(1 + n + n + 1);
    for (int i = 0; i < n; ++i) {
      g.cto(0, 1 + i, 1);
      g.rev();
      g.cto(1 + n + i, 1 + n + n, 1);
      g.rev();
    }
    // cout << (w * 180 / pie) << ": ";
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < n; ++j) {
        if (angle[i][j] < w + err) {
          // cout << "(" << i << ", " << j << ") ";
          g.cto(1 + i, 1 + n + j, 1);
          g.rev();
        }
      }
    }
    // cout << endl;
    if (dinic(g, 0, 1 + n + n) == n) {
      ret = r = w;
    } else l = w;
  }

  cout << fixed << setprecision(12) << (2 * ret * 180 / pie) << endl;
}
