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

int calc(string &s, string &t) {
  int ans = 0, n = s.length();
  for (int i = 0; i < n; ++i) {
    ans += abs(s[i] - t[i]);
  }
  return ans;
}

int main() {
  int t;
  cin >> t;
  while (t--) {
    int n, m;
    cin >> n >> m;
    vc<string> s(n); 
    for (int i = 0; i < n; ++i) {
      cin >> s[i];
    }
    int ans = 26 * m;
    for (int i = 0; i < n; ++i) {
      for (int j = i + 1; j < n; ++j) {
        ckmin(ans, calc(s[i], s[j]));
      }
    }
    cout << ans << endl;
  }
}