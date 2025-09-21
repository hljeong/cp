#include <bits/stdc++.h>
#define A first
#define B second
#define vc vector
using namespace std;
using ll = long long; using ld = long double;
using vi = vc<int>; using vll = vc<ll>;
using si = set<int>; using sll = set<ll>;
using pii = pair<int, int>; using mii = map<int, int>;
using gr = vc<vi>; using wgr = vc<vc<pii>>;

template<class T> bool ckmin(T &a, const T &b) { return b < a ? a = b, 1 : 0; }
template<class T> bool ckmax(T &a, const T &b) { return a < b ? a = b, 1 : 0; }

const int inf = 1e9 + 7;
const int mod = inf;
const ll infll = 0x3f3f3f3f3f3f3f3fll;

int main() {
  ll n; cin >> n;
  if (n == 1) {
    cout << 1 << endl;
    return 0;
  } else if (n == 2) {
    cout << 2 << endl;
    return 0;
  } else if (n == 3) {
    cout << 6 << endl;
    return 0;
  } else if (n == 4) {
    cout << 24 << endl;
    return 0;
  } else if (n == 5) {
    cout << 12 << endl;
    return 0;
  } else if (n == 6) {
    cout << 72 << endl;
    return 0;
  }
  ll ret = 1, c2 = 0, c5 = 0;
  for (ll k = n; k >= 2; --k) {
    ll kk = k;
    while (!(kk % 2)) {
      kk /= 2;
      ++c2;
    }
    while (!(kk % 5)) {
      kk /= 5;
      ++c5;
    }
    ret *= kk;
    ret %= 1000;
  }
  ll d = min(c2, c5);
  c2 -= d;
  c5 -= d;
  for (int i = 0; i < c2; ++i) {
    ret *= 2;
    ret %= 1000;
  }
  for (int i = 0; i < c5; ++i) {
    ret *= 5;
    ret %= 1000;
  }
  string sret = to_string(ret);
  while (sret.length() < 3) sret = "0" + sret;
  cout << sret << endl;
}
