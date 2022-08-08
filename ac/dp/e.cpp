#include <bits/stdc++.h>
#define A first
#define B second
using namespace std;
using ll = long long;
using vi = vector<int>;
using vll = vector<ll>;

template<class T> bool ckmin(T& a, const T& b) { return b < a ? a = b, 1 : 0; }
template<class T> bool ckmax(T& a, const T& b) { return a < b ? a = b, 1 : 0; }

int main() {
  int n, wn, ans = 0;
  cin >> n >> wn;
  vi w(n), v(n);
  for (int i = 0; i < n; ++i) {
    cin >> w[i] >> v[i];
  }
  ll inf = 0x3f3f3f3f3f3f3f3f;
  vll dp(n * 1000 + 5, inf);
  dp[0] = 0;
  for (int i = 0; i < n; ++i) 
    for (int j = n * 1000; j >= v[i]; --j) 
      if (dp[j - v[i]] != inf) 
        ckmin(dp[j], dp[j - v[i]] + w[i]);
  for (int i = n * 1000; i >= 0; --i) 
    if (dp[i] <= wn) {
      cout << i << endl;
      break;
    }
}