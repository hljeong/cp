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

const int maxn = 5005, maxm = 25;
vc<vc<pii>> rg(maxn, vc<pii>(maxm));
vc<vi> dp(maxn, vi(maxm));

int solve(int n, int m) {
  if (dp[n][m]) return dp[n][m];
  if (n == 0) return 0;
  if (m == 1) {
    rg[n][m].A = rg[n][m].B = 1;
    return n;
  }
  int ret = n;
  for (int i = 1; i <= n; ++i) {
    int left = solve(i - 1, m - 1), right = solve(n - i, m);
    int nret = 1 + max(left, right);
    if (ckmin(ret, nret)) {
      rg[n][m].A = rg[n][m].B = i;
    } else if (ret == nret) rg[n][m].B = i;
  }
  return (dp[n][m] = ret);
}

int main() {
  int n, m; cin >> n >> m;
  int ret = solve(n, m);
  cout << ret << ' ' << rg[n][m].A << ((rg[n][m].A != rg[n][m].B) ? "-" : "") << ((rg[n][m].A != rg[n][m].B) ? to_string(rg[n][m].B) : "") << endl;
}
