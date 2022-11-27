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

ll qpow(ll b, ll e) {
  if (!b) return 0;
  ll ret = 1;
  while (e) {
    if (e & 1) ret *= b;
    b *= b;
    e >>= 1;
  }
  return ret;
}

int main() {
  ll a, b; cin >> a >> b;
  vc<si> mods(11, si());
  for (int i = 1; i <= 10; ++i) {
    int cur = 1;
    for (int j = 0; j < 10; ++j) {
      mods[cur].insert(i);
      cur *= i;
      cur %= 10;
    }
  }
  vi ret(to_string(a).length());
  function<bool(ll, ll, int)> solve = [&](ll x, ll y, int i) {
    if (!x) return !y;
    int dx = x % 10, dy = y % 10;
    if (!mods[dy].count(dx)) return false;
    ll e = 0, cur = 1;
    while (cur <= y) {
      if (!((y - cur) % 10)) {
        ret[i] = (int) e;
        if (solve(x / 10, (y - cur) / 10, i - 1)) return true;
      }
      ++e;
      cur *= dx;
    }
    return false;
  };
  solve(a, b, ret.size() - 1);
  for (int i = 0; i < ret.size(); ++i) cout << ret[i] << " \n"[i == ret.size() - 1];
}
