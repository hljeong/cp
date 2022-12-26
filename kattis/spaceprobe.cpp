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
  int n, k; ll t1, t2; cin >> n >> k >> t1 >> t2;
  vll m(n); for (int i = 0; i < n; ++i) cin >> m[i];
  vc<pair<ll, ll>> segs;
  for (int i = 0; i < k; ++i) {
    ll b, e; cin >> b >> e;
    for (int j = 0; j < n; ++j) {
      segs.pb({b - m[j], e - m[j]});
    }
  }
  ld ret = 0;
  sort(segs.begin(), segs.end());
  ll last = t1;
  for (pair<ll, ll> seg : segs) {
    ret += max(0ll, min(seg.B, t2) - max(seg.A, last));
    ckmax(last, seg.B);
  }
  ret /= t2 - t1;
  ret = 1 - ret;
  cout << ret << endl;
}
