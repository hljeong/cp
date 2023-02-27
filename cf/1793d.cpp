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

int main() {
  int n; cin >> n;
  vi p(n), pi(n);
  for (int i = 0; i < n; ++i) {
    cin >> p[i]; --p[i];
    pi[p[i]] = i;
  }
  vi q(n), qi(n);
  for (int i = 0; i < n; ++i) {
    cin >> q[i]; --q[i];
    qi[q[i]] = i;
  }
  ll ret = 1;
  ll mn = min(pi[0], qi[0]), mx = max(pi[0], qi[0]);
  ret += (mn + 1) * mn / 2;
  ret += (mx - mn) * (mx - mn - 1) / 2;
  ret += (n - mx) * (n - mx - 1) / 2;
  int l = mn, r = mx, pmex = 1, qmex = 1, cur = 0;
  vi pv(n), qv(n);
  for (int i = l; i <= r; ++i) {
    pv[p[i]] = 1;
    qv[q[i]] = 1;
  }
  while (pmex < n && pv[pmex]) ++pmex;
  while (qmex < n && qv[qmex]) ++qmex;
  while (++cur < n) {
    ll nl = min(pi[cur], qi[cur]);
    ll nr = max(pi[cur], qi[cur]);
    if (pmex == cur && qmex == cur) {
      if (nl > r) {
        ret += (l + 1) * (nl - r);
      } else if (nr < l) {
        ret += (l - nr) * (n - r);
      } else {
        ret += (l - nl) * (nr - r);
      }
    }
    int pl = l, pr = r;
    ckmin(l, (int) nl);
    ckmax(r, (int) nr);
    for (int i = l; i < pl; ++i) {
      pv[p[i]] = 1;
      qv[q[i]] = 1;
    }
    for (int i = pr + 1; i <= r; ++i) {
      pv[p[i]] = 1;
      qv[q[i]] = 1;
    }
    while (pmex < n && pv[pmex]) ++pmex;
    while (qmex < n && qv[qmex]) ++qmex;
  }
  cout << ret << endl;
}
