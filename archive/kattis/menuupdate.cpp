#include <bits/stdc++.h>
#define A first
#define B second
#define vc vector
using namespace std;
using ll = long long; using ld = long double;
using vi = vc<int>; using vll = vc<ll>;
using si = set<int>; using sll = set<ll>;
using pii = pair<int, int>; using mii = map<int, int>;

template<class T> bool ckmin(T &a, const T &b) { return b < a ? a = b, 1 : 0; }
template<class T> bool ckmax(T &a, const T &b) { return a < b ? a = b, 1 : 0; }

const int inf = 1e9 + 7;
const int mod = inf;

int main() {
  int d, u; cin >> d >> u;
  vi r(d);
  si s;
  for (int i = 1; i <= u; ++i) s.insert(i);
  for (int i = 0; i < u; ++i) {
    if (r[i % d]) {
      s.insert(r[i % d]);
      r[i % d] = 0;
    }
    char c; cin >> c;
    if (c == 'a') {
      cout << *(s.begin()) << endl;
      s.erase(s.begin());
    } else {
      int x; cin >> x;
      r[i % d] = x;
    }
  }
}
