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
  for (int tt = 1; tt <= t; ++tt) {
    cout << "Case #" << tt << ':' << endl;
    int r, c;
    cin >> r >> c;
    for (int i = 0; i < 2 * r + 1; ++i) {
      string s = "";
      for (int j = 0; j < 2 * c + 1; ++j) {
        s += (i & 1) ? ((j & 1) ? '.' : '|') : ((j & 1) ? '-' : '+');
      }
      if (i < 2) s[0] = s[1] = '.';
      cout << s << endl;
    }
  }
}