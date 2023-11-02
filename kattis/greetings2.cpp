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

using a3 = array<int, 3>;

// iterate over submasks
int main() {
  cin.tie(0) -> sync_with_stdio(0);

  int n, k; cin >> n >> k;
  vc<a3> c(n);
  for (int i = 0; i < n; ++i) {
    cin >> c[i][0] >> c[i][1] >> c[i][2];
  }
  vll waste(1 << n);
  for (int i = 0; i < (1 << n); ++i) {
    ll w = 0, h = 0;
    for (int j = 0; j < n; ++j) {
      if ((i >> j) & 1) {
        ckmax(w, (ll) c[j][0]);
        ckmax(h, (ll) c[j][1]);
      }
    }
    for (int j = 0; j < n; ++j) {
      if ((i >> j) & 1) {
        waste[i] += c[j][2] * (w * h - c[j][0] * c[j][1]);
      }
    }
  }
  vc<vll> dp(k + 1, vll(1 << n, infll));
  dp[0][0] = 0;
  for (int i = 0; i < k; ++i) {
    for (int j = 0; j < (1 << n); ++j) {
      for (int k = j; k; k = (k - 1) & j) {
        ckmin(dp[i + 1][j], dp[i][j ^ k] + waste[k]);
      }
    }
    ckmin(dp[i + 1][(1 << n) - 1], dp[i][(1 << n) - 1]);
  }
  cout << dp[k][(1 << n) - 1] << endl;
}
