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
  int n; cin >> n;
  vi p(n); for (int i = 0; i < n; ++i) cin >> p[i];
  vc<vll> dp(n, vll(n, -infll));
  ll ret = -infll;
  for (int i = 0; i < n; ++i) dp[0][i] = p[0];
  for (int i = 1; i < n; ++i) {
    for (int j = n - 1; j > 0; --j) {
      if (i - j >= 0) ckmax(dp[i][j], dp[i - j][j] + p[i]);
      if (j < n - 1) ckmax(dp[i][j], dp[i][j + 1]);
    }
  }
  for (int i = 0; i < n; ++i) ckmax(ret, dp[n - 1][i]);
  cout << ret << endl;
}