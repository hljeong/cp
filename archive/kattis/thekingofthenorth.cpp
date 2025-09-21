#include <bits/stdc++.h>
#define A first
#define B second
#define vc vector
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

using fse = vc<pair<int, pair<int, ll>>>;
using fsgr = pair<vi, pair<fse, int>>;

void add_edge(fsgr &g, int u, int v, ll w) {
  g.B.A[g.B.B].A = g.A[u]; g.B.A[g.B.B].B.A = v; g.B.A[g.B.B].B.B = w;
  g.A[u] = g.B.B++;
}

bool bfs(fsgr &g, int s, int t, vi &cur, vi &lvl) {
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

ll dfs(fsgr &g, int p, int t, ll f, vi &cur, vi &lvl) {
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

ll dinic(fsgr &g, int s, int t) {
  ll ans = 0, inf = 0x3f3f3f3f3f3f3f3fll;
  vi lvl(g.A.size()), cur(g.A.size());
  while (bfs(g, s, t, cur, lvl)) ans += dfs(g, s, t, inf, cur, lvl);
  return ans;
}

const int dx[4] = {-1, 0, 1, 0};
const int dy[4] = {0, 1, 0, -1};

int main() {
  int r, c; cin >> r >> c;
  vc<vi> a(r, vi(c));
  for (int i = 0; i < r; ++i) for (int j = 0; j < c; ++j) cin >> a[i][j];
  int x, y; cin >> x >> y;
  fsgr g = {vi(2 * r * c + 1), {vc<pair<int, pair<int, ll>>>(16 * r * c + 5), 2}};
  auto oob = [&](int i, int j) {
    return i < 0 || r <= i || j < 0 || c <= j;
  };
  for (int i = 0; i < r; ++i) {
    for (int j = 0; j < c; ++j) {
      if (!a[i][j]) continue;
      add_edge(g, 2 * (i * c + j), 2 * (i * c + j) + 1, a[i][j]);
      add_edge(g, 2 * (i * c + j) + 1, 2 * (i * c + j), 0);
      bool sink = false;
      for (int d = 0; d < 4; ++d) {
        int ni = i + dx[d], nj = j + dy[d];
        if (oob(ni, nj)) {
          if (!sink) {
            add_edge(g, 2 * (i * c + j) + 1, 2 * r * c, infll);
            add_edge(g, 2 * r * c, 2 * (i * c + j) + 1, 0);
          }
          sink = true;
          continue;
        }
        add_edge(g, 2 * (i * c + j) + 1, 2 * (ni * c + nj), infll);
        add_edge(g, 2 * (ni * c + nj), 2 * (i * c + j) + 1, 0);
      }
    }
  }
  cout << dinic(g, 2 * (x * c + y), 2 * r * c) << endl;
}
