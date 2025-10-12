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

int dig(char c) { return c - '0'; }

int rt() {
  auto s = rs();
  int h = dig(s[0]) * 10 + dig(s[1]);
  int m = dig(s[3]) * 10 + dig(s[4]);
  return h * 60 + m;
}

str t2s(int t) {
  stringstream s;
  if (t % 60 < 10) s << (t / 60) << ":0" << (t % 60);
  else s << (t / 60) << ":" << (t % 60);
  return s.str();
}

// ucla tryout #2 2024 virtual
// binary search + greedily construct

void solve() {
  int n = ri();
  vc<pi> segs(n);
  for (int i = 0; i < n; i++) {
    segs[i].A = rt(); rs(); segs[i].B = rt();
  }
  vc<pi> ret(n);
  maxst(0, 480, [&](int mlen) {
    vc<pi> cret = segs;
    for (int i = 0; i < n; i++) {
      int ext = max(0, mlen - (cret[i].B - cret[i].A));
      if (ext) {
        if (i) {
          int ext_l = min(ext, max(0, cret[i].A - cret[i - 1].B));
          ext -= ext_l;
          cret[i].A -= ext_l;
        }
        if (ext) {
          if (i == n - 1 || cret[i + 1].A < cret[i].B + ext) {
            return false;
          }
          cret[i].B += ext;
        }
      }
    }
    ret = cret;
    return true;
  });
  for (auto [l, r] : ret) {
    cout << t2s(l) << " - " << t2s(r) << endl;
  }
}

int main() {
  cin.tie(0)->sync_with_stdio(0);

  int t = 1;
  // int t = ri();
  while (t--) solve();
}

#endif
