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
    int n, m;
    cin >> n >> m;
    vc<vi> a(n, vi(m)), l(n, vi(m, n + m)), r(n, vi(m, -(n + m)));
    for (int i = 0; i < n; ++i) for (int j = 0; j < m; ++j) {
      cin >> a[i][j];
      if (!i && !j) l[i][j] = r[i][j] = a[i][j];
      if (i) ckmin(l[i][j], l[i - 1][j] + a[i][j]);
      if (j) ckmin(l[i][j], l[i][j - 1] + a[i][j]);
      if (i) ckmax(r[i][j], r[i - 1][j] + a[i][j]);
      if (j) ckmax(r[i][j], r[i][j - 1] + a[i][j]);
    }
    if ((n + m - 1) & 1) cout << "NO" << endl;
    else cout << (l[n - 1][m - 1] <= 0 && 0 <= r[n - 1][m - 1] ? "YES" : "NO") << endl;
  }
}