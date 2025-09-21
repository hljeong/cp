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
    vi a(n);
    for (int i = 0; i < n; ++i) {
      cin >> a[i];
    }
    int l = 0, r = 0, i = 0, j = n, gi = 0, gj = n;
    while (i < j) {
      if (l == r) {
        gi = i;
        gj = j;
        l += a[i++];
      } else if (l < r) {
        l += a[i++];
      } else {
        r += a[--j];
      }
    }
    if (l == r) {
      gi = i;
      gj = j;
    }
    cout << gi + (n - gj) << endl;
  }
}