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
    int a, b;
    cin >> a >> b;
    if (a < b) {
      for (int i = 0; i < a; ++i) {
        cout << "01";
      }
      for (int i = 0; i < b - a; ++i) {
        cout << "1";
      }
      cout << endl;
    } else {
      for (int i = 0; i < b; ++i) {
        cout << "10";
      }
      for (int i = 0; i < a - b; ++i) {
        cout << "0";
      }
      cout << endl;
    }
  }
}