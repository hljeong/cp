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
    int n, k;
    cin >> n >> k;
    vi a(n);
    map<int, int> f;
    set<int> s;
    for (int i = 0; i < n; ++i) {
      cin >> a[i];
      ++f[a[i]];
      s.insert(a[i]);
    }
    int ans = 0, run = 0, last = -100, lastl = -1, l = -1, r = -1;
    for (int x : s) {
      if (f[x] < k) continue;
      if (x != last + 1) {
        run = 1;
        lastl = x;
        if (ckmax(ans, run)) {
          l = lastl;
          r = x;
        }
      } else if (ckmax(ans, ++run)) {
        l = lastl;
        r = x;
      }
      last = x;
    }
    if (!ans) cout << -1 << endl;
    else cout << l << ' ' << r << endl;
  }
}