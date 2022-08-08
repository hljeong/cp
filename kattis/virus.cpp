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
  string s, t;
  cin >> s >> t;
  int n = s.length(), m = t.length(), i = 0, j = 0;
  while (i < n && i < m && s[i] == t[i]) ++i;
  while (i + j < n && i + j < m && s[n - j - 1] == t[m - j - 1]) ++j;
  cout << (m - j) - i << endl;
}