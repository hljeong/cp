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

struct graph {
  vc<vi> adj;
  vc<map<int, ll>> w;

  graph(int n) : adj(n, vi()), w(n, map<int, ll>()) {}
  graph(const graph &g) : adj(g.adj), w(g.w) {}
  graph(int n, int m, int off = 1) : adj(n, vi()), w(n, map<int, ll>()) {
    for (int i = 0, u, v; i < m; ++i) {
      cin >> u >> v; u -= off; v -= off;
      c(u, v);
    }
  }

  void cto(int from, int to, ll weight) { adj[from].pb(to); w[from][to] += weight; }
  void cto(int from, int to) { cto(from, to, 1); }
  void c(int from, int to) { cto(from, to); cto(to, from); }
  void c(int from, int to, ll weight) { cto(from, to, weight); cto(to, from, weight); }

  vi operator[](int u) { return adj[u]; }
  vc<vi>::iterator begin() { return adj.begin(); }
  vc<vi>::const_iterator begin() const { return adj.begin(); }
  vc<vi>::iterator end() { return adj.end(); }
  vc<vi>::const_iterator end() const { return adj.end(); }
  int size() const { return adj.size(); }
};

struct dsu {
  vi par, sz;

  dsu(int n) : par(vi(n)), sz(vi(n)) {
    for (int i = 0; i < n; ++i) { par[i] = i; sz[i] = 1; }
  }

  int find(int i) {
    return par[i] == i ? i : (par[i] = find(par[i]));
  }

  bool combine(int i, int j) {
    i = find(i); j = find(j);
    if (i != j) {
      if (sz[i] < sz[j]) swap(i, j);
      par[j] = i; sz[i] += sz[j];
    }
    return i != j;
  }
};

int dfs(graph &g, int i, int p, vi &v, vi &c) {
  // cout << "dfs: " << (i + 1) << ", " << (p + 1) << endl;
  int ret = -1;
  v[i] = 1;
  for (int j : g[i]) {
    if (j == p) continue;
    if (v[j]) {
      if (c[i] == -1) {
        // cout << "cycle: " << (i + 1) << ", " << (j + 1) << endl;
        c[i] = ret = j;
      }
      continue;
    }
    int cret = dfs(g, j, i, v, c);
    if (cret != -1) {
      c[i] = cret;
      if (cret != i) ret = cret;
    }
  }
  return ret;
}

int dfs2(graph &g, int i, vi &v, vi &c, vi &p) {
  int cnt = 0;
  v[i] = 1;
  for (int j : g[i]) {
    if (v[j]) continue;
    int cret = dfs2(g, j, v, c, p);
    if (c[i] == -1 && cret != -1) p[i] = cret;
    ++cnt;
  }
  if (!cnt && c[i] == -1) p[i] = i;
  return p[i];
}

void dfs3(graph &g, int i, vi &c, vi &cid, vc<vll> &cd, ll d = 0) {
  // cout << "dfs3: " << (i + 1) << endl << flush;
  cd[c[i]].pb(d);
  for (int j : g[i]) {
    if (c[j] != c[i] || cid[j] != -1) continue;
    cid[j] = cid[i] + 1;
    dfs3(g, j, c, cid, cd, d + g.w[i][j]);
  }
}

void dfs4(graph &g, int i, vi &p, vi &pid, vc<vll> &pd, ll d = 0) {
  // cout << "dfs4: " << (i + 1) << endl << flush;
  if (p[i] == -1) return;
  for (int j : g[i]) {
    if (pid[j] != -1) continue;
    pid[j] = pid[i] + 1;
    pd[p[i]].pb(d);
    dfs4(g, j, p, pid, pd, d + g.w[i][j]);
  }
}

int main() {
  cin.tie(0) -> sync_with_stdio(0);

  int n; cin >> n;
  graph g(n);
  dsu d(n);
  for (int i = 0; i < n; ++i) {
    int j, t; cin >> j >> t; --j;
    g.c(i, j, t);
    d.combine(i, j);
  }
  vi v(n), c(n, -1), p(n, -1), cofp(n, -1), cofpat(n, -1);
  for (int i = 0; i < n; ++i) {
    if (!v[i]) dfs(g, i, -1, v, c);
  }
  // for (int i = 0; i < n; ++i) cout << (c[i] + 1) << " \n"[i == n - 1];
  // cout << flush;
  fill(v.begin(), v.end(), 0);
  for (int i = 0; i < n; ++i) {
    if (c[i] == i) {
      dfs2(g, i, v, c, p);
    }
  }
  vi cid(n, -1), pid(n, -1);
  vc<vll> cd(n), pd(n);
  for (int i = 0; i < n; ++i) {
    if (c[i] == i) {
      cid[i] = 0;
      dfs3(g, i, c, cid, cd);
    } else if (p[i] == i) {
      pid[i] = 0;
      pd[p[i]].pb(0);
      dfs4(g, i, p, pid, pd);
    }
  }
  // for (int i = 0; i < n; ++i) cout << cid[i] << " \n"[i == n - 1];
  // for (int i = 0; i < n; ++i) cout << pid[i] << " \n"[i == n - 1];
  // cout << flush;
  for (int i = 0; i < n; ++i) {
    if (c[i] != -1) {
      for (int j : g[i]) {
        if (p[j] != -1) {
          cofp[p[j]] = c[i];
          cofpat[p[j]] = i;
        }
      }
    }
  }
  auto pathd = [&](int a, int b) {
    if (pid[a] > pid[b]) swap(a, b);
    int path = p[a];
    return pd[path][pid[b] + 1] - pd[path][pid[a]];
  };
  auto cycd = [&](int a, int b) {
    if (cid[a] > cid[b]) swap(a, b);
    int cyc = c[a];
    ll dist = cd[cyc][cid[b]] - cd[cyc][cid[a]];
    return min(dist, cd[cyc].back() - dist);
  };
  int q; cin >> q;
  while (q--) {
    int a, b; cin >> a >> b; --a; --b;
    if (d.find(a) != d.find(b)) {
      cout << -1 << endl;
      continue;
    }
    if (c[a] == -1) swap(a, b);
    if (c[a] != -1) {
      if (c[b] != -1) {
        // both in cycle
        cout << "both in cycle" << endl;
        cout << cycd(a, b) << endl;
      } else {
        // one on path
        cout << "one on path" << endl;
        int u = cofpat[b];
        cout << (pathd(b, u) + cycd(u, a)) << endl;
      }
    } else if (p[a] != p[b]) {
      // on diff path
      cout << "on diff path" << endl;
      int u = cofpat[a], v = cofpat[b];
      cout << (pathd(a, u) + cycd(u, v) + pathd(v, b)) << endl;
    } else {
      // on same path
      cout << "on same path" << endl;
      cout << pathd(a, b) << endl;
    }
  }
}
