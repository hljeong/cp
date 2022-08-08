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
    int n, p = 0;
    cin >> n;
    for (int i = 2; i * i <= n; ++i) {
      if (!(n % i)) {
        p = i;
        break;
      }
    }
    if (!p) p = n;
    cout << (n / p) << ' ' << (n - n / p) << endl;
  }
}