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
  for (int tt = 1; tt <= t; ++tt) {
    cout << "Case #" << tt << ": ";
    int c1, m1, y1, k1;
    cin >> c1 >> m1 >> y1 >> k1;
    int c2, m2, y2, k2;
    cin >> c2 >> m2 >> y2 >> k2;
    int c3, m3, y3, k3;
    cin >> c3 >> m3 >> y3 >> k3;
    int c = min(c1, min(c2, c3));
    int m = min(m1, min(m2, m3));
    int y = min(y1, min(y2, y3));
    int k = min(k1, min(k2, k3));
    int sum = c + m + y + k;
    if (sum < 1000000) {
      cout << "IMPOSSIBLE" << endl;
    } else {
      int delta = min(k, sum - 1000000);
      k -= delta;
      sum -= delta;
      delta = min(y, sum - 1000000);
      y -= delta;
      sum -= delta;
      delta = min(m, sum - 1000000);
      m -= delta;
      sum -= delta;
      delta = min(c, sum - 1000000);
      c -= delta;
      sum -= delta;
      cout << c << ' ' << m << ' ' << y << ' ' << k << endl;
    }
  }
}