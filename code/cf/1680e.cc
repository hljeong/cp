#include <bits/stdc++.h>
#define A first
#define B second
#define pb push_back
#define endl '\n'
#define tT template <typename T
#define tTU tT, class U
using namespace std;
tT > using vc = vector<T>;
using ll = long long;
using ld = long double;
using vi = vc<int>;
using vll = vc<ll>;
using si = set<int>;
using sll = set<ll>;
using pi = pair<int, int>;
using pll = pair<ll, ll>;
using qi = queue<int>;
using mi = map<int, int>;

tT > ostream &operator<<(ostream &os, const vc<T> &a) {
  for (int i = 0, n = a.size(); i < n; i++)
    os << a[i] << " \n"[i == n - 1];
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
ll rll() { return rd<ll>(); }
string rs() { return rd<string>(); }
vi ria(int n) { return rda<int>(n); }
vll rlla(int n) { return rda<ll>(n); }

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

// answer is weight of mst

void solve() {
  int n;
  cin >> n;
  vi a(n);
  string r1 = rs(), r2 = rs();
  for (int i = 0; i < n; i++) {
    a[i] = (r1[i] == '*') | ((r2[i] == '*') << 1);
  }
  vc<vi> dp(n + 1, vi(4, inf));
  bool seen = false;
  dp[0][0] = 0;
  for (int i = 0; i < n; i++) {
    if (!a[i]) {
      ckmin(dp[i + 1][0], dp[i][0]);
      ckmin(dp[i + 1][0], dp[i][1]);
      ckmin(dp[i + 1][0], dp[i][2]);
      ckmin(dp[i + 1][0], dp[i][3]);
    }

    for (int j = 1; j < 4; j++) {
      // skip illegal state
      if ((j & a[i]) != a[i])
        continue;
      if (!seen)
        ckmin(dp[i + 1][j], dp[i][0]);
      // 1 to connect from left to right, add vertical connection if required
      ckmin(dp[i + 1][j], dp[i][1] + 1 + !(j & 1));
      ckmin(dp[i + 1][j], dp[i][2] + 1 + !(j & 2));
      ckmin(dp[i + 1][j], dp[i][3] + 1);

      // vertical connection required for this state
      dp[i + 1][j] += (j == 3);
    }

    if (a[i])
      seen = true;
  }
  cout << min(min(dp[n][0], dp[n][1]), min(dp[n][2], dp[n][3])) << endl;
}

int main() {
  cin.tie(0)->sync_with_stdio(0);

  // int t = 1;
  int t = ri();
  while (t--) {
    solve();
  }
}
