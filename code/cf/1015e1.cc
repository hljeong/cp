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

tTU> T max(T a, U b) { return a > b ? a : b; }
tTU> T min(T a, U b) { return a < b ? a : b; }
tTU> bool ckmin(T &a, U b) { return b < a ? a = b, 1 : 0; }
tTU> bool ckmax(T &a, U b) { return a < b ? a = b, 1 : 0; }
tT> T nth_bit(T x, int n) { return (x >> n) & 1; }
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

// take biggest star at each coord

void solve() {
  int n = ri(), m = ri();
  vc<vi> g(n + 1, vi(m + 1)),
         u(n + 1, vi(m + 1)),
         d(n + 1, vi(m + 1)),
         l(n + 1, vi(m + 1)),
         r(n + 1, vi(m + 1));
  int cnt = 0;
  for (int i = 0; i < n; i++) {
    auto row = rs();
    for (int j = 0; j < m; j++) {
      g[i][j] = u[i][j] = d[i][j] = l[i][j] = r[i][j] = row[j] == '*';
      cnt += g[i][j];
    }
  }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      u[i + 1][j] = g[i + 1][j] ? 1 + u[i][j] : 0;
      d[n - i - 1][j] = g[n - i - 1][j] ? 1 + d[n - i][j] : 0;
      l[i][j + 1] = g[i][j + 1] ? 1 + l[i][j] : 0;
      r[i][m - j - 1] = g[i][m - j - 1] ? 1 + r[i][m - j] : 0;
    }
  }

  using a3 = ar<int, 3>;
  vc<a3> ans;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      int sz = min(min(u[i][j], d[i][j]), min(l[i][j], r[i][j]));
      if (sz > 1) {
        ans.pb({i + 1, j + 1, sz - 1});
        for (int d = 0; d < sz; d++) {
          if (g[i - d][j]) g[i - d][j] = 0, --cnt;
          if (g[i + d][j]) g[i + d][j] = 0, --cnt;
          if (g[i][j - d]) g[i][j - d] = 0, --cnt;
          if (g[i][j + d]) g[i][j + d] = 0, --cnt;
        }
      }
    }
  }
  if (cnt) cout << "-1\n";
  else {
    cout << ans.size() << endl;
    for (auto &p : ans) {
      cout << p << endl;
    }
  }
}

int main() {
  cin.tie(0)->sync_with_stdio(0);

  int t = 1;
  // int t = ri();
  while (t--) solve();
}

#endif
