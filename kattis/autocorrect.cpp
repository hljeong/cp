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
template<class T> bool ckmax(T &a, const T &b) { return b > a ? a = b, 1 : 0; }

const int inf = 1e9 + 7;
const int mod = inf;
const ll infll = 0x3f3f3f3f3f3f3f3fll;

int main() {
  int n, m; cin >> n >> m;
  vc<string> ac(n), tp(m);
  for (int i = 0; i < n; ++i) cin >> ac[i];
  for (int i = 0; i < m; ++i) cin >> tp[i];
  int s = 1;
  vc<map<char, int>> tr(s);
  vi cor(s, -1), len(s, -1);
  mii prio;
  for (int i = 0; i < n; ++i) {
    int cur = 0;
    for (char c : ac[i]) {
      if (!tr[cur].count(c)) {
        tr[cur][c] = s++;
        tr.pb(map<char, int>());
        cor.pb(-1);
        len.pb(-1);
      }
      cur = tr[cur][c];
    }
    cor[cur] = cur;
    prio[cur] = m - i;
    len[cur] = ac[i].length();
  }
  vi tpi(m);
  for (int i = 0; i < m; ++i) {
    int cur = 0;
    for (char c : tp[i]) {
      if (!tr[cur].count(c)) {
        tr[cur][c] = s++;
        tr.pb(map<char, int>());
        cor.pb(-1);
        len.pb(-1);
      }
      cur = tr[cur][c];
    }
    tpi[i] = cur;
  }
  vc<vi> anc(s, vi(20));
  vi dep(s);
  function<void(int, int)> dfs = [&](int i, int p) {
    anc[i][0] = p;
    for (const auto &e : tr[i]) {
      int j = e.B;
      dep[j] = dep[i] + 1;
      dfs(j, i);
      if (cor[j] != -1 && (cor[i] == -1 || prio[cor[j]] > prio[cor[i]])) cor[i] = cor[j];
    }
  };
  dfs(0, 0);
  function<void(int)> lift = [&](int i) {
    for (int j = 1; j < 20; ++j) {
      anc[i][j] = anc[anc[i][j - 1]][j - 1];
    }
    for (const auto &e : tr[i]) {
      int j = e.B;
      lift(j);
    }
  };
  lift(0);
  function<int(int, int)> lca = [&](int u, int v) {
    if (dep[u] < dep[v]) swap(u, v);
    for (int i = 19; i >= 0; --i) {
      if (dep[anc[u][i]] >= dep[v]) u = anc[u][i];
    }
    for (int i = 19; i >= 0; --i) {
      if (anc[u][i] != anc[v][i]) {
        u = anc[u][i];
        v = anc[v][i];
      }
    }
    return u != v ? anc[u][0] : u;
  };
  for (int i = 0; i < m; ++i) {
    int l = tp[i].length();
    vi dp(l + 1, l);
    dp[l] = 0;
    for (int j = l - 1, cur = anc[tpi[i]][0]; j > 0; --j) {
      if (cor[cur] == -1) {
        dp[j] = l - j;
        cur = anc[cur][0];
        continue;
      }
      int lcp = dep[lca(tpi[i], cor[cur])];
      dp[j] = min(1 + dp[j + 1], 1 + (len[cor[cur]] - lcp) + dp[lcp]);
      // cout << tp[i].substr(0, j) << " -> " << len[cor[cur]] << ", " << lcp << endl;
      // cout << j << ": " << dp[j] << endl;
      cur = anc[cur][0];
    }
    cout << (1 + dp[1]) << endl;
  }
}