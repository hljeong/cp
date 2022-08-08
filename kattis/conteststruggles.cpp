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
  int n, k, d, s;
  cin >> n >> k >> d >> s;
  ld ans = (ld) (n * d - s * k) / (n - k);
  if (ans < 0 || ans > 100) cout << "impossible" << endl;
  else cout << setprecision(12) << ans << endl;
}