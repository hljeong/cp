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
    vi b(n);
    for (int i = 0; i < n; ++i) {
      cin >> b[i];
    }
    if (n & 1) {
      cout << "NO" << endl;
      continue;
    }
    sort(b.begin(), b.end());
    vi ans(n);
    for (int i = 0; i < n / 2; ++i) {
      ans[i << 1] = b[i];
      ans[i << 1 | 1] = b[i + n / 2];
    }
    bool bad = false;
    for (int i = 0; i < n; ++i) {
      int im1 = (i + n - 1) % n, ip1 = (i + 1) % n;
      if (!(ans[i] < ans[im1] && ans[i] < ans[ip1]) && !(ans[i] > ans[im1] && ans[i] > ans[ip1])) bad = true;
    }
    if (bad) cout << "NO" << endl;
    else {
      cout << "YES" << endl;
      for (int i = 0; i < n; ++i) cout << ans[i] << " \n"[i == n - 1];
    }
  }
}