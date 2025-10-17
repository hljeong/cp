#include "../misc/tmpl.cc"
#include "geom.cc"

// monotone chain
template <bool collinear = false>
vec<pt> convhull(vec<pt> &p) {
  int n = p.size();
  if (n <= 2) return p;
  sort(p.begin(), p.end());
  vec<pt> u, l;
  for (int i = 0; i < n; i++) {
    if constexpr (collinear) while (l.size() >= 2 && cw(l[l.size() - 2], l.back(), p[i])) l.pop_back();
    else while (l.size() >= 2 && !ccw(l[l.size() - 2], l.back(), p[i])) l.pop_back();
    l.pb(p[i]);
  }
  for (int i = n - 1; i >= 0; i--) {
    if constexpr (collinear) while (u.size() >= 2 && cw(u[u.size() - 2], u.back(), p[i])) u.pop_back();
    else while (u.size() >= 2 && !ccw(u[u.size() - 2], u.back(), p[i])) u.pop_back();
    u.pb(p[i]);
  }
  l.pop_back(); u.pop_back();
  l.insert(l.end(), u.begin(), u.end());
  return l;
}
