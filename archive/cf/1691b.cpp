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
    vi a(n); map<int, int> f; for (int i = 0; i < n; ++i) {
      cin >> a[i];
      ++f[a[i]];
    }
    bool bad = false;
    for (int i : a) bad |= f[i] == 1;
    if (bad) {
      cout << -1 << endl;
      continue;
    }
    vi ans(n);
    for (int i = 0; i < n; ++i) {
      if (!i || a[i - 1] != a[i]) {
        ans[i] = i + f[a[i]];
      } else ans[i] = i;
    }
    for (int i = 0; i < n; ++i) cout << ans[i] << " \n"[i == n - 1];
  }
}