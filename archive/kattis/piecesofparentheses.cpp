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

int main() {
  int n; cin >> n;
  vc<pair<int, pii>> p(n);
  for (int i = 0; i < n; ++i) {
    string s; cin >> s;
    int b = 0, m = 0;
    for (int j = 0; j < s.length(); ++j) {
      if (s[j] == '(') ++b;
      else --b;
      ckmin(m, b);
    }
    p[i] = {m, {b, s.length()}};
  }
  sort(p.rbegin(), p.rend());
  vi dp(90005, -1), hi(90005, 0);
  dp[0] = 0;
  for (int i = 0; i < n; ++i) {
    vi ndp = dp;
    for (int j = 0; j <= 90000; ++j) {
      int min_dip = p[i].A, delta = p[i].B.A, len = p[i].B.B;
      int nb = j + delta;
      if (dp[j] == -1) continue;
      if (hi[j] + min_dip < 0) continue;
      if (nb < 0 || nb > 90000) continue;
      if (ckmax(ndp[nb], dp[j] + len)) hi[nb] = hi[j] + max(0, delta);
      else if (ndp[nb] == dp[j] + len) ckmax(hi[nb], hi[j] + delta);
    }
    dp = ndp;
  }
  cout << dp[0] << endl;
}
