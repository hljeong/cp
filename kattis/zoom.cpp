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
  int n, k; cin >> n >> k;
  vi a(n); for (int i = 0; i < n; ++i) cin >> a[i];
  vi ans(n / k);
  for (int i = 0; i < n / k; ++i) ans[i] = a[(i + 1) * k - 1];
  for (int i = 0; i < n / k; ++i) cout << ans[i] << " \n"[i == n / k - 1];
}
