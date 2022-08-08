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
  int n;
  cin >> n;
  string s;
  cin >> s;
  for (int i = 0; i < n; ++i) s[i] = (char) ('0' + ('9' - s[i]));
  if (s[0] == '0') {
    int c = 1;
    for (int i = n - 1; i >= 0; --i) {
      s[i] += 1 + c;
      if (s[i] > '9') {
        s[i] -= 10;
        c = 1;
      } else c = 0;
    }
  }
  cout << s << endl;
 } 
}