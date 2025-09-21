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

int gauss(vc<vc<ld>> c, vc<ld> &ret) {
  int n = c.size(), m = c[0].size() - 1;

  vi where(m, -1);
  for (int var = 0, row = 0; var < m && row < n; ++var) {
    int cur = row;
    for (int i = row; i < n; ++i)
      if (fabs(c[i][var]) > fabs(c[cur][var])) 
        cur = i;
    if (fabs(c[cur][var]) < 1e-9) continue;
    swap(c[cur], c[row]);
    where[var] = row;

    for (int i = 0; i < n; ++i) {
      if (i == row) continue;
      ld mult = c[i][var] / c[row][var];
      for (int j = var; j <= m; ++j) c[i][j] -= mult * c[row][j];
    }
    ++row;
  }

  ret.assign(m, 0);
  for (int i = 0; i < m; ++i)
    if (where[i] != -1)
      ret[i] = c[where[i]][m] / c[where[i]][i];
  for (int i = 0; i < n; ++i) {
    ld sum = 0;
    for (int j = 0; j < m; ++j)
      sum += ret[j] * c[i][j];
    if (fabs(sum - c[i][m]) > 1e-9) return 0;
  }

  for (int i = 0; i < m; ++i)
    if (where[i] == -1) return -1;

  return 1;
}

int main() {
  cin.tie(0) -> sync_with_stdio(0);

  int l, w, cnt = 0; cin >> l >> w;
  string _;
  getline(cin, _);
  vc<string> m(l);
  vc<vc<ld>> p(l, vc<ld>(w));
  map<pi, int> id;
  int ent = -1, dst = -1;
  for (int i = 0; i < l; ++i) {
    getline(cin, m[i]);
    for (int j = 0; j < w; ++j) {
      if (m[i][j] == ' ') {
        id[{i, j}] = cnt++;
      } else if (m[i][j] == 'E') {
        ent = i * w + j;
      } else if (m[i][j] == 'D') {
        dst = i * w + j;
      } else p[i][j] = 1;
    }
  }
  
  vc<vc<ld>> mat(cnt + 1, vc<ld>(cnt + 1));
  for (int i = 0; i < l; ++i) {
    for (int j = 0; j < w; ++j) {
      if (id.count({i, j})) {
        int cur = id[{i, j}], tot = 0;
        if (id.count({i - 1, j})) {
          ++mat[cur][id[{i - 1, j}]];
          ++tot;
        }
        if (id.count({i, j - 1})) {
          ++mat[cur][id[{i, j - 1}]];
          ++tot;
        }
        if (id.count({i + 1, j})) {
          ++mat[cur][id[{i + 1, j}]];
          ++tot;
        }
        if (id.count({i, j + 1})) {
          ++mat[cur][id[{i, j + 1}]];
          ++tot;
        }
        if (tot) {
          for (int k = 0; k < cnt; ++k) mat[cur][k] /= tot;
        }
        mat[cur][cur] -= 1;
      }
    }
  }
  for (int i = 0; i < cnt; ++i) {
    for (int j = 0; j < i; ++j) {
      swap(mat[i][j], mat[j][i]);
    }
  }
  for (int i = 0; i <= cnt; ++i) mat[cnt][i] = 1;
  vc<ld> eq(cnt);
  gauss(mat, eq);
  for (int i = 0; i < l; ++i) {
    for (int j = 0; j < w; ++j) {
      if (id.count({i, j})) p[i][j] = eq[id[{i, j}]];
    }
  }
  vc<vc<ld>> dist(l, vc<ld>(w, 1));
  dist[ent / w][ent % w] = 0;
  priority_queue<pair<ld, int>> pq;
  pq.push({0, ent});
  while (pq.size()) {
    auto [ prob, cur ] = pq.top(); pq.pop();
    prob = -prob;
    int x = cur / w, y = cur % w;
    if (dist[x][y] < prob) continue;
    if (cur == dst) break;
    if (x && ckmin(dist[x - 1][y], dist[x][y] + p[x - 1][y])) {
      pq.push({-dist[x - 1][y], (x - 1) * w + y});
    }
    if (y && ckmin(dist[x][y - 1], dist[x][y] + p[x][y - 1])) {
      pq.push({-dist[x][y - 1], x * w + (y - 1)});
    }
    if (x < l - 1 && ckmin(dist[x + 1][y], dist[x][y] + p[x + 1][y])) {
      pq.push({-dist[x + 1][y], (x + 1) * w + y});
    }
    if (y < w - 1 && ckmin(dist[x][y + 1], dist[x][y] + p[x][y + 1])) {
      pq.push({-dist[x][y + 1], x * w + (y + 1)});
    }
  }
  cout << dist[dst / w][dst % w] << endl;
}
