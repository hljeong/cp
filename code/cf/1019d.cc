#ifndef TMPL
#define TMPL
#include <bits/stdc++.h>
#define A first
#define B second
#define pb push_back
#define fun constexpr auto
#define endl '\n'
#define self (*this)
using namespace std;
namespace r = ranges;
namespace rv = r::views;
template <class T> using vec = vector<T>;
template <class T, size_t N> using ar = array<T, N>;
template <class ...Ts> using tup = tuple<Ts...>;
using ll = long long; using ld = long double;
using vi = vec<int>; using vll = vec<ll>;
using si = set<int>; using sll = set<ll>;
using pi = pair<int, int>; using pll = pair<ll, ll>;
using qi = queue<int>;
template <class T> using pq = priority_queue<T>;
using mii = map<int, int>;
using str = string;

template <class T>
concept not_str = !(same_as<remove_cvref_t<T>, str> ||
                    same_as<remove_cvref_t<T>, string_view> ||
                    convertible_to<T, const char *>);

template <ranges::range R> requires not_str<R>
ostream &operator<<(ostream &o, R &&range) {
  bool first = true;
  for (auto &&value : range) {
    if (!first) o << ' ';
    first = false;
    o << value;
  }
  return o;
}

template <class T, class U> ostream& operator<<(ostream &o, const pair<T, U> &p) { return o << '(' << p.A << ' ' << p.B << ')'; }
template <class T, class U> istream& operator>>(istream &i, pair<T, U> &p) { return i >> p.A >> p.B; }


template <class T> T rd() { T x; cin >> x; return x; }
int ri() { return rd<int>(); }
ll rll() { return rd<ll>(); }
str rs() { return rd<str>(); }

template <r::range R>
requires (r::random_access_range<R> && r::sized_range<R> && not_str<R>)
void read(R& range, int n) { for (int i = 0; i < n; i++) cin >> range[i]; }
void read(auto &...vars) { ((cin >> vars), ...); }
#define def(T, vars...) T vars; read(vars)
#define defv(E, var, n) vec<E> var(n); read(var, n)

template <class T> concept torder = totally_ordered<T>;
template <class T, class U> concept mut_torder = totally_ordered_with<T, U>;
#define mut_torder_TU template <class T, class U> requires mut_torder<T, U>
mut_torder_TU fun max(T a, U b) { return a > b ? a : b; }
mut_torder_TU fun min(T a, U b) { return a < b ? a : b; }
mut_torder_TU constexpr bool ckmin(T &a, U b) { return b < a ? a = b, 1 : 0; }
mut_torder_TU constexpr bool ckmax(T &a, U b) { return b > a ? a = b, 1 : 0; }
#undef mut_torder_TU

fun nth_bit(integral auto x, int n) { return (x >> n) & 1; }
fun high_bit_idx(integral auto x) { assert(x); return bit_width(x) - 1; }
fun high_bit(integral auto x) { assert(x); return 1 << high_bit_idx(x); }
fun low_bit(integral auto x) { assert(x); return x & -x; }
fun low_bit_idx(integral auto x) { assert(x); return high_bit_idx(low_bit(x)); }

fun mid(integral auto l, integral auto r) { return l + (r - l) / 2; }

template <torder T> constexpr T minst(T l, T r, predicate<T> auto pred) {
  while (l < r) {
    const T m = mid(l, r);
    if (pred(m)) r = m;
    else l = m + 1;
  }
  return l;
}

template <torder T> constexpr T maxst(T l, T r, predicate<T> auto pred) {
  return minst(l, r + 1, [pred](T x) { return !pred(x); }) - 1;
}

template <class T, size_t N> struct nvec_t;
template <class T, size_t N> using nvec = nvec_t<T, N>::type;
template <class T, size_t N> struct nvec_t { using type = vec<nvec<T, N - 1>>; };
template <class T> struct nvec_t<T, 0> { using type = T; };

template <class T> T make_nvec(const T &value) { return value; }
template <class T, class... Dims>
auto make_nvec(size_t dim, Dims... dims) {
  using E = decltype(make_nvec<T>(dims...));
  return vec<E>(dim, make_nvec<T>(dims...));
}

constexpr int inf = 1e9 + 7;
constexpr int mod = inf;
constexpr ll infll = 0x3f3f'3f3f'3f3f'3f3fll;

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
template <class T> constexpr Point<T> rot180(Point<T> p) { return { -p.x, -p.y }; }
template <class T> constexpr Point<T> rot270(Point<T> p) { return { p.y, -p.x }; }
template <class T> fun tophalf(Point<T> p) { return p.y > 0 || (p.y == 0 && p.x >= 0); }
template <class T> fun cmp_angle(Point<T> a, Point<T> b) {
  bool ha = tophalf(a), hb = tophalf(b);
  if (ha != hb) return ha > hb;
  return (a ^ b) > 0;
}

using pt = Point<ll>;

template <integral T, integral U> fun range(T start, U end) {
  using V = common_type_t<T, U>;
  return rv::iota(static_cast<V>(start), static_cast<V>(end));
}
template <integral T> fun range(T end) { return range(T(0), end); }

template <r::range R>
auto sliced(R &&r, size_t start, size_t end) {
  return std::forward<R>(r) | rv::drop(start) | rv::take(end - start);
}

template <r::range R> auto sliced(R &&r, size_t start) {
  return std::forward<R>(r) | rv::drop(start);
}

template <r::forward_range R1, r::forward_range R2>
struct zip : r::view_interface<zip<R1, R2>>
{
  R1 r1; R2 r2;
  zip() = default;
  zip(R1 r1, R2 r2) : r1(r1), r2(r2) {}

  struct iterator {
    using iterator_category = forward_iterator_tag;
    using value_type = tup<r::range_reference_t<R1>, r::range_reference_t<R2>>;
    r::iterator_t<R1> it1; r::iterator_t<R2> it2;
    iterator() = default;
    iterator(auto a, auto b) : it1(a), it2(b) {}
    value_type operator*() const { return { *it1, *it2 }; }
    iterator &operator++() { it1++; it2++; return self; }
    bool operator==(const iterator &other) const { return it1 == other.it1 || it2 == other.it2; }
    bool operator!=(const iterator &other) const { return !(self == other); }
  };

  iterator begin() { return { r::begin(r1), r::begin(r2) }; }
  iterator end() { return { r::end(r1), r::end(r2) }; }
};

template <r::forward_range R1, r::forward_range R2> zip(R1, R2) -> zip<R1, R2>;

template <r::forward_range R> auto pairwise(R &&r) { return zip(r, r | rv::drop(1)); }

void solve() {
  def(int, n);
  def(ll, s); s *= 2;
  defv(pt, p, n);
  vec<pi> dirs;
  for (int i : range(n)) {
    for (int j : range(i + 1, n)) {
      // will fail without forcing all normals to the same half plane
      // instead of using rot90(p[j] - p[i]), use (p[j] - p[i]) and sub
      // dot products w cross products
      if (tophalf(p[j] - p[i])) dirs.pb({j, i});
      else dirs.pb({i, j});
    }
  }

  vi idx(n); iota(idx.begin(), idx.end(), 0);
  r::sort(dirs, cmp_angle<ll>, [&](auto &ij) { return p[ij.B] - p[ij.A]; });
  r::sort(idx, {}, [&](auto i) { return p[i] ^ (p[dirs[0].B] - p[dirs[0].A]); });
  vi inv(n); for (int i : range(n)) inv[idx[i]] = i;

  #define ok(i, j, k) ({{ \
    cout << "Yes" << endl; \
    cout << p[i].x << ' ' << p[i].y << endl; \
    cout << p[j].x << ' ' << p[j].y << endl; \
    cout << p[idx[k]].x << ' ' << p[idx[k]].y << endl; \
    return; \
  }})

  for (auto &[i, j] : dirs) {
    auto side = p[j] - p[i];
    int k = minst(0, n, [&](int k) { return ((p[idx[k]] - p[i]) ^ side) >= s; });
    if (k < n && ((p[idx[k]] - p[i]) ^ side) == s) ok(i, j, k);
    k = minst(0, n, [&](int k) { return ((p[idx[k]] - p[i]) ^ side) >= -s; });
    if (k < n && ((p[idx[k]] - p[i]) ^ side) == -s) ok(i, j, k);
    swap(idx[inv[i]], idx[inv[j]]);
    swap(inv[i], inv[j]);
  }
  cout << "No" << endl;
}

int main() {
  cin.tie(0)->sync_with_stdio(0);

  int t = 1;
  // int t = ri();
  while (t--) solve();
}

#endif
