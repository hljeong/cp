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
  ll ret = 0;
  bool good = true;
  for (int i = 1; i <= n; ++i) {
    ll fact = 1;
    for (int j = i; j <= n; ++j) {
      fact *= j;
      if (fact > 1000000000) {
        good = false;
        break;
      }
    }
    if (!good) break;
    ret += fact;
    if (ret > 1000000000) {
      good = false;
      break;
    }
  }
  if (good) {
    cout << ret << endl;
  } else {
    cout << "JUST RUN!!" << endl;
  }
}
