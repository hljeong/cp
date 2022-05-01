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

// easy case only

int main() {
  int t;
  cin >> t;
  for (int tt = 1; tt <= t; ++tt) {
    int n, k;
    cin >> n >> k;
    vll e(n);
    ll mn = 1e18 + 1, mx = -1e18 - 1, sum = 0, sumsq = 0;
    for (int i = 0; i < n; ++i) {
      cin >> e[i];
      ckmin(mn, e[i]);
      ckmax(mx, e[i]);
      sum += e[i];
      sumsq += e[i] * e[i];
    }
    cout << "Case #" << tt << ": ";
    if (mn == mx && mn == 0) {
      cout << 0 << endl;
    } else if (sum == 0 || (sumsq - sum * sum) % (2 * sum) != 0) {
      cout << "IMPOSSIBLE" << endl;
    } else {
      cout << (sumsq - sum * sum) / (2 * sum) << endl;
    }
  }
}