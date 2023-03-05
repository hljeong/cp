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
const int mod = 1e9 + 9;
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

int ghash(graph &g, int i, int p, vll &h, vll &pbase) {
  priority_queue<pair<int, ll>> sorted;
  for (int j : g[i]) {
    if (j == p) continue;
    int len = ghash(g, j, i, h, pbase);
    sorted.push({len, h[j]});
  }
  int len = 0;
  while (sorted.size()) {
    auto [slen, hsh] = sorted.top(); sorted.pop();
    h[i] = (h[i] * pbase[1] + 1) % mod;
    h[i] = (h[i] * pbase[slen] + hsh) % mod;
    h[i] = (h[i] * pbase[1] + 0) % mod;
    len += 1 + slen + 1;
  }
  return len;
}

bool check(graph &g, int i, int p, vll &h1, vll &h2) {
  map<pll, int> f;
  for (int j : g[i]) {
    if (j == p) continue;
    ++f[{h1[j], h2[j]}];
  }
  int ocnt = 0;
  for (int j : g[i]) {
    if (j == p) continue;
    if (f[{h1[j], h2[j]}] & 1) {
      if (++ocnt > f[{h1[j], h2[j]}] || !check(g, j, i, h1, h2)) return false;
    }
  }
  return true;
}

int main() {
  cin.tie(0) -> sync_with_stdio(0);

  int b1 = 2, b2 = 3;
  vll pbase1(2000005), pbase2(2000005);
  pbase1[0] = pbase2[0] = 1;
  for (int i = 1; i < 2000005; ++i) {
    pbase1[i] = pbase1[i - 1] * b1 % mod;
    pbase2[i] = pbase2[i - 1] * b2 % mod;
  }

  int t; cin >> t;
  while (t--) {
    int n; cin >> n;
    graph g(n, n - 1);
    vll h1(n), h2(n);
    ghash(g, 0, -1, h1, pbase1);
    ghash(g, 0, -1, h2, pbase2);
    cout << (check(g, 0, -1, h1, h2) ? "YES" : "NO") << endl;
  }
}
