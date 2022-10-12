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
  int n, k, ans = 0; cin >> n >> k;
  vi r(1 << n); for (int i = 0; i < 1 << n; ++i) cin >> r[i];
  sort(r.rbegin(), r.rend());
  for (int b = 0; b < n; ++b) {
    int m = 1 << b, j = m - 1;
    for (int i = m - 1; i >= 0; --i) {
      while (~j && r[i] - r[m + j] > k) --j;
      if (!~j) break;
      ++ans;
      --j;
    }
  }
  cout << ans << endl;
}
