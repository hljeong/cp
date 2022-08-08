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

// 6 -> 2 3 1
// 7 -> 2 4 1
// 8 -> 3 4 1
// 9 -> 3 4 2

int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    if (n % 3 == 0) {
      cout << (n / 3) << ' ' << (n / 3 + 1) << ' ' << (n / 3 - 1) << endl;
    } else if (n % 3 == 1) {
      cout << (n / 3) << ' ' << (n / 3 + 2) << ' ' << (n / 3 - 1) << endl;
    } else if (n % 3 == 2) {
      cout << (n / 3 + 1) << ' ' << (n / 3 + 2) << ' ' << (n / 3 - 1) << endl;
    }
  }
}