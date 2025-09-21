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
  vc<pii> pts(n);
  for (int i = 0; i < n; ++i) {
    int x, w; cin >> x >> w;
    pts[i] = {x, w};
  }
  sort(pts.begin(), pts.end(), [&](pii a, pii b) {
    return a.A + a.B < b.A + b.B;
  });
  vi dp(n, 1);
  set<pii> store;
  for (int i = 0; i < n; ++i) {
    auto it = store.upper_bound({pts[i].A - pts[i].B, inf});
    if (it != store.begin()) {
      --it;
      dp[i] = it->B + 1;
    }
    if (i) ckmax(dp[i], dp[i - 1]);
    store.insert({pts[i].A + pts[i].B, dp[i]});
  }
  /*
  for (int i = 0; i < n; ++i) {
    cout << dp[i] << " \n"[i == n - 1];
  }
  */
  cout << dp[n - 1] << endl;
}
