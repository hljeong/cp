#include <bits/stdc++.h>
#define A first
#define B second
#define vc vector
#define pb push_back
using namespace std;
using ll = long long; using ld = long double;
using vi = vc<int>; using vll = vc<ll>;
using si = set<int>; using sll = set<ll>;
using pii = pair<int, int>; using mii = map<int, int>;

template<class T> bool ckmin(T &a, const T &b) { return b < a ? a = b, 1 : 0; }
template<class T> bool ckmax(T &a, const T &b) { return b > a ? a = b, 1 : 0; }

const int inf = 1e9 + 7;
const ll mod = 11092019;
const ll infll = 0x3f3f3f3f3f3f3f3fll;

inline int lsb(int m) {
  return m & (-m);
}

int main() {
  string s; cin >> s;
  vll f(26);
  for (char c : s) ++f[c - 'a'];
  ll ret = 1;
  for (ll i : f) ret = (ret * (1 + i)) % mod;
  cout << ret << endl;
}