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
  int n; cin >> n;
  vc<vi> a(n, vi(n));
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      cin >> a[i][j];
    }
  }
  vll dp(1 << n);
  for (int i = 0; i < (1 << n); ++i) {
    for (int j = 0; j < n; ++j) {
      for (int k = j + 1; k < n; ++k) {
        if ((i >> j) & (i >> k) & 1) {
          dp[i] += a[j][k];
        }
      }
    }
  }
  for (int mask = 0; mask < (1 << n); ++mask) {
    for (int smask = mask; smask; smask = (smask - 1) & mask) {
      ckmax(dp[mask], dp[smask] + dp[mask ^ smask]);
    }
  }
  cout << dp[(1 << n) - 1] << endl;
}
