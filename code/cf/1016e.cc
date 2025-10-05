#ifndef TMPL
#define TMPL
#include <bits/stdc++.h>
#define A first
#define B second
#define pb push_back
#define endl '\n'
#define tT template <typename T
#define tTU tT, class U
using namespace std;
tT> using vc = vector<T>;
tT, int N> using ar = array<T, N>;
using ll = long long; using ld = double;
using vi = vc<int>; using vll = vc<ll>;
using si = set<int>; using sll = set<ll>;
using pi = pair<int, int>; using pll = pair<ll, ll>;
using qi = queue<int>;
using mii = map<int, int>;
using str = string;

tT> ostream &operator<<(ostream &os, const vc<T> &a) {
  for (int i = 0, n = a.size(); i < n; i++) os << (i ? " " : "") << a[i];
  return os;
}

tT, size_t N> ostream &operator<<(ostream &os, const ar<T, N> &a) {
  for (int i = 0; i < N; i++) os << (i ? " " : "") << a[i];
  return os;
}

tT> T rd() { T x; cin >> x; return x; }

tTU> istream& operator>>(istream &i, pair<T, U> &p) { return i >> p.A >> p.B; }
tT> vc<T> rda(int n) {
  vc<T> v(n);
  for (int i = 0; i < n; i++) cin >> v[i];
  return v;
}

int ri() { return rd<int>(); }
ll rll() { return rd<ll>(); }
str rs() { return rd<str>(); }
vi ria(int n) { return rda<int>(n); }
vll rlla(int n) { return rda<ll>(n); }

tTU> constexpr decltype(declval<T>() + declval<U>()) max(T a, U b) { return a > b ? a : b; }
tTU> constexpr decltype(declval<T>() + declval<U>()) min(T a, U b) { return a < b ? a : b; }
tTU> constexpr bool ckmin(T &a, U b) { return b < a ? a = b, 1 : 0; }
tTU> constexpr bool ckmax(T &a, U b) { return a < b ? a = b, 1 : 0; }
tT> constexpr T nth_bit(T x, int n) { return (x >> n) & 1; }
tTU> T minst(T l, T r, U pred) {
  T ans = r + 1;
  while (l <= r) {
    T m = l + (r - l) / 2;
    if (pred(m)) r = (ans = m) - 1;
    else l = m + 1;
  }
  return ans;
}
tTU> T maxst(T l, T r, U pred) {
  T ans = l - 1;
  while (l <= r) {
    T m = l + (r - l) / 2;
    if (pred(m)) l = (ans = m) + 1;
    else r = m - 1;
  }
  return ans;
}

constexpr int inf = 1e9 + 7;
constexpr int mod = inf;
constexpr ll infll = 0x3f3f'3f3f'3f3f'3f3fll;

tT> struct Point {
  T x, y;
  constexpr Point() : x{0}, y{0} {}
  template <class U, class V> constexpr Point(U x, V y) : x(x), y(y) {}
  constexpr Point operator+(Point p) const { return { x + p.x, y + p.y }; }
  constexpr Point operator-(Point p) const { return { x - p.x, y - p.y }; }
  constexpr Point operator*(T d) const { return { x * d, y * d }; }
  constexpr Point operator/(T d) const { return { x / d, y / d }; }
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

ld x_intercept(pt p1, pt p2) {
  ld im = (p2.x - p1.x) / (p2.y - p1.y);
  return p1.x - p1.y * im;
}

// editorial: project a and b onto x-axis

void solve() {
  int sy = -ri();
  pt a = {ri(), -sy}, b = {ri(), -sy};
  int n = ri();
  vc<pi> segs = rda<pi>(n);
  vi prefix(n + 1);
  for (int i = 0; i < n; i++) {
    prefix[i + 1] = prefix[i] + (segs[i].B - segs[i].A);
  }
  int q = ri();
  while (q--) {
    // note: rd<pt>() here is extremely slow
    pt p = {ri(), ri()};
    auto lx = x_intercept(p, a), rx = x_intercept(p, b);
    // find leftmost and rightmost fully contained segments
    auto lseg = minst(0, n - 1, [&](auto i) { return segs[i].A >= lx; });
    auto rseg = maxst(0, n - 1, [&](auto i) { return segs[i].B <= rx; });
    ld scale = (p.y + sy) / p.y;
    ld ret = rseg >= lseg ? prefix[rseg + 1] - prefix[lseg] : 0;
    // cout << "scale: " << scale << endl;
    // cout << lseg << ", " << rseg << " -> " << ret << endl;
    if (lseg - 1 == rseg + 1) {
      ret = rx - lx;
    }
    else {
      if (lseg) {
        // cout << "l: " << segs[lseg - 1].B - lx << endl;
        ret += max(0, segs[lseg - 1].B - lx);
      }
      if (rseg < n - 1) {
        // cout << "r: " << rx - segs[rseg + 1].A << endl;
        ret += max(0, rx - segs[rseg + 1].A);
      }
    }
    cout << (ret * scale) << endl;
  }
}

int main() {
  cin.tie(0)->sync_with_stdio(0);
  cout << setprecision(6) << fixed;

  int t = 1;
  // int t = ri();
  while (t--) solve();
}

#endif
