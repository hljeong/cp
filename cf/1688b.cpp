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
    int n; cin >> n;
    int ec = 0;
    vi a(n); for (int i = 0; i < n; ++i) {
      cin >> a[i];
      if (!(a[i] & 1)) ++ec;
    }
    if (ec < n) {
      cout << ec << endl;
      continue;
    }
    int mn = 31;
    for (int i = 0; i < n; ++i) {
      int p = 0;
      while (!(a[i] & 1)) {
        ++p;
        a[i] /= 2;
      }
      ckmin(mn, p);
    }
    cout << (mn + n - 1) << endl;
  }
}