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
    vi s(n), f(n), ans(n);
    for (int i = 0; i < n; ++i) cin >> s[i];
    for (int i = 0; i < n; ++i) cin >> f[i];
    ans[0] = f[0] - s[0];
    for (int i = 1; i < n; ++i) ans[i] = f[i] - max(s[i], f[i - 1]);
    for (int i = 0; i < n; ++i) cout << ans[i] << " \n"[i == n - 1];
  }
}