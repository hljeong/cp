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

using ar = array<int, 10>;

int main() {
  int n, m, d; cin >> n >> m >> d;
  ar s = {0};
  int sum = 0;
  for (int i = 0; i < n; ++i) {
    cin >> s[i];
    sum += s[i];
  }
  for (int i = 0; i < m; ++i) {
    cin >> s[5 + i];
    sum += s[5 + i];
  }
  sort(s.begin(), s.begin() + 5);
  sort(s.begin() + 5, s.begin() + 10);
  if (d >= sum) {
    cout << setprecision(10) << fixed << 1 << endl;
    return 0;
  }
  map<ar, ld> dp;
  dp[s] = 1;
  ld ret = 0;
  for (int i = 0; i < d; ++i) {
    map<ar, ld> ndp;
    for (const auto &e : dp) {
      ar a = e.A;
      ld p = e.B;
      int nonzero1 = 0, nonzero2 = 0;
      for (int j = 0; j < 5; ++j) nonzero1 += !!a[j];
      for (int j = 5; j < 10; ++j) nonzero2 += !!a[j];
      p /= nonzero1 + nonzero2;
      for (int j = 4; j >= 0; --j) {
        if (!a[j]) break;
        if (!(--a[j])) --nonzero1;
        ar b = a;
        sort(b.begin(), b.begin() + 5);
        ndp[b] += p;
        if (!(a[j]++)) ++nonzero1;
      }
      for (int j = 4; j >= 0; --j) {
        if (!a[5 + j]) continue;
        if (!(--a[5 + j])) --nonzero2;
        if (!nonzero2) {
          ret += p;
        } else {
          ar b = a;
          sort(b.begin() + 5, b.begin() + 10);
          ndp[b] += p;
        }
        if (!(a[5 + j]++)) ++nonzero2;
      }
    }
    dp = ndp;
  }

  cout << setprecision(10) << fixed << ret << endl;
}
