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
  int n; cin >> n;
  vi a(n); for (int i = 0; i < n; ++i) cin >> a[i];
  vc<char> ans(20, '?');
  for (int i = 0; i < 20; ++i) {
    if ((1 << i) >= n) {
      if (a[0] == 20 - i) {
        for (int j = 2; j < 20; ++j) ans[j] = 'A';
      }
      break;
    }
    if (a[0] == a[1 << i]) ans[i] = 'x';
    else if (a[0] > a[1 << i]) {
      ans[i] = 'A';
      for (int j = 0; j < n; ++j) if (!(j & (1 << i))) a[j] -= 1;
    } else {
      ans[i] = 'B';
      for (int j = 0; j < n; ++j) if (j & (1 << i)) a[j] -= 1;
    }
  }
  for (int i = 0; i < 20; ++i) {
    cout << ans[i] << " \n"[i == 19];
  }
}
