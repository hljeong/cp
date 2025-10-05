#include "../misc/tmpl.cc"

tT> struct Point {
  T x = 0, y = 0;
  constexpr Point() : x{0}, y{0} {}
  template <class U, class V> constexpr Point(U x, V y) : x(x), y(y) {}
  constexpr Point operator+(Point p) const { return { x + p.x, y + p.y }; }
  constexpr Point operator-(Point p) const { return { x - p.x, y - p.y }; }
  template <class U> constexpr Point operator*(U d) const { return { x * d, y * d }; }
  template <class U> constexpr Point operator/(U d) const { return { x / d, y / d }; }
  constexpr bool operator<(Point p) const { return tie(x, y) < tie(p.x, p.y); }
  constexpr bool operator==(Point p) const { return tie(x, y) == tie(p.x, p.y); }
  constexpr T dot(Point p) const { return x * p.x + y * p.y; }
  constexpr T cross(Point p) const { return x * p.y - y * p.x; }
  constexpr T cross(Point a, Point b) const { return (a - *this).cross(b - *this); }
};

tT> ostream& operator<<(ostream &o, Point<T> &p) { return o << p.x << ' ' << p.y; }
tT> istream& operator>>(istream &i, Point<T> &p) { return i >> p.x >> p.y; }
tT> constexpr bool ccw(Point<T> a, Point<T> b, Point<T> c) { return a.cross(b, c) > 0; }

using pt = Point<ld>;
