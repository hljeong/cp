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
  string kr; cin >> kr; int n = kr.length(); 
  vi ks(n); for (int i = 0; i < n; ++i) ks[i] = kr[i] - '0';
  int d; cin >> d;
  vc<vll> dp(2, vll(d));
  dp[1][0] = 1;
  for (int i = 0; i < n; ++i) {
    vc<vll> ndp(2, vll(d));
    for (int j = 0; j < 10; ++j) {
      for (int k = 0; k < d; ++k) {
        ndp[0][(k + j) % d] += dp[0][k];
        if (j < ks[i]) ndp[0][(k + j) % d] += dp[1][k];
        ndp[0][(k + j) % d] %= mod;
      }
    }
    for (int j = 0; j < d; ++j) {
      ndp[1][(j + ks[i]) % d] += dp[1][j];
    }
    dp = ndp;
  }
  cout << (dp[0][0] + dp[1][0] + mod - 1) % mod << endl;
}