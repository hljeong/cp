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
  int c; cin >> c; --c;
  int n = 0, cc = c;
  while (cc) {
    cc >>= 1;
    ++n;
  }
  ld pgo = 1, reset = 0;
  vc<ld> pm(n, 0);
  for (int i = 0; i < n; ++i) {
    if (!(c & (1 << (n - 1 - i)))) {
      pm[i] = powl(2, -1 - i);
      pgo -= pm[i];
      reset += pm[i] * (i + 1);
    }
  }
  cout << (n + reset / pgo) << endl;
}
