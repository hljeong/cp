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
    int n;
    cin >> n;
    ll ans = 0, adj = 0;
    vi a(n);
    for (int i = 0; i < n; ++i) {
      cin >> a[i];
      if (i) {
        int d = abs(a[i] - a[i - 1]), c = max(0, a[i] - a[i - 1]);
        ans += d;
        adj -= c;
      }
    }
    ans += abs(a[n - 1] + adj);
    cout << ans << endl;
  }
}