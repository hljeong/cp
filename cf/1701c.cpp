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

template<class T> bool ckmin(T &a, const T &b) { return b < a ? a = b, 1 : 0; }
template<class T> bool ckmax(T &a, const T &b) { return a < b ? a = b, 1 : 0; }

int main() {
  int t; cin >> t;
  while (t--) {
    int n, m; cin >> n >> m;
    vi a(m); for (int i = 0; i < m; ++i) cin >> a[i], --a[i];
    int ans = 2 * m;
    for (int l = 1, r = 2 * m; l <= r; ) {
      int mid = l + (r - l) / 2, left = 0;
      vi time(n);
      for (int i = 0; i < m; ++i) {
        if (time[a[i]] < mid) ++time[a[i]];
        else ++left;
      }
      for (int i = 0; i < n; ++i) {
        while (left && time[i] + 2 <= mid) {
          --left;
          time[i] += 2;
        }
      }
      if (left) {
        l = mid + 1;
      } else {
        ans = mid;
        r = mid - 1;
      }
    }
    cout << ans << endl;
  }
}