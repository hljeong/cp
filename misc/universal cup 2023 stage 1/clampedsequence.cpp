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

ll clamp(ll x, ll l, ll r) {
  return x < l ? l : x > r ? r : x;
}

int main() {
  int n, d; cin >> n >> d;
  vll a(n); for (int i = 0; i < n; ++i) cin >> a[i];
  ll ret = 0;
  for (int i = 0; i < n; ++i) {
    ll cret = 0;
    for (int j = 1; j < n; ++j) {
      cret += abs(clamp(a[j - 1], a[i], a[i] + d) - clamp(a[j], a[i], a[i] + d));
    }
    ckmax(ret, cret);
  }
  for (int i = 0; i < n; ++i) {
    ll cret = 0;
    for (int j = 1; j < n; ++j) {
      cret += abs(clamp(a[j - 1], a[i] - d, a[i]) - clamp(a[j], a[i] - d, a[i]));
    }
    ckmax(ret, cret);
  }
  cout << ret << endl;
}
