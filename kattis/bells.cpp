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

vc<vi> solve(int n) {
  if (n == 1) return vc<vi>(1, vi(1, 1));
  vc<vi> sub = solve(n - 1), ret;
  for (int i = 0; i < sub.size(); ++i) {
    if (i & 1) {
      for (int j = 0; j < n; ++j) {
        vi p;
        for (int k = 0; k < n - 1; ++k) {
          if (k == j) p.pb(n);
          p.pb(sub[i][k]);
        }
        if (j == n - 1) p.pb(n);
        ret.pb(p);
      }
    } else {
      for (int j = n - 1; j >= 0; --j) {
        vi p;
        for (int k = 0; k < n - 1; ++k) {
          if (k == j) p.pb(n);
          p.pb(sub[i][k]);
        }
        if (j == n - 1) p.pb(n);
        ret.pb(p);
      }
    }
  }
  return ret;
}

int main() {
  int n; cin >> n;
  vc<vi> ret = solve(n);
  for (vi p : ret) for (int i = 0; i < n; ++i) cout << p[i] << " \n"[i == n - 1];
}
