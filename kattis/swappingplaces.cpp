#include <bits/stdc++.h>
#define A first
#define B second
#define vc vector
using namespace std;
using ll = long long; using ld = long double;
using vi = vc<int>; using vll = vc<ll>;
using si = set<int>; using sll = set<ll>;
using pii = pair<int, int>; using mii = map<int, int>;

template<class T> bool ckmin(T &a, const T &b) { return b < a ? a = b, 1 : 0; }
template<class T> bool ckmax(T &a, const T &b) { return a < b ? a = b, 1 : 0; }

const int inf = 1e9 + 7;
const int mod = inf;

using dsu = pair<vi, vi>;

dsu make_dsu(int n) {
  dsu d = { vi(n), vi(n) };
  for (int i = 0; i < n; ++i) {
    d.A[i] = i;
    d.B[i] = 1;
  }
  return d;
}

int find(dsu &d, int i) {
  return d.A[i] == i ? i : (d.A[i] = find(d, d.A[i]));
}

bool combine(dsu &d, int i, int j) {
  i = find(d, i); j = find(d, j);
  if (i != j) {
    if (d.B[i] < d.B[j]) swap(i, j);
    d.A[j] = i; d.B[i] += d.B[j];
    return true;
  }
  return false;
}

int main() {
  int n, m; scanf("%d %d", &n, &m);
  vc<vi> g(n, vi());
  vi s(n), deg(n), cur(n), icur(n);
  for (int i = 0; i < n; ++i) cur[i] = icur[i] = i;
  dsu d = make_dsu(n);
  for (int i = 0; i < m; ++i) {
    int u, v; scanf("%d %d", &u, &v); --u; --v;
    g[u].push_back(v);
    g[v].push_back(u);
    combine(d, u, v);
    ++deg[u];
    ++deg[v];
  }
  bool good = true;
  for (int i = 0; i < n; ++i) {
    scanf("%d", &s[i]); --s[i];
    good &= find(d, s[i]) == find(d, i);
  }
  if (!good) {
    cout << "impossible" << endl;
    return 0;
  }
  vc<pii> ans;
  vi p(n);
  set<pii> q;
  vc<bool> vis(n);
  queue<int> bfs;
  for (int i = 0; i < n; ++i) {
    q.insert({ deg[i], i });
  }
  while (q.size()) {
    pii e = *q.begin(); int i = e.B;
    q.erase(q.begin());
    fill(p.begin(), p.end(), -1);
    p[i] = i;
    bfs.push(i);
    int cnt = 0;
    while (bfs.size()) {
      int j = bfs.front(); bfs.pop();
      for (int k : g[j]) {
        if (vis[k] || ~p[k]) continue;
        p[k] = j;
        bfs.push(k);
      }
    }
    int pos = icur[s[i]];
    while (pos != i) {
      int nxt = p[pos];
      ans.push_back({ cur[pos] + 1, cur[nxt] + 1 });
      swap(icur[cur[pos]], icur[cur[nxt]]);
      swap(cur[pos], cur[nxt]);
      pos = nxt;
    }
    vis[i] = true;
    for (int j : g[i]) {
      if (vis[j]) continue;
      q.erase(q.find({ deg[j]--, j }));
      q.insert({ deg[j], j });
    }
  }
  printf("%d\n", (int) ans.size());
  for (auto const &e : ans) {
    printf("%d %d\n", e.A, e.B);
  }
}
