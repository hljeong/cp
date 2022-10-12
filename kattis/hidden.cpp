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
  string p, s; cin >> p >> s;
  int len = p.length(), cur = 0;
  map<char, int> f;
  for (char c : p) ++f[c];
  for (char c : s) {
    if (c == p[cur]) {
      if (!--f[c]) {
        f.erase(f.find(c));
      }
      if (++cur == len) {
        break;
      }
    } else if (f.find(c) != f.end()) {
      break;
    }
  }
  cout << (cur == len ? "PASS" : "FAIL") << endl;
}
