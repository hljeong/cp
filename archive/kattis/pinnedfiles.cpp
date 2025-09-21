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
  int pi, ui, n; cin >> pi >> ui; n = pi + ui;
  vi ai(n); for (int i = 0; i < n; ++i) cin >> ai[i];
  int pf, uf; cin >> pf >> uf;
  vi af(n); for (int i = 0; i < n; ++i) cin >> af[i];
  mii ind;
  for (int i = 0; i < n; ++i) {
    ind[ai[i]] = i;
  }
  si s;
  for (int i = 0; i < pi; ++i) s.insert(af[i]);
  int l = 0, r = n - 1;
  vi pord, sord;
  for (int i = 0; i < n; ++i) {
    if (s.count(ai[i])) {
      if (i < pi)
        pord.pb(ai[i]);
    } else {
      if (i >= pi)
        sord.pb(ai[i]);
    }
  }
  for (int i : pord) {
    if (l < pf && af[l] == i) ++l;
  }
  reverse(sord.begin(), sord.end());
  for (int i : sord) {
    if (r >= pf && af[r] == i) --r;
  }
  // cout << l << ' ' << r << endl;
  int ret = 0;
  for (int i = l; i <= r; ++i) {
    int j = ind[af[i]];
    if (i < pf) {
      if (j < pi) ret += 2;
      else ++ret;
    } else {
      if (j >= pi) ret += 2;
      else ++ret;
    }
  }
  cout << ret << endl;
}
