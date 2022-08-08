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
    vi p(n); for (int i = 0; i < n; ++i) cin >> p[i];
    vi ans(n); for (int i = 0; i < n; ++i) ans[i] = i + 1;
    for (int i = 0; i < n - 1; ++i) {
      if (p[i] == ans[i]) swap(ans[i], ans[i + 1]);
    }
    if (n == 1) cout << -1 << endl;
    else {
      if (p[n - 1] == ans[n - 1]) swap(ans[n - 1], ans[n - 2]);
      for (int i = 0; i < n; ++i) cout << ans[i] << " \n"[i == n - 1];
    }
  }
}