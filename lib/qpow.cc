#include "../misc/tmpl.cc"

template <class T> requires requires { T(1); }
T qpow(T b, ll e) {
  assert(e >= 0);
  T ans = 1;
  for (; e; e >>= 1, b *= b) if (e & 1) ans *= b;
  return ans;
}
