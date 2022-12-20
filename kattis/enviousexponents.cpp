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

int main() {
  ll n; cin >> n;
  int k, i; cin >> k;
  ll ret = 0;
  for (i = 59; i >= 0; --i) {
    if ((n >> i) & 1) {
      ret |= 1ll << i;
      if (--k == 0) {
        break;
      }
    }
  }
  if (!k) {
    while ((n >> i) & 1) {
      ret &= ~(1ll << i);
      ++k; ++i;
    }
    ret |= 1ll << i;
    --k;
  }
  i = 0;
  while (k) {
    if (!((ret >> i) & 1)) {
      ret |= 1ll << i;
      --k;
    }
    ++i;
  }
  cout << ret << endl;
}
