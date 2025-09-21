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

int main() {
  int h; cin >> h;
  vi hi(h); for (int i = 0; i < h; ++i) cin >> hi[i];
  int b; cin >> b;
  vi bi(b); for (int i = 0; i < b; ++i) cin >> bi[i];
  vi dp1(100001, inf), dp2(100001, inf);
  dp1[0] = dp2[0] = 0;
  for (int i = 0; i < h; ++i) {
    for (int j = 100000 - hi[i]; j >= 0; --j) {
      if (dp1[j] < inf)
        ckmin(dp1[j + hi[i]], dp1[j] + 1);
    }
  }
  for (int i = 0; i < b; ++i) {
    for (int j = 100000 - bi[i]; j >= 0; --j) {
      if (dp2[j] < inf)
        ckmin(dp2[j + bi[i]], dp2[j] + 1);
    }
  }
  int ret = inf;
  for (int i = 1; i <= 100000; ++i) {
    ckmin(ret, dp1[i] + dp2[i]);
  }
  if (ret == inf) cout << "impossible" << endl;
  else cout << ret << endl;
}