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

const int maxn = 3e5 + 5;
const int lift = 20;
vc<vi> anc(maxn, vi(lift));
vi d(maxn);

int lca(int v, int w) {
  if (d[v] > d[w]) swap(v, w);
  for (int i = lift - 1; i >= 0; --i) {
    if (d[w] - (1 << i) >= d[v]) w = anc[w][i];
  }
  if (v == w) return v;
  for (int i = lift - 1; i >= 0; --i) {
    if (anc[v][i] != anc[w][i]) {
      v = anc[v][i];
      w = anc[w][i];
    }
  }
  return anc[v][0];
}

// c is depth of lca
int main() {
  cin.tie(0) -> sync_with_stdio(0);

  int n; cin >> n;
  graph g(n + 1);
  for (int i = 0; i < lift; ++i) anc[0][i] = 0;
  vi val(n + 1), ptr(n + 1);
  for (int i = 1; i <= n; ++i) {
    char t; cin >> t;
    if (t == 'a') {
      int v; cin >> v;
      g.c(i, v);
      val[i] = i;
      ptr[i] = i;
      d[i] = d[ptr[v]] + 1;
      anc[i][0] = ptr[v];
      for (int j = 1; j < lift; ++j) anc[i][j] = anc[anc[i][j - 1]][j - 1];
    } else if (t == 'b') {
      int v; cin >> v;
      ptr[i] = anc[ptr[v]][0];
      cout << val[ptr[v]] << endl;
    } else {
      int v, w; cin >> v >> w;
      ptr[i] = ptr[v];
      cout << d[lca(ptr[v], ptr[w])] << endl;
    }
    // for (int j = 0; j <= n; ++j) cout << val[j] << " \n"[j == n];
    // for (int j = 0; j <= n; ++j) cout << ptr[j] << " \n"[j == n];
  }
}
