#include "../misc/tmpl.cc"

template <class T> struct Point {
  T x = 0, y = 0;
  constexpr Point() = default;
  constexpr Point(auto x, auto y) : x(x), y(y) {}
  constexpr Point operator+(Point p) const { return { x + p.x, y + p.y }; }
  constexpr Point operator-(Point p) const { return { x - p.x, y - p.y }; }
  constexpr Point operator-() const { return { -x, -y }; }
  constexpr T operator*(Point p) const { return x * p.x + y * p.y; }  // dot product
  constexpr T dot(Point a, Point b) const { return (a - self) * (b - self); }  // dot product
  constexpr T operator^(Point p) const { return x * p.y - y * p.x; }  // cross product
  constexpr T cross(Point a, Point b) const { return (a - self) ^ (b - self); }  // cross product
  constexpr Point operator*(auto c) const { return { x * c, y * c }; }
  constexpr Point operator/(auto c) const { return { x / c, y / c }; }
  constexpr auto operator<=>(const Point &) const = default;
};

template <class T> ostream& operator<<(ostream &o, Point<T> p) { return o << '(' << p.x << ' ' << p.y << ')'; }
template <class T> istream& operator>>(istream &i, Point<T> &p) { return i >> p.x >> p.y; }
template <class T> constexpr bool cw(Point<T> a, Point<T> b, Point<T> c) { return a.cross(b, c) < 0; }
template <class T> constexpr bool ccw(Point<T> a, Point<T> b, Point<T> c) { return a.cross(b, c) > 0; }
template <class T> constexpr Point<T> rot90(Point<T> p) { return { -p.y, p.x }; }
template <class T> constexpr Point<T> rot270(Point<T> p) { return { p.y, -p.x }; }
template <class T> fun tophalf(Point<T> p) { return p.y > 0 || (p.y == 0 && p.x >= 0); }
template <class T> fun cmp_angle(Point<T> a, Point<T> b) {
  bool ha = tophalf(a), hb = tophalf(b);
  if (ha != hb) return ha > hb;
  return (a ^ b) > 0;
}

using pt = Point<ll>;
