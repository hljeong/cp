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

int get(multiset<int> &s) {
  return s.empty() ? 1 : *s.begin() + 1;
}

void solve(graph &g, int i, int p, vc<multiset<int>> &len, multiset<int> &len2) {
  for (int j : g[i]) {
    if (j == p) continue;
    solve(g, j, i, len, len2);
    len[i].insert(get(len[j]));
  }
  if (len[i].size() > 1) len2.insert(*++len[i].begin());
}

int reroot(graph &g, int i, int p, vc<multiset<int>> &len, multiset<int> &len2) {
  int ret = min(get(len[i]), *len2.begin());
  for (int j : g[i]) {
    if (j == p) continue;

    if (len[i].size() > 1) len2.erase(len2.find(*++len[i].begin()));
    len[i].erase(len[i].find(get(len[j])));
    if (len[i].size() > 1) len2.insert(*++len[i].begin());

    if (len[j].size() > 1) len2.erase(len2.find(*++len[j].begin()));
    len[j].insert(get(len[i]));
    if (len[j].size() > 1) len2.insert(*++len[j].begin());

    ckmax(ret, reroot(g, j, i, len, len2));

    if (len[j].size() > 1) len2.erase(len2.find(*++len[j].begin()));
    len[j].erase(len[j].find(get(len[i])));
    if (len[j].size() > 1) len2.insert(*++len[j].begin());

    if (len[i].size() > 1) len2.erase(len2.find(*++len[i].begin()));
    len[i].insert(get(len[j]));
    if (len[i].size() > 1) len2.insert(*++len[i].begin());
  }
  return ret;
}

int main() {
  cin.tie(0) -> sync_with_stdio(0);

  int t; cin >> t;
  while (t--) {
    int n; cin >> n; 
    graph g(n, n - 1);
    vc<multiset<int>> len(n);
    multiset<int> len2;
    len2.insert(inf);
    solve(g, 0, -1, len, len2);
    cout << reroot(g, 0, -1, len, len2) << endl;
  }
}
