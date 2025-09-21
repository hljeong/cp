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
using gr = vc<vi>; using wgr = vc<vc<pii>>;

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

int main() {
  int n, m; cin >> n >> m;
  graph g(n);
  vc<pii> ed(m);
  for (int i = 0; i < m; ++i) {
    int a, b, c; cin >> a >> b >> c;
    ed[i].A = a;
    ed[i].B = b;
    g.c(a, b, c);
  }
  vll d(n);
  vi b(n, -1);
  d[0] = infll;
  priority_queue<pair<ll, int>> pq;
  pq.push({infll, 0});
  while (pq.size()) {
    auto e = pq.top(); pq.pop();
    ll dist = e.A;
    int i = e.B;
    if (dist < d[i]) continue;
    for (int j : g[i]) {
      if (ckmax(d[j], min(d[i], g.w[i][j]))) {
        b[j] = i;
        pq.push({d[j], j});
      }
    }
  }
  si path;
  set<pii> safe;
  int cur = n - 1;
  while (~cur) {
    path.insert(cur);
    if (~b[cur]) {
      safe.insert({cur, b[cur]});
      safe.insert({b[cur], cur});
    }
    cur = b[cur];
  }
  vi ret;
  for (int i = 0; i < ed.size(); ++i) {
    int a = ed[i].A, b = ed[i].B;
    if ((path.count(a) || path.count(b)) && !safe.count(ed[i])) {
      ret.pb(i);
    }
  }
  if (!ret.size()) {
    cout << "none" << endl;
  } else {
    for (int i = 0; i < ret.size(); ++i) cout << ret[i] << " \n"[i == ret.size() - 1];
  }
}
