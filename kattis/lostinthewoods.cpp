#include <bits/stdc++.h>
#define A first
#define B second
#define vc vector
#define pb push_back
using namespace std;
using ll = long long; using ld = long double;
using vi = vc<int>; using vll = vc<ll>;
using si = set<int>; using sll = set<ll>;
using pii = pair<int, int>; using pll = pair<ll, ll>;
using mii = map<int, int>;

template<class T> bool ckmin(T &a, const T &b) { return b < a ? a = b, 1 : 0; }
template<class T> bool ckmax(T &a, const T &b) { return a < b ? a = b, 1 : 0; }

const int inf = 1e9 + 7;
const int mod = inf;
const ll infll = 0x3f3f3f3f3f3f3f3fll;

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
  int n, m; cin >> n >> m;
  vc<vi> g(n);
  for (int i = 0; i < m; ++i) {
    int k, l; cin >> k >> l;
    g[k].pb(l);
    g[l].pb(k);
  }
  vc<vc<ld>> coeff(n, vc<ld>(n + 1));
  for (int i = 0; i < n - 1; ++i) {
    int cnt = g[i].size();
    for (int j : g[i]) 
      coeff[i][j] = 1.0l / cnt;
    coeff[i][i] = coeff[i][n] = -1;
  }
  coeff[n - 1][n - 1] = 1;
  vc<ld> ret(n);
  gauss(coeff, ret);
  cout << setprecision(12) << fixed <<  ret[0] << endl;
}
