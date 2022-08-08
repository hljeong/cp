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
    int n, k; cin >> n >> k;
    string s; cin >> s;
    int ans = 0, cnt1 = 0;
    for (int i = 0; i < n; ++i) {
      int c = s[i] - '0';
      if (c) ++cnt1;
      if (i < n - 1) ans += 10 * c;
      if (i) ans += c;
    }
    int cnt = 0, rcnt = 0;
    for (int i = n - 1; i >= 0; --i) {
      if (s[i] == '1') break;
      ++cnt;
    }
    for (int i = 0; i < n; ++i) {
      if (s[i] == '1') break;
      ++rcnt;
    }
    bool noright = false;
    if (cnt == n) cnt = 1e9 + 7;
    if (cnt && cnt <= k) {
      if (cnt == n - 1) ans -= 9;
      else ans -= 10;
      k -= cnt;
    } else noright = true;
    if ((cnt1 > 1 || noright) && cnt1 && rcnt && rcnt < n - 1 && rcnt <= k) ans -= 1;
    cout << ans << endl;
  }
}