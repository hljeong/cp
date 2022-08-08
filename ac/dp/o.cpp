#include <bits/stdc++.h>
#define A first
#define B second
#define vc vector
using namespace std;
using ll = long long;
using ld = long double;
using vi = vc<int>;
using vll = vc<ll>;
using pii = pair<int, int>;

template<class T> bool ckmin(T& a, const T& b) { return b < a ? a = b, 1 : 0; }
template<class T> bool ckmax(T& a, const T& b) { return a < b ? a = b, 1 : 0; }

const int mod = 1e9 + 7; 

int main() {
  int n; cin >> n;
  vi dp(1 << n);
  dp[0] = 1;
  for (int i = 0; i < n; ++i) {
    vi ndp(1 << n);
    for (int j = 0; j < n; ++j) {
      int a; cin >> a;
      if (!a) continue;
      for (int m = 0; m < 1 << n; ++m) {
        ndp[m | (1 << j)] += dp[m];
        if (ndp[m | (1 << j)] >= mod) ndp[m | (1 << j)] -= mod;
      }
    }
    dp = ndp;
  }
  cout << dp[(1 << n) - 1] << endl;
}