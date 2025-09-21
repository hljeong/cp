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
  int n; cin >> n;
  vi x(n); for (int i = 0; i < n; ++i) cin >> x[i];
  for (int k = 1; k <= n / 2; ++k) {
    int j = 2 * k;
    int last = x[k - 1];
    bool good = true;
    while (j <= n) {
      int next = x[j - 1];
      if (next <= last) {
        good = false;
        break;
      }
      last = next;
      j += k;
    }
    if (good) {
      cout << k << endl;
      return 0;
    }
  }
  cout << "ABORT!" << endl;
}
