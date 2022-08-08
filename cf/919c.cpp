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
  int n, m, k, cnt = 0;
  cin >> n >> m >> k;
  vc<string> mp(n);
  for (int i = 0; i < n; ++i) {
    cin >> mp[i];
    for (int j = 0; j < m; ++j) if (mp[i][j] == '.') ++cnt;
  }
  if (k == 1) {
    cout << cnt << endl;
    return 0;
  }
  int ans = 0;
  for (int i = 0; i < n; ++i) {
    int run = 0;
    for (int j = 0; j < m; ++j) {
      if (mp[i][j] == '.') {
        ++run;
        if (run >= k) ++ans;
      } else {
        run = 0;
      }
    }
  }
  for (int i = 0; i < m; ++i) {
    int run = 0;
    for (int j = 0; j < n; ++j) {
      if (mp[j][i] == '.') {
        ++run;
        if (run >= k) ++ans;
      } else {
        run = 0;
      }
    }
  }
  cout << ans << endl;
}