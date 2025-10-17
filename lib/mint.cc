#include "../misc/tmpl.cc"
#include "qpow.cc"

template <int M> concept prime = []() {
  if (M < 2) return false;
  for (int i = 2; i * i <= M; i++)
    if (!(M % i)) return false;
  return true;
}();

template <int M> struct modint {
  int v = 0;

  constexpr modint() = default;
  constexpr modint(ll x) : v((x % M + M) % M) {}

  constexpr explicit operator int() const { return v; }

  constexpr modint &operator+=(modint o) { if ((v += o.v) >= M) v -= M; return *this; }
  constexpr modint &operator-=(modint o) { if ((v -= o.v) < 0) v += M; return *this; }
  constexpr modint &operator*=(modint o) { v = ll(v) * o.v % M; return *this; }
  constexpr modint &operator/=(modint o) requires prime<M> { return *this *= inv(o); }

  constexpr modint operator-() const { return modint(-v); }
  constexpr modint &operator++() { return *this += 1; }
  constexpr modint &operator--() { return *this -= 1; }

  friend constexpr modint inv(modint x) requires prime<M> { assert(x != 0); return pow(x, M - 2); }
  friend constexpr modint pow(modint b, ll e) {
    return e < 0 ? assert(!prime<M>), qpow(inv(b), -e) : qpow(b, e);
  }

  friend constexpr auto operator<=>(modint, modint) = default;

  friend constexpr modint operator+(modint a, modint b) { return a += b; }
  friend constexpr modint operator-(modint a, modint b) { return a -= b; }
  friend constexpr modint operator*(modint a, modint b) { return a *= b; }
  friend constexpr modint operator/(modint a,modint b) requires prime<M> { return a /= b; }

  friend ostream &operator<<(ostream &o, modint x) { return o << x.v; }
  friend istream &operator>>(istream &i, modint &x) { return i >> x.v; }
};

using mint = modint<inf>;
