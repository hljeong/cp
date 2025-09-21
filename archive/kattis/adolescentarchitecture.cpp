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

void dfs(graph &g, int i, vi &sz, si &cur) {
  sz[i] = 1;
  int ssz = 0;
  cur.insert(i);
  for (int j : g[i]) {
    if (cur.count(j)) continue;
    if (!sz[j]) dfs(g, j, sz, cur);
    ckmax(ssz, sz[j]);
  }
  sz[i] += ssz;
  cur.erase(cur.find(i));
}

void construct(graph &g, int i, vi &sz, vi &ord) {
  ord.pb(i);
  for (int j : g[i]) {
    if (sz[j] == sz[i] - 1) {
      construct(g, j, sz, ord);
      return;
    }
  }
}

int main() {
  int n; cin >> n;
  vc<pii> p(n);
  for (int i = 0; i < n; ++i) {
    string s; int a; cin >> s >> a;
    if (s == "cylinder") p[i] = {0, a};
    else p[i] = {1, a};
  }
  graph g(n);
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      if (i == j) continue;
      if (p[i].A == p[j].A) {
        if (p[i].B >= p[j].B) {
          g.cto(i, j);
        }
      } else if (!p[i].A) {
        int delta = 4 * p[i].B * p[i].B - 2 * p[j].B * p[j].B;
        if (delta >= 0) {
          g.cto(i, j);
        }
      } else {
        int delta = p[i].B - 2 * p[j].B;
        if (delta >= 0) {
          g.cto(i, j);
        }
      }
    }
  }
  vi sz(n);
  si cur;
  int rt = -1;
  for (int i = 0; i < n; ++i) {
    sz.assign(n, 0);
    dfs(g, i, sz, cur);
    if (sz[i] == n) {
      rt = i;
      break;
    }
  }
  if (rt == -1) return !printf("impossible\n");

  vi ord;
  construct(g, rt, sz, ord);
  reverse(ord.begin(), ord.end());
  for (int i : ord) {
    if (!p[i].A) cout << "cylinder ";
    else cout << "cube ";
    cout << p[i].B << endl;
  }
}
