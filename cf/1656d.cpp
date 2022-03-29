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

int main() {
  int t;
  cin >> t;
  while (t--) {
    ll n, m, ans = 2;
    cin >> n, m = n;
    while (!(m & 1)) {
      m >>= 1;
      ans <<= 1;
    }
    if (m > 1) ckmin(ans, m);
    if (ans > 1e9 || 2 * n < ans * (ans - 1)) {
      cout << -1 << endl;
      continue;
    }
    cout << ans << endl;
  }
}