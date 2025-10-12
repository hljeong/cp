#include "../misc/tmpl.cc"
#include "qpow.cc"

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

using mint = modint<inf>;
