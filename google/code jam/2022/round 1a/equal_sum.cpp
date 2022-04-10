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
    ll sa = 0, sb = 0;
    for (int i = 0; i < 30; ++i) {
      cout << (1 << i) << ' ';
      sa += 1 << i;
    }
    for (int i = 1; i <= 65; ++i) {
      if (i != 33)
        cout << ((1 << 29) + i) << ' ';
    }
    cout << ((1 << 29) + 70) << ' ';
    cout << ((1 << 29) + 71) << ' ';
    cout << ((1 << 29) + 72) << ' ';
    cout << ((1 << 29) + 73) << ' ';
    cout << ((1 << 29) + 75) << ' ';
    cout << ((1 << 29) + 79) << endl;
    cout << flush;
    vi b(100);
    for (int i = 0; i < n; ++i) {
      cin >> b[i];
      sb += b[i];
    }
    ll s = (sa - sb) / 2;
    int k = 0;
    while (s < 0) {
      s += b[k++];
    }
    while (k < n) {
      cout << b[k++] << ' ';
    }
    for (int i = 0; i < 16; ++i) {
      cout << ((1 << 29) + (i + 1)) << ' ' << ((1 << 29) + (65 - i)) << ' ';
    }
    cout << ((1 << 29) + 70) << ' ' << ((1 << 29) + 71) << ' ' << ((1 << 29) + 79);
    for (int i = 0; i < 30; ++i) {
      if (s & (1 << i)) cout << ' ' << (1 << i);
    }
    cout << endl << flush;
  }
}