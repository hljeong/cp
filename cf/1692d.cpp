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
    string s;
    cin >> s;
    int x;
    cin >> x;
    int ih = stoi(s.substr(0, 2)), im = stoi(s.substr(3, 2)), h = ih, m = im;
    set<pii> ps;
    while (true) {
      if (h / 10 == m % 10 && h % 10 == m / 10) {
        pii p = {h, m};
        ps.insert(p);
      }
      m += x;
      h += m / 60;
      m %= 60;
      h %= 24;
      if (h == ih && m == im) break;
    }
    cout << ps.size() << endl;
  }
}