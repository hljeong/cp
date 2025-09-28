#include <bits/stdc++.h>
#define A first
#define B second
#define pb push_back
#define endl '\n'
#define tT template <typename T
#define tTU tT, class U
using namespace std;
tT > using vc = vector<T>;
tT, int N > using ar = array<T, N>;
using ll = long long;
using ld = long double;
using vi = vc<int>;
using vll = vc<ll>;
using si = set<int>;
using sll = set<ll>;
using pi = pair<int, int>;
using pll = pair<ll, ll>;
using qi = queue<int>;
using mii = map<int, int>;
using str = string;

tT > ostream &operator<<(ostream &os, const vc<T> &a) {
  for (int i = 0, n = a.size(); i < n; i++) {
    if (i)
      os << " ";
    os << a[i];
  }
  return os;
}

tT, int N > ostream &operator<<(ostream &os, const ar<T, N> &a) {
  for (int i = 0; i < N; i++) {
    if (i)
      os << " ";
    os << a[i];
  }
  return os;
}

tT > T rd() {
  T x;
  cin >> x;
  return x;
}

tT > vc<T> rda(int n) {
  vc<T> v(n);
  for (int i = 0; i < n; i++) {
    cin >> v[i];
  }
  return v;
}

int ri() { return rd<int>(); }
ll rl() { return rd<ll>(); }
str rs() { return rd<str>(); }
vi ria(int n) { return rda<int>(n); }
vll rla(int n) { return rda<ll>(n); }

tTU > T max(T a, U b) { return a > b ? a : b; }
tTU > T min(T a, U b) { return a < b ? a : b; }
tTU > bool ckmin(T &a, U b) { return b < a ? a = b, 1 : 0; }
tTU > bool ckmax(T &a, U b) { return a < b ? a = b, 1 : 0; }
tT > T nth_bit(T x, int n) { return (x >> n) & 1; }
tTU > T minst(T l, T r, U pred) {
  T ans = r + 1;
  while (l <= r) {
    T m = l + (r - l) / 2;
    if (pred(m))
      r = (ans = m) - 1;
    else
      l = m + 1;
  }
  return ans;
}
tTU > T maxst(T l, T r, U pred) {
  T ans = l - 1;
  while (l <= r) {
    T m = l + (r - l) / 2;
    if (pred(m))
      l = (ans = m) + 1;
    else
      r = m - 1;
  }
  return ans;
}

constexpr int inf = 1e9 + 7;
constexpr int mod = inf;
constexpr ll infll = 0x3f3f'3f3f'3f3f'3f3fll;

// dp[i] at kth iter = min cost to have k peaks, last one being at i
// 2 cases for transition: transition from dp[i - 2] -> a[i - 1] must have been
// reduced to min(a[i - 1], a[i - 2] - 1), keep reducing from there if needed
// otherwise last peak doesnt affect us. take prefix min: min(dp[0 : i - 2])

void solve() {
  int n;
  cin >> n;
  vi a = ria(n);
  vi ans((n + 1) / 2, inf);
  vi dp(n, inf);
  for (int i = 0; i < n; i++) {
    ckmin(dp[i], (i ? max(0, a[i - 1] - (a[i] - 1)) : 0) +
                     ((i < n - 1) ? max(0, a[i + 1] - (a[i] - 1)) : 0));
    ckmin(ans[0], dp[i]);
  }
  // cout << dp << endl;
  for (int i = 1; i * 2 < n; i++) {
    vi p(n + 1, inf), ndp(n, inf);
    for (int j = 0; j < n; j++)
      p[j + 1] = min(p[j], dp[j]);
    // cout << "p: " << p << endl;
    for (int j = 2 * i; j < n; j++) {
      const int r = (j < n - 1) ? max(0, a[j + 1] - (a[j] - 1)) : 0;

      ckmin(ndp[j],
            dp[j - 2] + r + max(0, min(a[j - 2] - 1, a[j - 1]) - (a[j] - 1)));

      if (j >= 3)
        ckmin(ndp[j], p[j - 2] + r + max(0, a[j - 1] - (a[j] - 1)));

      ckmin(ans[i], ndp[j]);
    }
    dp = ndp;
    // cout << dp << endl;
  }
  cout << ans << endl;
}

int main() {
  cin.tie(0)->sync_with_stdio(0);

  int t = 1;
  // int t = ri();
  while (t--) {
    solve();
  }
}
