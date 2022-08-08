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

const int mod = 998244353;

int main() {
  int t;
  cin >> t;
  while (t--) {
    int n, s;
    cin >> n >> s;
    vi a(n), b(n);
    for (int i = 0; i < n; ++i) cin >> a[i];
    for (int i = 0; i < n; ++i) cin >> b[i];
    set<int> nd;
    vi blk;
    int m = 0;
    for (int i = 0; i < n; ++i) {
      nd.insert(i + 1);
      if (b[i] == -1) blk.push_back(a[i]), ++m;
    }
    sort(blk.begin(), blk.end());
    for (int i = 0; i < n; ++i) nd.erase(b[i]);
    ll ans = 1;
    for (int i = 0; i < n; ++i) if (b[i] > 0 && a[i] > b[i] + s) ans *= 0;
    int cur = 0, ind = 0;
    for (int i : nd) {
      while (cur < m && i + s >= blk[cur]) {
        ++cur;
      }
      ans *= max(0, cur - ind);
      ++ind;
      ans %= mod;
    }
    cout << ans << endl;
  }
}