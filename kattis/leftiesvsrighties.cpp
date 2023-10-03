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

int main() {
  cin.tie(0) -> sync_with_stdio(0);

  int t, n; cin >> t >> n;
  vi l(n), r(n);
  for (int i = 0; i < n; ++i) {
    int tp; cin >> tp; --tp;
    string p; cin >> p;
    if (p == "L") ++l[tp];
    else ++r[tp];
  }
  int good = 1, lc = 0, rc = 0, ret = 0;
  vi u(t);
  for (int i = 0; i < t; ++i) {
    if (!l[i] && !r[i]) {
      good = 0;
      break;
    } else if (!l[i]) {
      --r[i];
      ++rc;
      u[i] = 1;
      ++ret;
    } else if (!r[i]) {
      --l[i];
      ++lc;
      u[i] = 1;
      ++ret;
    }
  }
  if (!good) {
    cout << -1 << endl;
    return 0;
  }
  for (int i = 0; i < t; ++i) {
    if (!u[i]) {
      if (rc < lc) {
        --r[i]; ++rc;
      } else {
        --l[i]; ++lc;
      }
      ++ret;
    }
  }
  for (int i = 0; i < t; ++i) {
    if (rc > lc) {
      int delta = min(rc - lc, l[i]);
      ret += delta;
      lc += delta;
    } else {
      int delta = min(lc - rc, r[i]);
      ret += delta;
      rc += delta;
    }
  }
  if (rc != lc) {
    cout << -1 << endl;
  } else {
    cout << ret << endl;
  }
}
