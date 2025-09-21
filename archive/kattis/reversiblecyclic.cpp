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
  string s; cin >> s;
  int n = s.length();
  vc<string> c(n);
  for (int i = 0; i < n; ++i) {
    c[i] = s.substr(i, n - i) + s.substr(0, i);
    c[i] = c[i].substr(0, n - 1);
  }
  string a = s.substr(0, n - 1), b = s.substr(1);
  reverse(a.begin(), a.end());
  reverse(b.begin(), b.end());
  bool good1 = false, good2 = false;
  for (int i = 0; i < n; ++i) {
    good1 |= c[i] == a;
    good2 |= c[i] == b;
  }
  cout << int(good1 && good2) << endl;
}
