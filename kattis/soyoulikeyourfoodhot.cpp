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
  ld ptr, p1r, p2r;
  cin >> ptr >> p1r >> p2r;
  int pt = round(100 * ptr), p1 = round(100 * p1r), p2 = round(100 * p2r);
  bool good = false;
  for (int i = 0; i <= pt / p1; ++i) {
    if (!((pt - i * p1) % p2)) {
      cout << i << ' ' << (pt - i * p1) / p2 << endl;
      good = true;
    }
  }
  if (!good) cout << "none" << endl;
}