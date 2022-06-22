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
  int n, ans = 1;
  cin >> n;
  vi a(n);
  for (int i = 0; i < n; ++i) cin >> a[i];
  vi inc(n + 1, 1), dec(n + 1, 1);
  inc[0] = dec[n] = 0;
  for (int i = 1; i < n; ++i) {
    if (a[i - 1] < a[i]) inc[i + 1] = inc[i] + 1;
    if (a[n - i - 1] < a[n - i]) dec[n - i - 1] = dec[n - i] + 1;
  }
  // for (int i = 0; i <= n; ++i) cout << inc[i] << " \n"[i == n];
  // for (int i = 0; i <= n; ++i) cout << dec[i] << " \n"[i == n];
  for (int i = 0; i < n; ++i) {
    ckmax(ans, inc[i] + 1);
    ckmax(ans, 1 + dec[i + 1]);
    if (i && n - i - 1 && a[i - 1] + 1 < a[i + 1]) ckmax(ans, inc[i] + 1 + dec[i + 1]);
  }
  cout << ans << endl;
}