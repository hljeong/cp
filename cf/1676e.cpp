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
    int n, q;
    cin >> n >> q;
    vi a(n), p(n + 1);
    for (int i = 0; i < n; ++i) {
      cin >> a[i];
    }
    sort(a.rbegin(), a.rend());
    for (int i = 0; i < n; ++i) {
      p[i + 1] = p[i] + a[i];
    }
    for (int tt = 0; tt < q; ++tt) {
      int ans = -1, x;
      cin >> x;
      for (int l = 0, r = n; l <= r; ) {
        int m = l + (r - l) / 2;
        if (p[m] >= x) {
          ans = m;
          r = m - 1;
        } else l = m + 1;
      }
      cout << ans << endl;
    }
  }
}