#include <bits/stdc++.h>
#define A first
#define B second
#define vc vector
using namespace std;
using ll = long long; using ld = long double;
using vi = vc<int>; using vll = vc<ll>;
using si = set<int>; using sll = set<ll>;
using pii = pair<int, int>; using mii = map<int, int>;
using gr = vc<vi>;

template<class T> bool ckmin(T &a, const T &b) { return b < a ? a = b, 1 : 0; }
template<class T> bool ckmax(T &a, const T &b) { return a < b ? a = b, 1 : 0; }

const int inf = 1e9 + 7;
const int mod = inf;

int exgcd(int a, int b, int &x, int &y) {
  if (!b) {x = 1; y = 0; return a;}
  int d = exgcd(b, a % b, x, y), t = x;
  x = y; y = t - a / b * y;
  return d;
}

ll exgcd(ll a, ll b, ll &x, ll &y) {
  if (!b) {x = 1; y = 0; return a;}
  ll d = exgcd(b, a % b, x, y), t = x;
  x = y; y = t - a / b * y;
  return d;
}

int crt(const vi &a, const vi &m) {
  int ans = a[0], lcm = m[0], n = a.size();
  for (int i = 1; i < n; ++i) {
    int x, y, d = exgcd(lcm, m[i], x, y);
    if ((a[i] - ans) % d) return -1;
    ans += x * (a[i] - ans) / d % (m[i] / d) * lcm;
    lcm *= m[i] / d;
    ans %= lcm;
    if (ans < 0) ans += lcm;
  }
  return ans;
}

ll crt(const vll &a, const vll &m) {
  ll ans = a[0], lcm = m[0], n = a.size();
  for (int i = 1; i < n; ++i) {
    ll x, y, d = exgcd(lcm, m[i], x, y);
    if ((a[i] - ans) % d) return -1;
    ans += x * (a[i] - ans) / d % (m[i] / d) * lcm;
    lcm *= m[i] / d;
    ans %= lcm;
    if (ans < 0) ans += lcm;
  }
  return ans;
}

ll normalize(ll x, ll m) {
    x %= m;
    if (x < 0) x += m;
    return x;
}

int main() {
  int t; cin >> t;
  while (t--) {
    ll ws, hs, wl, hl, xl, yl; cin >> ws >> hs >> wl >> hl >> xl >> yl;
    ll a = normalize(-xl, ws - wl), b = normalize(-yl, hs - hl);
    ll _, __;
    vll ca, cm;
    ca.push_back(a); ca.push_back(b);
    cm.push_back(ws - wl); cm.push_back(hs - hl);
    ll t = crt(ca, cm);
    if (t == -1) cout << "Johnny will die waiting" << endl;
    else cout << normalize(t, (ws - wl) / exgcd(ws - wl, hs - hl, _, __) * (hs - hl)) << endl;
  }
}
