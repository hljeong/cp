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
template<class T> bool ckmax(T &a, const T &b) { return a < b ? a = b, 1 : 0; }

const int inf = 1e9 + 7;
const int mod = inf;
const ll infll = 0x3f3f3f3f3f3f3f3fll;

vll rret;

int q(ll l, ll r) {
  cout << "q " << l << ' ' << r << endl << flush;
  int ret; cin >> ret;
  return ret;
}

void solve(ll l, ll r, int cnt = -1) {
  if (cnt == -1) cnt = q(l, r);
  if (!cnt) return;
  if (l == r) {
    rret.pb(l);
    return;
  }
  ll m = l + (r - l) / 2;
  int lcnt = q(l, m), rcnt = cnt - lcnt;
  if (lcnt) solve(l, m, lcnt);
  if (rcnt) solve(m + 1, r, rcnt);
}

int main() {
  solve(0, (1ll << 63) - 1);
  cout << "a " << rret.size();
  for (int i = 0; i < rret.size(); ++i) cout << ' ' << rret[i];
  cout << endl;
}
