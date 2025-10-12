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

tT> requires requires { T(1); } T qpow(T b, ll e) {
  assert(e >= 0);
  T ans(1);
  for (; e; e >>= 1, b *= b) if (e & 1) ans *= b;
  return ans;
}

template <int M> struct modint {
  int v;

  explicit operator int() const { return v; }
  modint() : v(0) {}
  modint(ll x) : v((-M <= x && x < M) ? x : x % M) { if (v < 0) v += M; }
  bool operator==(const modint &o) const { return v == o.v; }
  friend bool operator!=(const modint &a, const modint &b) { return !(a == b); }
  friend bool operator<(const modint &a, const modint &b) { return a.v < b.v; }
  modint &operator+=(const modint &o) { if ((v += o.v) >= M) v -= M; return *this; }
  modint &operator-=(const modint &o) { if ((v -= o.v) < 0) v += M; return *this; }
  modint &operator*=(const modint &o) { v = int(ll(v) * o.v % M); return *this; }
  modint &operator/=(const modint &o) { return (*this) *= inv(o); }
  friend modint inv(const modint &x);
  friend modint pow(modint b, ll e) { return e < 0 ? qpow(inv(b), -e) : qpow(b, e); }
  // friend modint pow(modint b, ll e) {
  //   if (e < 0) return pow(inv(b), -e);
  //   modint ans = 1;
  //   for (; e; e >>= 1, b *= b) if (e & 1) ans *= b;
  //   return ans;
  // }

  friend modint inv(const modint &x) { assert(x.v != 0); return pow(x, M - 2); }
  modint operator-() const { return modint(-v); }
  modint &operator++() { return *this += 1; }
  modint &operator--() { return *this -= 1; }
  friend modint operator+(modint a, const modint &b) { return a += b; }
  friend modint operator-(modint a, const modint &b) { return a -= b; }
  friend modint operator*(modint a, const modint &b) { return a *= b; }
  friend modint operator/(modint a, const modint &b) { return a /= b; }
  friend ostream &operator<<(ostream &os, const modint &x) { return os << int(x); }
  friend istream &operator>>(istream &os, modint &x) { return os >> x.v; }
};

using mint = modint<1000000009>;

tT, int N> struct mat {
  using V = ar<ar<T, N>, N>;
  V v;

  mat() = default;
  mat(const V &v) : v{v} {}
  mat(T v_) { for (int i = 0; i < N; i++) v[i][i] = v_; }
  bool operator==(const mat &o) const { return v == o.v; }
  friend bool operator!=(const mat &a, const mat &b) { return !(a == b); }
  mat &operator+=(const mat &o) {
    for (int i = 0; i < N; i++) {
      for (int j = 0; j < N; j++) {
        v[i][j] += o.v[i][j];
      }
    }
    return *this;
  }
  mat &operator-=(const mat &o) {
    for (int i = 0; i < N; i++) {
      for (int j = 0; j < N; j++) {
        v[i][j] -= o.v[i][j];
      }
    }
    return *this;
  }
  mat &operator*=(const mat &o) { v = (*this * o).v; return *this; }

  friend mat operator+(mat a, const mat &b) { return a += b; }
  friend mat operator-(mat a, const mat &b) { return a -= b; }
  friend mat operator*(const mat &a, const mat &b) {
    mat c;
    for (int i = 0; i < N; i++) {
      for (int j = 0; j < N; j++) {
        for (int k = 0; k < N; k++) {
          c.v[i][j] += a.v[i][k] * b.v[k][j];
        }
      }
    }
    return c;
  }
  friend mat operator/(mat a, const mat &b) { return a /= b; }
  // friend ostream &operator<<(ostream &os, const modint &x) { return os << int(x); }
  // friend istream &operator>>(istream &os, modint &x) { return os >> x.v; }
};

using M = mat<mint, 20>;
// template <> M qpow<M>(M b, ll e);

M make(int v) {
  M m;
  for (int i = 0; i < v; i++) {
    for (int j = 0; j <= i; j++) {
      m.v[j][i] = 1;
    }
  }
  return m;
}

// ucla tryout #2 2025 mirror
// https://open.kattis.com/contests/y64efw

// harry zhou: you can matrix expo apparently
void solve() {
  int t = ri(), c = ri(), o = ri(), d = ri(), i = ri();
  M m = qpow(make(4), t) * qpow(make(6), c) * qpow(make(8), o) * qpow(make(12), d) * qpow(make(20), i);
  mint ans = 0;
  for (int i = 0; i < 20; i++) ans += m.v[0][i];
  cout << ans << endl;
}

// william zhao: the problem bijects to grid walking where the heights represent the dice values you roll
void solve_dp() {
  // (idgi)
}

int main() {
  cin.tie(0)->sync_with_stdio(0);

  int t = 1;
  // int t = ri();
  while (t--) solve();
}

#endif
