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
using gr = vc<vi>; using wgr = vc<vc<pii>>;

template<class T> bool ckmin(T &a, const T &b) { return b < a ? a = b, 1 : 0; }
template<class T> bool ckmax(T &a, const T &b) { return a < b ? a = b, 1 : 0; }

const int inf = 1e9 + 7;
const int mod = inf;
const ll infll = 0x3f3f3f3f3f3f3f3fll;

int main() {
  int n; cin >> n;
  vc<vc<pii>> prf(n);
  for (int i = 0; i < n; ++i) {
    int p; cin >> p;
    for (int j = 0; j < p; ++j) {
      int l, k; cin >> l >> k;
      prf[i].pb({l, 0});
      for (int kk = 0; kk < k; ++kk) {
        int d; cin >> d;
        prf[i][j].B |= 1 << d;
      }
    }
  }
  vll dp(1 << n, infll);
  dp[0] = 0;
  vi masks(1 << n);
  for (int i = 0; i < (1 << n); ++i) masks[i] = i;
  sort(masks.begin(), masks.end(), [&](int i, int j) {return __builtin_popcount(i) < __builtin_popcount(j);});
  for (int m : masks) {
    for (int i = 0; i < n; ++i) {
      if (!((m >> i) & 1)) {
        for (pii p : prf[i]) {
          if ((m & p.B) == p.B) ckmin(dp[m | (1 << i)], dp[m] + p.A);
        }
      }
    }
  }
  ll ans = infll;
  for (int i = 0; i < (1 << n); ++i) if (i & 1) ckmin(ans, dp[i]);
  cout << ans << endl;
}
