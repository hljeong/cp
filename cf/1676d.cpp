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
    map<int, int> xpy, xmy; 
    int n, m;
    cin >> n >> m;
    vc<vi> mp(n, vi(m));
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < m; ++j) {
        cin >> mp[i][j];
        xpy[i + j] += mp[i][j];
        xmy[i - j] += mp[i][j];
      }
    }
    int ans = 0;
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < m; ++j) {
        ckmax(ans, xpy[i + j] + xmy[i - j] - mp[i][j]);
      }
    }
    cout << ans << endl;
  }
}