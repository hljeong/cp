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
  int f; cin >> f;
  bool ans = true;
  for (int i = 0; i < f; ++i) {
    int t, n; cin >> t >> n;
    si p;
    for (int j = 0; j <= t; ++j) p.insert(j);
    for (int j = 0; j < n; ++j) {
      int a, b, d; cin >> a >> b; d = b - a;
      si np;
      for (int k : p) {
        if (k - d >= 0) np.insert(k - d);
        if (k + d <= t) np.insert(k + d);
      }
      p = np;
    }
    ans &= !!p.size();
  }
  cout << (ans ? "possible" : "impossible") << endl;
}
