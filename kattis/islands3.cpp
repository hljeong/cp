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

void dfs(int i, int j, vc<string> &mp, int n, int m) {
  mp[i][j] = 'W';
  if (i) {
    if (mp[i - 1][j] != 'W') dfs(i - 1, j, mp, n, m);
  }
  if (j) {
    if (mp[i][j - 1] != 'W') dfs(i, j - 1, mp, n, m);
  }
  if (i < n - 1) {
    if (mp[i + 1][j] != 'W') dfs(i + 1, j, mp, n, m);
  }
  if (j < m - 1) {
    if (mp[i][j + 1] != 'W') dfs(i, j + 1, mp, n, m);
  }
}

int main() {
  int n, m; cin >> n >> m;
  vc<string> mp(n);
  for (int i = 0; i < n; ++i) cin >> mp[i];
  int ret = 0;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      if (mp[i][j] == 'L') {
        ++ret;
        dfs(i, j, mp, n, m);
      }
    }
  }
  cout << ret << endl;
}
