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
const int mod = inf;
const ll infll = 0x3f3f3f3f3f3f3f3fll;

ll exgcd(ll a, ll b, ll &x, ll &y) {
  if (!b) {x = 1; y = 0; return a;}
  ll d = exgcd(b, a % b, x, y), t = x;
  x = y; y = t - a / b * y;
  return d;
}

int main() {
  int n; cin >> n;
  while (n--) {
    ll a1, b1, a2, b2, a, b; cin >> a1 >> b1 >> a2 >> b2 >> a >> b;
    ll xd = a2 * b - a * b2, d = a2 * b1 - a1 * b2;
    if (d) {
      if (!(xd % d)) {
        ll x = xd / d;
        if (x <= 0) {
          cout << '?' << endl;
        } else {
          ll ya2 = a - a1 * x;
          if (!(ya2 % a2)) {
            ll y = ya2 / a2;
            if (y <= 0) {
              cout << '?' << endl;
            } else {
              cout << x << ' ' << y << endl;
            }
          } else {
            cout << '?' << endl;
          }
        }
      } else {
        cout << '?' << endl;
      }
    } else {
      if (xd) {
        cout << '?' << endl;
      } else {
        ll c, d;
        ll g = exgcd(a1, a2, c, d);
        if (!(a % g)) {
          ll k = a / g, a1g = a1 / g, a2g = a2 / g;
          c *= k; d *= k;
          ll m = c > 0 ? -((c - 1) / a2g) : ((1 - c) + a2g - 1) / a2g;
          c += m * a2g;
          d -= m * a1g;
          if (d > 0 && d - a1g <= 0) {
            cout << c << ' ' << d << endl;
          } else {
            cout << '?' << endl;
          }
        } else {
          cout << '?' << endl;
        }
      }
    }
  }
}