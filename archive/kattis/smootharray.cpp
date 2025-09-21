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
template<class T> bool ckmax(T &a, const T &b) { return a < b ? a = b, 1 : 0; }

const int inf = 1e9 + 7;
const int mod = inf;
const ll infll = 0x3f3f3f3f3f3f3f3fll;

int main() {
  int n, k, s; cin >> n >> k >> s;
  vi a(n); for (int i = 0; i < n; ++i) cin >> a[i];
  vi cnt(k); for (int i = 0; i < n; ++i) ++cnt[i % k];
  vc<mii> f(k); for (int i = 0; i < n; ++i) ++f[i % k][a[i]];
  vc<vi> dp(k + 1, vi(s + 1, inf)), mdp(k + 1, vi(s + 1 + 1, inf));
  dp[0][0] = 0;
  for (int i = 0; i <= s; ++i) mdp[0][i + 1] = min(mdp[0][i], dp[0][i]);
  for (int i = 0; i < k; ++i) {
    for (int j = 0; j <= s; ++j) {
      ckmin(dp[i + 1][j], mdp[i][j + 1] + cnt[i]);
      for (const auto &p : f[i]) {
        if (j < p.A) continue;
        ckmin(dp[i + 1][j], dp[i][j - p.A] + cnt[i] - p.B);
      }
      mdp[i + 1][j + 1] = min(mdp[i + 1][j], dp[i + 1][j]);
    }
  }
  /*
  for (int i = 1; i <= k; ++i) {
    for (int j = 0; j <= s; ++j) {
      cout << dp[i][j] << " \n"[j == s];
    }
  }
  */
  cout << dp[k][s] << endl;
}
