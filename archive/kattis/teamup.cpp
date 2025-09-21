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

int dfs(graph &g, int i, int p, vc<vi> &plr, vi &sz, vc<vi> &ret, int cur) {
  int base = cur + plr[i].size(), nret = 300001;
  for (int j = 0; j < plr[i].size(); ++j) {
    ret[cur + j].pb(plr[i][j]);
  }
  int sum = 0;
  for (int j : g[i]) {
    if (j == p) continue;
    ckmin(nret, dfs(g, j, i, plr, sz, ret, base));
    sum += sz[j];
  }
  if (sum < sz[i]) return base;
  return nret == 300001 ? base : nret;
}

int main() {
  int n, m, p; cin >> n >> m >> p;
  vc<vi> s(m);
  vi sz(m);
  for (int i = 0; i < m; ++i) {
    cin >> sz[i];
    for (int j = 0; j < sz[i]; ++j) {
      int sij; cin >> sij;
      s[i].pb(sij);
    }
  }
  graph g(m);
  mii mp;
  vi ord(m);
  for (int i = 0; i < m; ++i) ord[i] = i;
  sort(ord.begin(), ord.end(), [&](int i, int j) {
    return s[j].size() < s[i].size();
  });
  vi rts;
  for (int i : ord) {
    if (!mp.count(s[i][0])) rts.pb(i);
    else g.c(mp[s[i][0]], i);
    for (int j : s[i]) {
      mp[j] = i;
    }
  }
  vc<vi> plr(m);
  for (int i = 0; i < p; ++i) {
    int cls; cin >> cls; --cls;
    plr[cls].pb(i + 1);
  }
  vc<vi> ret(p);
  int nret = p;
  for (int i : rts) {
    ckmin(nret, dfs(g, i, -1, plr, sz, ret, 0));
  }
  cout << nret << endl;
  for (int i = 0; i < nret; ++i) {
    cout << ret[i].size();
    for (int j : ret[i]) cout << ' ' << j;
    cout << endl;
  }
}
