#ifndef TMPL
#define TMPL
#include <bits/stdc++.h>
#define A first
#define B second
#define pb push_back
#define endl '\n'
using namespace std;
template <class T> using vc = vector<T>;
template <class T, int N> using ar = array<T, N>;
using ll = long long; using ld = long double;
using vi = vc<int>; using vll = vc<ll>;
using si = set<int>; using sll = set<ll>;
using pi = pair<int, int>; using pll = pair<ll, ll>;
using qi = queue<int>;
using mii = map<int, int>;
using str = string;

template <ranges::range R>
requires (!(same_as<R, str> || same_as<R, string_view>))
ostream &operator<<(ostream &os, const R& range) {
  auto it = ranges::begin(range);
  auto end = ranges::end(range);
  for (bool first = true; it != end; it++) {
    if (!first) os << ' ';
    first = false;
    os << *it;
  }
  return os;
}

template <class T, class U>
istream& operator>>(istream &i, pair<T, U> &p) { return i >> p.A >> p.B; }

template <class T> T rd() { T x; cin >> x; return x; }

template <class T> vc<T> rda(int n) {
  vc<T> v(n);
  for (int i = 0; i < n; i++) cin >> v[i];
  return v;
}

int ri() { return rd<int>(); }
ll rll() { return rd<ll>(); }
str rs() { return rd<str>(); }
vi ria(int n) { return rda<int>(n); }
vll rlla(int n) { return rda<ll>(n); }

template <totally_ordered T, totally_ordered U>
constexpr auto max(T a, U b) -> common_type_t<T, U> { return a > b ? a : b; }

template <totally_ordered T, totally_ordered U>
constexpr auto min(T a, U b) -> common_type_t<T, U> { return a < b ? a : b; }

template <totally_ordered T, totally_ordered U>
constexpr bool ckmin(T &a, U b) { return b < a ? a = b, 1 : 0; }

template <totally_ordered T, totally_ordered U>
constexpr bool ckmax(T &a, U b) { return a < b ? a = b, 1 : 0; }

template <integral T>
constexpr T nth_bit(T x, int n) { return (x >> n) & 1; }

template <integral T, predicate<T> Pred>
T minst(T l, T r, Pred pred) {
  while (l < r) {
    T m = l + (r - l) / 2;
    if (pred(m)) r = m;
    else l = m + 1;
  }
  return l;
}

template <integral T, predicate<T> Pred>
T maxst(T l, T r, Pred pred) {
  while (l < r) {
    T m = l + (r - l) / 2;
    if (pred(m)) l = m + 1;
    else r = m;
  }
  return l - 1;
}

constexpr int inf = 1e9 + 7;
constexpr int mod = inf;
constexpr ll infll = 0x3f3f'3f3f'3f3f'3f3fll;

void solve() {
  int n = ri();
  auto a = rs(), b = rs();
  vll cnt(4);
  for (int i = 0; i < n; i++) {
    cnt[(a[i] - '0') | (b[i] - '0') << 1]++;
  }
  cout << cnt[0] * (cnt[1] + cnt[3]) + cnt[1] * cnt[2] << endl;
}

int main() {
  cin.tie(0)->sync_with_stdio(0);

  int t = 1;
  // int t = ri();
  while (t--) solve();
}

#endif
