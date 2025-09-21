#include <bits/stdc++.h>
#define A first
#define B second
#define vc vector
#define pb push_back
using namespace std;
using ll = long long; using ld = long double;
using vi = vc<int>; using vll = vc<ll>;
using si = set<int>; using sll = set<ll>;
using pii = pair<int, int>; using pll = pair<ll, ll>;
using mii = map<int, int>;

template<class T> bool ckmin(T &a, const T &b) { return b < a ? a = b, 1 : 0; }
template<class T> bool ckmax(T &a, const T &b) { return a < b ? a = b, 1 : 0; }

const int inf = 1e9 + 7;
const int mod = inf;
const ll infll = 0x3f3f3f3f3f3f3f3fll;

template<class T> T minst(function<bool(T)> pred, T i, T j) {
  T ret = j + 1;
  for (T l = i, r = j, m; l <= r; ) {
    if (pred(m = l + (r - l) / 2)) r = (ret = m) - 1;
    else l = m + 1;
  }
  return ret;
}

int main() {
  int h, w; cin >> h >> w;
  vi b(w); for (int i = 0; i < w; ++i) cin >> b[i];
  ll tot = (ll) h * w;
  for (int i = 0; i < w; ++i) tot -= b[i];
  function<ll(int)> calc = [&](int m) {
    ll cnt = 0;
    for (int i = 0; i < w; ++i) cnt += max(0, m - b[i]);
    return cnt;
  };
  function<bool(int)> pred = [&](int m) {
    ll cnt = calc(m);
    return cnt >= tot - cnt;
  };
  int ret1 = minst(pred, 0, h), ret2 = max(0, ret1 - 1);
  if (abs(tot - 2 * calc(ret1)) < abs(tot - 2 * calc(ret2))) {
    ll cnt = calc(ret1);
    if (!cnt) cout << "0 0" << endl;
    else cout << ret1 << ' ' << cnt << endl;
  } else {
    ll cnt = calc(ret2);
    if (!cnt) cout << "0 0" << endl;
    else cout << ret2 << ' ' << cnt << endl;
  }
}
