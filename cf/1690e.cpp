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
    int n, k;
    cin >> n >> k;
    vi a(n), f(k);
    ll ans = 0;
    for (int i = 0; i < n; ++i) {
      cin >> a[i];
      ++f[a[i] % k];
      ans += a[i] / k;
    }
    int i = 1, j = k - 1;
    while (i < j) {
      if (!f[i]) ++i;
      else if (!f[j]) --j;
      else if (i + j < k) ++i;
      else {
        --f[i];
        --f[j];
        ++ans;
      }
    }
    if (i < k && 2 * i >= k) ans += f[i] / 2;
    cout << ans << endl;
  }
}