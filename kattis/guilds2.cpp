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

vi indegree(const gr &g) {
  int n = g.size();
  vi indeg(n);
  for (const vi &adj : g) for (int i : adj) ++indeg[i];
  return indeg;
}

vi kahn(const gr &g, vi &indeg) {
  int n = g.size();
  vi sorted(n);
  queue<int> q;
  for (int i = 0; i < n; ++i) if (!indeg[i]) q.push(i);
  while (q.size()) {
    int i = q.front(); q.pop();
    sorted.push_back(i);
    for (int j : g[i]) if (!--indeg[j]) q.push(j);
  }
  return sorted;
}

vi kahn(const gr &g) {
  vi indeg = indegree(g);
  return kahn(g, indeg);
}

bool kahn_check(const gr &g) {
  int n = g.size();
  vi indeg = indegree(g);
  kahn(g, indeg);
  for (int i = 0; i < n; ++i) if (indeg[i]) return false;
  return true;
}

int mid(int l, int r) { return l + (r - l) / 2; }

void dfs(const gr &g, vc<string> &ans, int i, int p, string s) {
  ans[i] = s;
  for (int j : g[i]) {
    if (j == p) continue;
    dfs(g, ans, j, i, s);
  }
}

int main() {
  int n; cin >> n;
  map<string, int> mp;
  map<int, string> imp;
  vc<pii> es;
  int id = 0;
  for (int i = 0; i < n; ++i) {
    string u, v; cin >> u >> v;
    if (mp.find(u) == mp.end()) {
      imp[id] = u;
      mp[u] = id++;
    }
    if (mp.find(v) == mp.end()) {
      imp[id] = v;
      mp[v] = id++;
    }
    es.push_back({ mp[u], mp[v] });
  }
  gr g(id, vi());
  for (const auto &e : es) {
    g[e.B].push_back(e.A);
  }
  vi sorted = kahn(g), indeg = indegree(g);
  vc<string> ans(id);
  for (int i = 0; i < id; ++i) if (!indeg[i]) {
    dfs(g, ans, i, -1, imp[i]);
  }
  for (const auto &e : es) {
    cout << imp[e.A] << ' ' << ans[e.A] << endl;
  }
}
