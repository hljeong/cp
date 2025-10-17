#include "../misc/tmpl.cc"

vi sieve(int n) {
  vi div(n + 1);
  for (int p = 2, q = p; p <= n; q = ++p) {
    if (div[p]) continue;
    while (q <= n) {
      div[q] = p;
      q += p;
    }
  }
  return div;
}
