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

struct graph {
  vc<vi> adj;
  vc<map<int, ll>> w;

  graph(int n) : adj(n, vi()), w(n, map<int, ll>()) {}
  graph(const graph &g) : adj(g.adj), w(g.w) {}

  void cto(int from, int to, ll weight) {adj[from].pb(to); w[from][to] += weight;}
  void cto(int from, int to) {cto(from, to, 1);}
  void c(int from, int to) {cto(from, to); cto(to, from);}
  void c(int from, int to, ll weight) {cto(from, to, weight); cto(to, from, weight);}

  vi operator[](int u) {return adj[u];}
  vc<vi>::iterator begin() {return adj.begin();}
  vc<vi>::const_iterator begin() const {return adj.begin();}
  vc<vi>::iterator end() {return adj.end();}
  vc<vi>::const_iterator end() const {return adj.end();}
  int size() const {return adj.size();}
};

graph g(100000);
vi l, a;

void leaves(int i, int p) {
  for (int j : g[i]) {
    if (j == p) continue;
    leaves(j, i);
    l[i] += l[j];
  }
  if (!l[i]) l[i] = 1;
}

int dfs(int i, int p) {
  int ret = a[i];
  for (int j : g[i]) {
    if (j == p) continue;
    ret += dfs(j, i);
  }
  return min(ret, l[i]);
}

int main() {
  int n, s; cin >> n >> s; --s;
  vi p(n);
  for (int i = 0; i < n; ++i) {
    cin >> p[i]; --p[i];
  }
  for (int i = 1; i < n; ++i) {
    int u, v; cin >> u >> v; --u; --v;
    g.c(u, v);
  }
  l = vi(n);
  a = vi(n);
  leaves(s, -1);
  for (int i = 0; i < l[s]; ++i) {
    ++a[p[i]];
  }
  cout << dfs(s, -1) << endl;
}
