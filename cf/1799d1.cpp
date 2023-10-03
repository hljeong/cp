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

  int t; cin >> t;
  while (t--) {
    int n, k; cin >> n >> k;
    vi a(n); for (int i = 0; i < n; ++i) cin >> a[i];
    vi c(k + 1), h(k + 1);
    for (int i = 1; i <= k; ++i) cin >> c[i];
    for (int i = 1; i <= k; ++i) cin >> h[i];
    vll dp(k + 1, infll);
    dp[0] = c[a[0]];
    for (int i = 1; i < n; ++i) {
      vll ndp(k + 1, infll);
      int l1 = a[i - 1];
      for (int l2 = 0; l2 <= k; ++l2) {
        // assign to cpu 1
        ckmin(ndp[l2], dp[l2] + (l1 == a[i] ? h[a[i]] : c[a[i]]));
        // assign to cpu 2
        ckmin(ndp[l1], dp[l2] + (l2 == a[i] ? h[a[i]] : c[a[i]]));
      }
      dp = ndp;
    }
    ll ret = infll;
    for (int i = 0; i <= k; ++i) ckmin(ret, dp[i]);
    cout << ret << endl;
  }
}
