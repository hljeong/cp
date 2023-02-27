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
  int n, m, ans = 0;
  string s;
  cin >> n >> m >> s;
  for (int i = n - 1; i >= 0; --i) {
    if (s[i] - '0') {
      ++ans;
      if (i > 1 && s[i - 1] - '0') {
        s[i - 1] = '0';
        s[i - 2] = '1';
      }
    }
  }
  cout << ans << endl;
}