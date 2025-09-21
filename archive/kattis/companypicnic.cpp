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

using ar = array<pii, 2>;

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

void dfs(graph &g, int i, int p, vc<ar> &dp, vi &s) {
  for (int j : g[i]) {
    if (j == p) continue;
    dfs(g, j, i, dp, s);
    dp[i][0].A += dp[j][1].A;
    dp[i][0].B += dp[j][1].B;
    if (ckmax(dp[i][1].A, dp[j][0].A + 1 - dp[j][1].A)) {
      dp[i][1].B = dp[j][0].B + min(s[i], s[j]) - dp[j][1].B;
    } else if (dp[i][1].A == dp[j][0].A + 1 - dp[j][1].A) {
      ckmax(dp[i][1].B, dp[j][0].B + min(s[i], s[j]) - dp[j][1].B);
    }
  }
  dp[i][1].A += dp[i][0].A;
  dp[i][1].B += dp[i][0].B;
}

int main() {
  int n; cin >> n;
  graph g(n);
  map<string, int> mp; int mid = 0, rt = -1;
  vi s(n);
  for (int i = 0; i < n; ++i) {
    string u, p; ld spd; cin >> u >> spd >> p;
    if (!mp.count(u)) mp[u] = mid++;
    s[mp[u]] = (int) round(spd * 1000);
    if (p == "CEO") {
      rt = mp[u];
    } else {
      if (!mp.count(p)) mp[p] = mid++;
      g.c(mp[u], mp[p]);
    }
  }
  vc<ar> dp(n);
  dfs(g, rt, -1, dp, s);
  cout << dp[rt][1].A << ' ' << (ld) dp[rt][1].B / dp[rt][1].A / 1000 << endl;
}
