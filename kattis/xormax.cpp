#include <bits/stdc++.h>
#define A first
#define B second
#define vc vector
#define pb push_back
#define endl '\n'
using namespace std;
using ll = long long; using ld = long double;
using vi = vc<int>; using vll = vc<ll>;
using si = set<int>; using sll = set<ll>;
using pi = pair<int, int>; using pll = pair<ll, ll>;
using qi = queue<int>; using mi = map<int, int>;

template<class T> bool ckmin(T &a, const T &b) { return b < a ? a = b, 1 : 0; }
template<class T> bool ckmax(T &a, const T &b) { return a < b ? a = b, 1 : 0; }

const int inf = 1e9 + 7;
const int mod = inf;
const ll infll = 0x3f3f3f3f3f3f3f3fll;

// find basis
int main() {
  cin.tie(0) -> sync_with_stdio(0);

  int n; cin >> n;
  set<ll> a;
  for (int i = 0; i < n; ++i) {
    ll ai;
    cin >> ai;
    a.insert(ai);
  }
  vll basis;
  vi bit;
  for (int i = 62; i >= 0; --i) {
    for (ll aj : a) {
      for (int k = 0; k < basis.size(); ++k) {
        if (aj & (1ll << bit[k])) {
          aj ^= basis[k];
        }
      }
      if (aj & (1ll << i)) {
        basis.pb(aj);
        bit.pb(i);
        break;
      }
    }
  }
  ll ret = 0;
  for (ll x : basis) {
    ckmax(ret, ret ^ x);
  }
  cout << ret << endl;
}
