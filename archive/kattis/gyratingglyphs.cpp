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

const int P = 22;

ll qry(vi &a) {
  cout << '?';
  for (int i : a) cout << ' ' << i;
  cout << endl << flush;
  ll q; cin >> q;
  return q;
}

int main() {
  int n; cin >> n;
  if (n >= 15) {
    map<ll, int> get;
    for (int mask = 0; mask < (1 << 15); ++mask) {
      ll ret = P;
      for (int i = 0; i < 15; ++i) {
        if ((mask >> i) & 1) ret = (ret + P) % mod;
        else ret = (ret * P) % mod;
      }
      get[ret] = mask;
    }
    vi a(n + 1, 1);
    ll np = qry(a) - 1, cp = np;
    for (int i = 0; i <= n - 16; i += 15) {
      for (int j = 0; j < 16; ++j) a[i + j] = P;
      ll q = qry(a); int mask = 0;
      for (int j = 0; j <= 15; ++j) {
        ll t = (q + mod - (cp - j)) % mod;
        if (get.count(t)) {
          mask = get[t];
          break;
        }
      }
      for (int j = 0; j < 15; ++j) a[i + j] = !((mask >> j) & 1);
      cp -= __builtin_popcount(mask);
    }
    for (int i = n - 15; i <= n; ++i) a[i] = P;
    int mask = get[qry(a)];
    for (int i = 0; i < 15; ++i) a[n - 15 + i] = !((mask >> i) & 1);
    cout << "! ";
    for (int i = 0; i < n; ++i) cout << (a[i] ? 'x' : '+');
    cout << endl;
  } else {
    vi a(n + 1, 1);
    ll np = qry(a);
    for (int i = n; i > 0; --i) {
      a[i] = 0;
      ll q = qry(a);
      if (!q) a[i] = 1;
      else a[i] = 0;
    }
    cout << "! ";
    for (int i = 1; i <= n; ++i) cout << (a[i] ? 'x' : '+');
    cout << endl;
  }
}
