#include "../misc/tmpl.cc"

tT> T qpow(T b, ll e) {
  assert(e >= 0);
  T ans = 1;
  for (; e; e >>= 1, b *= b) if (e & 1) ans *= b;
  return ans;
}
