#include "../misc/tmpl.cc"
#include "mint.h"

template <int... Base> struct polyhash {
  static constexpr int N = sizeof...(Base);
  static constexpr int base[N] = {Base...};
  static array<vc<mint>, N> base_pow;
  array<mint, N> v;

  static void init(int n) {
    for (int i = 0; i < N; i++) {
      base_pow[i] = vc<mint>(n + 1, 1);
      for (int j = 0; j < n; j++) base_pow[i][j + 1] = base_pow[i][j] * base[i];
    }
  }

  polyhash() {}
  polyhash(int v) : v{static_cast<mint>(v + (Base * 0))...} {}

  bool operator==(const polyhash &o) const { return v == o.v; }
  friend bool operator!=(const polyhash &a, const polyhash &b) { return !(a == b); }
  friend bool operator<(const polyhash &a, const polyhash &b) { return a.v < b.v; }
  polyhash &operator+=(const polyhash &o) { for (int i = 0; i < N; i++) { v[i] += o.v[i]; } return *this; }
  polyhash &operator-=(const polyhash &o) { for (int i = 0; i < N; i++) { v[i] -= o.v[i]; } return *this; }
  polyhash &operator*=(const polyhash &o) { for (int i = 0; i < N; i++) { v[i] *= o.v[i]; } return *this; }
  polyhash &operator/=(const polyhash &o) { for (int i = 0; i < N; i++) { v[i] /= o.v[i]; } return *this; }
  polyhash &operator<<=(const int p) { for (int i = 0; i < N; i++) { v[i] *= base_pow[i][p]; } return *this; }
  polyhash &operator>>=(const int p) { for (int i = 0; i < N; i++) { v[i] /= base_pow[i][p]; } return *this; }
  polyhash operator-() const { polyhash neg; for (int i = 0; i < N; i++) { neg.v[i] = -v[i]; } return neg; }
  polyhash &operator++() { return *this += 1; }
  polyhash &operator--() { return *this -= 1; }
  friend polyhash operator+(polyhash a, const polyhash &b) { return a += b; }
  friend polyhash operator-(polyhash a, const polyhash &b) { return a -= b; }
  friend polyhash operator*(polyhash a, const polyhash &b) { return a *= b; }
  friend polyhash operator/(polyhash a, const polyhash &b) { return a /= b; }
  friend polyhash operator<<(polyhash a, int b) { return a <<= b; }
  friend polyhash operator>>(polyhash a, int b) { return a >>= b; }
  friend ostream &operator<<(ostream &os, const polyhash &x) { return os << "(" << x.v << ")"; }
};

using phash = polyhash<2000003, 2000023>;
