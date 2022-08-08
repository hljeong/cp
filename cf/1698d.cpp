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
    int n, ans = -1;
    cin >> n;
    for (int l = 0, r = n; l < r; ) {
      int m = l + (r - l) / 2, p = 0, a;
      cout << "? " << (l + 1) << ' ' << (m + 1) << endl << flush;
      for (int i = 0; i <= m - l; ++i) {
        cin >> a;
        if (l + 1 <= a && a <= m + 1) p ^= 1;
      }
      if (p) {
        ans = m + 1;
        r = m;
      } else {
        l = m + 1;
      }
    }
    cout << "! " << ans << endl;
  }
}