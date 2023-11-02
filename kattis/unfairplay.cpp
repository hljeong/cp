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
using t4 = array<int, 4>;

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

int main() {
  cin.tie(0) -> sync_with_stdio(0);

  while (true) {
    int n, m, lm = 0; cin >> n;
    if (n == -1) break;
    cin >> m;
    vi p(n); for (int i = 0; i < n; ++i) cin >> p[i];
    vi ret(m);
    vc<t4> mt;
    for (int i = 0; i < m; ++i) {
      int a, b; cin >> a >> b; --a; --b;
      if (a == n - 1) {
        p[a] += 2;
        ret[i] = 0;
      } else if (b == n - 1) {
        p[b] += 2;
        ret[i] = 2;
      } else {
        mt.pb({a, b, i, -1});
        ++lm;
      }
    }
    bool good = true;
    for (int i = 0; i < n - 1; ++i) {
      if (p[n - 1] <= p[i]) {
        good = false;
        break;
      }
    }
    if (!good) {
      cout << "NO" << endl;
      continue;
    }
    fsgraph g(1 + (n - 1) + lm + 1);
    for (int i = 0; i < lm; ++i) {
      g.cto(0, 1 + (n - 1) + i, 2);
      g.rev();
      g.cto(1 + (n - 1) + i, 1 + mt[i][0], infll);
      g.rev();
      g.cto(1 + (n - 1) + i, 1 + mt[i][1], infll);
      mt[i][3] = g.eid;
      g.rev();
    }
    for (int i = 0; i < n - 1; ++i) {
      g.cto(1 + i, 1 + (n - 1) + lm, p[n - 1] - p[i] - 1);
      g.rev();
    }
    if (dinic(g, 0, 1 + (n - 1) + lm) < 2 * lm) {
      cout << "NO" << endl;
      continue;
    }
    for (int i = 0; i < lm; ++i) {
      ret[mt[i][2]] = g.w[mt[i][3]];
    }
    for (int i = 0; i < m; ++i) {
      cout << ret[i] << " \n"[i == m - 1];
    }
  }
}
