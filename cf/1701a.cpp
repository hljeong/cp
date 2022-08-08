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
  int t; cin >> t;
  while (t--) {
    vc<vi> a(2, vi(2, 0)); for (int i = 0; i < 2; ++i) for (int j = 0; j < 2; ++j) cin >> a[i][j];
    int r = (a[0][0] | a[0][1]) + (a[1][0] | a[1][1]), c = (a[0][0] | a[1][0]) + (a[0][1] | a[1][1]);
    int R = (a[0][0] & a[0][1]) + (a[1][0] & a[1][1]), C = (a[0][0] & a[1][0]) + (a[0][1] & a[1][1]);
    if (!r && !c) {
      cout << 0 << endl;
    } else if (R < 2 || C < 2) {
      cout << 1 << endl;
    } else {
      cout << 2 << endl;
    }
  }
}