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
    int n, mn = 1e9;
    cin >> n;
    vi a(n);
    for (int i = 0; i < n; ++i) {
      cin >> a[i];
      ckmin(mn, a[i]);
    }
    if (n & 1) cout << "Mike" << endl;
    else {
      int ind = -1;
      for (int i = 0; i < n; ++i) {
        if (a[i] == mn) {
          ind = i;
          break;
        }
      }
      cout << (ind & 1 ? "Mike" : "Joe") << endl;
    }
  }
}