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
  int n, a, b;
  cin >> n >> a >> b;
  --a;
  --b;
  int x = a ^ b;
  int m = 0;
  while (n > 1) {
    ++m;
    n >>= 1;
  }
  for (int i = m - 1; i >= 0; --i) {
    if (x & (1 << i)) {
      if (i == m - 1)
        cout << "Final!" << endl;
      else 
        cout << i + 1 << endl;
      return 0;
    }
  }
}