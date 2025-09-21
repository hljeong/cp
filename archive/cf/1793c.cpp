#include <bits/stdc++.h>
#define A first
#define B second
#define vc vector
#define pb push_back
using namespace std;
using ll = long long; using ld = long double;
using vi = vc<int>; using vll = vc<ll>;
using si = set<int>; using sll = set<ll>;
using pii = pair<int, int>; using pll = pair<ll, ll>;
using mii = map<int, int>;

template<class T> bool ckmin(T &a, const T &b) { return b < a ? a = b, 1 : 0; }
template<class T> bool ckmax(T &a, const T &b) { return a < b ? a = b, 1 : 0; }

const int inf = 1e9 + 7;
const int mod = inf;
const ll infll = 0x3f3f3f3f3f3f3f3fll;

int main() {
  int t; cin >> t;
  while (t--) {
    int n; cin >> n;
    vi a(n); for (int i = 0; i < n; ++i) cin >> a[i];
    int l = 0, r = n - 1, mn = 1, mx = n;
    while (l < r && (a[l] == mn || a[l] == mx || a[r] == mn || a[r] == mx)) {
      if (a[l] == mn) {
        ++l;
        ++mn;
      } else if (a[l] == mx) {
        ++l;
        --mx;
      } else if (a[r] == mn) {
        --r;
        ++mn;
      } else {
        --r;
        --mx;
      }
    }
    if (l == r) cout << -1 << endl;
    else cout << (l + 1) << ' ' << (r + 1) << endl;
  }
}
