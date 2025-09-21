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

using frog = array<int, 3>;

int main() {
  int n, d, mxw = 0; cin >> n >> d;
  vc<frog> f(n);
  for (int i = 0; i < n; ++i) {
    cin >> f[i][0] >> f[i][1] >> f[i][2];
    ckmax(mxw, f[i][1]);
  }

  sort(f.begin(), f.end(), [&](frog a, frog b) {
    return b[1] < a[1];
  });
  vi dp(mxw * 2);
  int ret = 0;
  for (int i = 0; i < n; ++i) {
    if (dp[f[i][1]] + f[i][0] > d) ++ret;
    for (int j = 1; j < f[i][1]; ++j) {
      ckmax(dp[j], dp[j + f[i][1]] + f[i][2]);
      ckmin(dp[j], d + 1);
    }
  }
  cout << ret << endl;
}
