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
    int n, bit = 1, ans = 0;
    cin >> n;
    while (true) {
      vi a, b;
      for (int i = 0; i < n; ++i) {
        if (i & bit) a.push_back(i + 1);
        else b.push_back(i + 1);
      }
      if (!a.size() || !b.size()) break;
      cout << a.size() << ' ' << b.size();
      for (int i = 0; i < a.size(); ++i) cout << ' ' << a[i];
      for (int i = 0; i < b.size(); ++i) cout << ' ' << b[i];
      cout << endl << flush;
      int x;
      cin >> x;
      ckmax(ans, x);
      bit <<= 1;
    }
    cout << -1 << ' ' << ans << endl;
  }
}