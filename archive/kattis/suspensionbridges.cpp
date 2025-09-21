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
using gr = vc<vi>; using wgr = vc<vc<pii>>;

template<class T> bool ckmin(T &a, const T &b) { return b < a ? a = b, 1 : 0; }
template<class T> bool ckmax(T &a, const T &b) { return a < b ? a = b, 1 : 0; }

const int inf = 1e9 + 7;
const int mod = inf;
const ll infll = 0x3f3f3f3f3f3f3f3fll;

template<class T> T minst(function<bool(T)> pred, T i, T j) {
  T ret = j + 1;
  for (T l = i, r = j, m; r - l > 1e-12; ) {
    if (pred(m = l + (r - l) / 2)) r = (ret = m);
    else l = m;
  }
  return ret;
}

ld ccosh(ld x) {
  return (exp(x) + exp(-x)) / 2;
}

ld csinh(ld x) {
  return (exp(x) - exp(-x)) / 2;
}

int main() {
  ld d, s; cin >> d >> s;
  function<bool(ld)> pred = [&](ld a) {
    return a * ccosh(d / 2 / a) - a - s <= 0;
  };
  ld a = minst(pred, (ld) 0.0000001, (ld) 1e18);
  cout << setprecision(12) << fixed << 2 * a * csinh(d / 2 / a) << endl;
}
