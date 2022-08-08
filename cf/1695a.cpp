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
    int n, m, mx = -1e9;
    cin >> n >> m;
    vc<vi> a(n, vi(m)); 
    for (int i = 0; i < n; ++i) for (int j = 0; j < m; ++j) {
      cin >> a[i][j];
      ckmax(mx, a[i][j]);
    }
    int t = n, b = n, l = m, r = m;
    for (int i = 0; i < n; ++i) for (int j = 0; j < m; ++j) if (a[i][j] == mx) {
      ckmin(t, i + 1);
      ckmin(b, n - i);
      ckmin(l, j + 1);
      ckmin(r, m - j);
    }
    cout << max(t, b) * max(l, r) << endl;
  }
}