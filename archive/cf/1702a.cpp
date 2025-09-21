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
    string s; cin >> s;
    s[0] = (char) (s[0] - 1);
    while (s[0] == '0' && s.length() > 1) {
      s = s.substr(1, s.length() - 1);
    }
    cout << s << endl;
  }
}