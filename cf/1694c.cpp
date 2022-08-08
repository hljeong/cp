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
    ll bal = 0;
    bool bad = false, z = false;
    for (int i = 0; i < n; ++i) {
      cin >> a[i];
      bal += a[i];
      if (bal < 0 || z && a[i]) bad = true;
      if (!bal) z = true;
    }
    cout << (!bal && !bad ? "Yes" : "No") << endl;
  }
}