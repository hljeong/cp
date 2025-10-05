#ifndef TMPL
#define TMPL
#include <bits/stdc++.h>
#define A first
#define B second
#define pb push_back
#define endl '\n'
#define tT template <typename T
#define tTU tT, class U
using namespace std;
tT> using vc = vector<T>;
tT, int N> using ar = array<T, N>;
using ll = long long; using ld = long double;
using vi = vc<int>; using vll = vc<ll>;
using si = set<int>; using sll = set<ll>;
using pi = pair<int, int>; using pll = pair<ll, ll>;
using qi = queue<int>;
using mii = map<int, int>;
using str = string;

tT> ostream &operator<<(ostream &os, const vc<T> &a) {
  for (int i = 0, n = a.size(); i < n; i++) os << (i ? " " : "") << a[i];
  return os;
}

tT, size_t N> ostream &operator<<(ostream &os, const ar<T, N> &a) {
  for (int i = 0; i < N; i++) os << (i ? " " : "") << a[i];
  return os;
}

tT> T rd() { T x; cin >> x; return x; }

tT> vc<T> rda(int n) {
  vc<T> v(n);
  for (int i = 0; i < n; i++) cin >> v[i];
  return v;
}

int ri() { return rd<int>(); }
ll rll() { return rd<ll>(); }
str rs() { return rd<str>(); }
vi ria(int n) { return rda<int>(n); }
vll rlla(int n) { return rda<ll>(n); }

tTU> constexpr T max(T a, U b) { return a > b ? a : b; }
tTU> constexpr T min(T a, U b) { return a < b ? a : b; }
tTU> constexpr bool ckmin(T &a, U b) { return b < a ? a = b, 1 : 0; }
tTU> constexpr bool ckmax(T &a, U b) { return a < b ? a = b, 1 : 0; }
tT> constexpr T nth_bit(T x, int n) { return (x >> n) & 1; }
tTU> T minst(T l, T r, U pred) {
  T ans = r + 1;
  while (l <= r) {
    T m = l + (r - l) / 2;
    if (pred(m)) r = (ans = m) - 1;
    else l = m + 1;
  }
  return ans;
}
tTU> T maxst(T l, T r, U pred) {
  T ans = l - 1;
  while (l <= r) {
    T m = l + (r - l) / 2;
    if (pred(m)) l = (ans = m) + 1;
    else r = m - 1;
  }
  return ans;
}

constexpr int inf = 1e9 + 7;
constexpr int mod = inf;
constexpr ll infll = 0x3f3f'3f3f'3f3f'3f3fll;

// there are only n possibilities:
// zig-zag up and down for k columns and then go out and back

void solve() {
  int n; cin >> n;
  vc<vll> v{rlla(n), rlla(n)};
  if (n == 1) {
    cout << v[1][0] << endl;
    return;
  }
  vll suf(n + 1);
  for (int i = n - 1; i >= 0; i--) {
    suf[i] = suf[i + 1] + v[0][i] + v[1][i];
  }
  vll out_and_back(n + 1);
  out_and_back[n - 1] = v[((n - 1) & 1) ^ 1][n - 1];
  out_and_back[n - 2] = v[(n - 2) & 1][n - 1] * 1
                      + v[((n - 2) & 1) ^ 1][n - 1] * 2
                      + v[((n - 2) & 1) ^ 1][n - 2] * 3;
  for (int i = n - 3; i >= 0; i--) {
    int parity = i & 1;
    int cnt = (n - i) * 2;
    out_and_back[i] = suf[i + 2] * 2 + out_and_back[i + 2]
                    + v[parity][i + 1]
                    + v[parity ^ 1][i + 1] * (cnt - 2)
                    + v[parity ^ 1][i] * (cnt - 1);
  }
  ll ans = 0, cur = 0;
  for (int i = 0; i < n; i++) {
    ckmax(ans, cur + 2 * i * suf[i] + out_and_back[i]);
    int parity = i & 1;
    cur += v[parity][i] * (2 * i) + v[parity ^ 1][i] * (2 * i + 1);
  }
  cout << max(ans, cur) << endl;
}

int main() {
  cin.tie(0)->sync_with_stdio(0);

  int t = 1;
  // int t = ri();
  while (t--) solve();
}

#endif
