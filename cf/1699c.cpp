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

const int mod = 1e9 + 7;

int main() {
  int t; cin >> t;
  while (t--) {
    int n; cin >> n;
    int l, r;
    vi a(n), ia(n); for (int i = 0; i < n; ++i) {
      cin >> a[i];
      ia[a[i]] = i;
      if (!a[i]) l = r = i;
    }
    ll ans = 1, free = 0;
    vc<bool> seen(n + 1);
    seen[0] = true;
    int mex = 1;
    for (int i = 1; i < n; ++i) {
      if (mex > i) {
        ans *= free;
        ans %= mod;
        --free;
        continue;
      }
      if (ia[i] < l) {
        while (l > ia[i]) {
          --l;
          ++free;
          seen[a[l]] = true;
        }
        --free;
      } else {
        while (r < ia[i]) {
          ++r;
          ++free;
          seen[a[r]] = true;
        }
        --free;
      }
      while (seen[mex]) ++mex;
    }
    cout << ans << endl;
  }
}