#ifndef TMPL
#define TMPL
#include <bits/stdc++.h>
#define A first
#define B second
#define pb push_back
#define endl '\n'
#define tT template <class T
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

tTU> istream& operator>>(istream &i, pair<T, U> &p) { return i >> p.A >> p.B; }

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

tTU> constexpr decltype(declval<T>() + declval<U>()) max(T a, U b) { return a > b ? a : b; }
tTU> constexpr decltype(declval<T>() + declval<U>()) min(T a, U b) { return a < b ? a : b; }
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

// ucla tryout #2 2024 virtual

void solve() {
  vc<vi> g(10, vi(10));
  for (int i = 0; i < 10; i++) {
    auto s = rs();
    for (int j = 0; j < 10; j++) {
      g[i][j] = s[j] - '0';
    }
  }
  vi row(10), col(10), shape(10);
  vc<vi> st(10, vi(10));
  for (int i = 0; i < 10; i++) {
    auto s = rs();
    for (int j = 0; j < 10; j++) {
      st[i][j] = s[j] == '*';
      if (st[i][j]) {
        row[i]++;
        col[j]++;
        shape[g[i][j]]++;
      }
    }
  }
  for (int i = 0; i < 10; i++) {
    if (row[i] != 2) {
      cout << "invalid" << endl;
      return;
    }
    if (col[i] != 2) {
      cout << "invalid" << endl;
      return;
    }
    if (shape[i] != 2) {
      cout << "invalid" << endl;
      return;
    }
  }

  for (int i = 0; i < 10; i++) {
    for (int j = 0; j < 10; j++) {
      if (!st[i][j]) continue;
      for (int dx : {-1, 0, 1}) {
        for (int dy : {-1, 0, 1}) {
          if (!dx && !dy) continue;
          if (i + dx < 0) continue;
          if (i + dx >= 10) continue;
          if (j + dy < 0) continue;
          if (j + dy >= 10) continue;
          if (st[i + dx][j + dy]) {
            cout << "invalid" << endl;
            return;
          }
        }
      }
    }
  }
  cout << "valid" << endl;
}

int main() {
  cin.tie(0)->sync_with_stdio(0);

  int t = 1;
  // int t = ri();
  while (t--) solve();
}

#endif
