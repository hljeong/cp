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
  for (int tt = 1; tt <= t; ++tt) {
    string s, ans = "";
    cin >> s;
    int n = s.length();
    bool bad = true;
    char last = 0;
    for (int i = n - 1; i >= 0; --i) {
      if (s[i] < last || !bad && s[i] == last) {
        ans += s[i];
        bad = false;
      } else if (s[i] > last) {
        bad = true;
      }
      ans += s[i];
      last = s[i];
    }
    int m = ans.length();
    for (int i = 0; i < m / 2; ++i) {
      swap(ans[i], ans[m - i - 1]);
    }
    cout << "Case #" << tt << ": " << ans << endl;
  }
}