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
  string s;
  while (cin >> s) {
    int n = s.length();
    char c = s[0];
    int run = 1, i = 1;
    string ans;
    while (i < n) {
      char nc = s[i];
      if (nc != c) {
        ans += to_string(run);
        ans += c;
        run = 1;
      } else ++run;
      c = nc;
      ++i;
    }
    ans += to_string(run);
    ans += c;
    cout << ans << endl;
  }
}
