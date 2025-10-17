#ifndef TMPL
#define TMPL
#include <bits/stdc++.h>
#define A first
#define B second
#define pb push_back
#define endl '\n'
using namespace std;
template <class T> using vec = vector<T>;
template <class T, int N> using ar = array<T, N>;
using ll = long long; using ld = long double;
using vi = vec<int>; using vll = vec<ll>;
using si = set<int>; using sll = set<ll>;
using pi = pair<int, int>; using pll = pair<ll, ll>;
using qi = queue<int>;
using mii = map<int, int>;
using str = string;

template <class T>
concept not_str = !(same_as<remove_cvref_t<T>, str> ||
                    same_as<remove_cvref_t<T>, string_view> ||
                    convertible_to<T, const char *>);

template <ranges::range R> requires not_str<R>
ostream &operator<<(ostream &os, const R& range) {
  auto it = ranges::begin(range); auto end = ranges::end(range);
  for (bool first = 1; it != end; it++) {
    if (!first) os << ' ';
    first = 0;
    os << *it;
  }
  return os;
}

template <class T, class U>
istream& operator>>(istream &i, pair<T, U> &p) { return i >> p.A >> p.B; }

template <class T> T rd() { T x; cin >> x; return x; }
int ri() { return rd<int>(); }
ll rll() { return rd<ll>(); }
str rs() { return rd<str>(); }

template <ranges::range R>
requires (ranges::random_access_range<R> && ranges::sized_range<R> && not_str<R>)
void read(R& range, int n) { for (int i = 0; i < n; i++) cin >> range[i]; }
void read(auto &...vars) { ((cin >> vars), ...); }
#define def(T, vars...) T vars; read(vars)
#define defv(E, var, n) vec<E> var(n); read(var, n)

template <class T> concept torder = totally_ordered<T>;
constexpr auto max(torder auto a, torder auto b) { return a > b ? a : b; }
constexpr auto min(torder auto a, torder auto b) { return a < b ? a : b; }
constexpr bool ckmin(torder auto &a, torder auto b) { return b < a ? a = b, 1 : 0; }
constexpr bool ckmax(torder auto &a, torder auto b) { return b > a ? a = b, 1 : 0; }

constexpr auto nth_bit(integral auto x, int n) { return (x >> n) & 1; }
constexpr auto high_bit_idx(integral auto x) { assert(x); return bit_width(x) - 1; }
constexpr auto high_bit(integral auto x) { assert(x); return 1 << high_bit_idx(x); }
constexpr auto low_bit(integral auto x) { assert(x); return x & -x; }
constexpr auto low_bit_idx(integral auto x) { assert(x); return high_bit_idx(low_bit(x)); }

constexpr auto minst(torder auto l, decltype(l) r, predicate<decltype(l)> auto pred) {
  while (l < r) {
    const decltype(l) m = l + (r - l) / 2;
    if (pred(m)) r = m;
    else l = m + 1;
  }
  return l;
}

constexpr auto maxst(torder auto l, decltype(l) r, predicate<decltype(l)> auto pred) {
  return minst(l, r + 1, [pred](decltype(l) x) { return !pred(x); }) - 1;
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
  constexpr T operator*(Point p) const { return x * p.x + y * p.y; }  // dot product
  constexpr T operator^(Point p) const { return x * p.y - y * p.x; }  // cross product
  constexpr T cross(Point a, Point b) const { return (a - *this) ^ (b - *this); }  // cross product
  constexpr Point operator*(auto c) const { return { x * c, y * c }; }
  constexpr Point operator/(auto c) const { return { x / c, y / c }; }
  constexpr auto operator<=>(Point p) const { return tie(x, y) <=> tie(p.x, p.y); }
};

template <class T> ostream& operator<<(ostream &o, Point<T> p) { return o << '(' << p.x << ' ' << p.y << ')'; }
template <class T> istream& operator>>(istream &i, Point<T> &p) { return i >> p.x >> p.y; }
template <class T> constexpr bool cw(Point<T> a, Point<T> b, Point<T> c) { return a.cross(b, c) < 0; }
template <class T> constexpr bool ccw(Point<T> a, Point<T> b, Point<T> c) { return a.cross(b, c) > 0; }

using pt = Point<ll>;

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

template <ranges::range R>
requires (ranges::random_access_range<R> && ranges::sized_range<R>)
vi prefix(const R &s) {
  auto n = ranges::size(s);
  vi pi(n);
  for (int i = 1; i < n; i++) {
    int j = pi[i - 1];
    while (j > 0 && s[i] != s[j]) j = pi[j - 1];
    pi[i] = j + (s[i] == s[j]);
  }
  return pi;
}

template <ranges::range R>
requires (ranges::random_access_range<R> && ranges::sized_range<R>)
vi kmp(const R &s, const R &pat) {
  auto n = ranges::size(s), m = ranges::size(pat);
  if (m == 0) return {};

  vi pi = prefix(pat), ret;
  for (int i = 0, j = 0; i < n; i++) {
    while (j && s[i] != pat[j]) j = pi[j - 1];
    if (s[i] == pat[j]) j++;
    if (j == m) {
      ret.pb(i - m + 1);
      j = pi[j - 1];
    }
  }
  return ret;
}

// check if the 2 convex hulls are congruent modulo translation and rotation

void solve() {
  def(int, n, m);
  defv(pt, f, n);  // "first"
  defv(pt, s, m);  // "second"
  auto fh = convhull(f);  // "first hull"
  auto sh = convhull(s);  // "second hull"
  // cout << fh << endl;
  // cout << sh << endl;
  if (fh.size() != sh.size()) {
    cout << "NO" << endl;
    return;
  }

  int k = fh.size();

  // edge cases
  if (k == 1) {
    cout << "YES" << endl; return;
  } else if (k == 2) {
    cout << ((fh[1] - fh[0]) * (fh[1] - fh[0]) == (sh[1] - sh[0]) * (sh[1] - sh[0]) ? "YES" : "NO") << endl;
    return;
  }

  // represent convex hull as [(edge length, angle), ...], where angle is represented by (cross, dot)
  vec<ar<ll, 3>> fh_, sh_;
  for (int i = 0; i < k; i++) {
    int j = (i + 1) % k, l = (i + 2) % k;
    fh_.pb({(fh[j] - fh[i]) * (fh[j] - fh[i]), fh[i].cross(fh[j], fh[l]), (fh[j] - fh[i]) * (fh[l] - fh[i])});
    sh_.pb({(sh[j] - sh[i]) * (sh[j] - sh[i]), sh[i].cross(sh[j], sh[l]), (sh[j] - sh[i]) * (sh[l] - sh[i])});
  }

  // cout << fh_ << endl;
  // cout << sh_ << endl;

  // check equivalence up to rotation of vertices: double one of them, search for the other via kmp
  for (int i = 0; i < 2 * k; i++) fh_.pb(fh_[i]);
  cout << (kmp(fh_, sh_).size() ? "YES" : "NO") << endl;
}

int main() {
  cin.tie(0)->sync_with_stdio(0);

  int t = 1;
  // int t = ri();
  while (t--) solve();
}

#endif
