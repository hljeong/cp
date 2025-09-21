#include <bits/stdc++.h>
#define A first
#define B second
#define vc vector
#define pb push_back
#define endl '\n'
using namespace std;
using ll = long long; using ld = long double;
using vi = vc<int>; using vll = vc<ll>;
using si = set<int>; using sll = set<ll>;
using pi = pair<int, int>; using pll = pair<ll, ll>;
using qi = queue<int>; using mi = map<int, int>;

template<class T> bool ckmin(T &a, const T &b) { return b < a ? a = b, 1 : 0; }
template<class T> bool ckmax(T &a, const T &b) { return a < b ? a = b, 1 : 0; }

const int inf = 1e9 + 7;
const int mod = inf;
const ll infll = 0x3f3f3f3f3f3f3f3fll;

using T = ld;
struct pt {
  T x, y;
  pt() : x(0), y(0) {}
  pt(T x, T y) : x(x), y(y) {}
  pt operator+(pt p) const { return { x + p.x, y + p.y }; }
  pt operator-(pt p) const { return { x - p.x, y - p.y }; }
  pt operator*(T d) const { return { x * d, y * d }; }
  pt operator/(T d) const { return { x / d, y / d }; }
  bool operator<(pt p) const { return tie(x, y) < tie(p.x, p.y); }
  bool operator==(pt p) const { return tie(x, y) == tie(p.x, p.y); }
  T dot(pt p) const { return x * p.x + y * p.y; }
  T cross(pt p) const { return x * p.y - y * p.x; }
  T cross(pt a, pt b) const { return (a - *this).cross(b - *this); }
};

ostream& operator<<(ostream &o, pt &p) {
  return o << p.x << ' ' << p.y;
}

bool ccw(pt a, pt b, pt c) {
  return a.cross(b, c) > 0;
}

ld mag(pt v) {
  return sqrt(v.dot(v));
}

ld dist(pt a, pt b) {
  return mag(b - a);
}

pt proj(pt u, pt v) {
  return v * u.dot(v) / v.dot(v);
}

ld dist(pt a, pt b, pt c) {
  ld r = (a - c).dot(b - c) / (b - c).dot(b - c);
  if (r <= 0 || r >= 1) return min(dist(a, b), dist(a, c));
  else return mag((a - c) - proj(a - c, b - c));
}

int main() {
  cin.tie(0) -> sync_with_stdio(0);

  int x, y, x1, y1, x2, y2;
  cin >> x >> y >> x1 >> y1 >> x2 >> y2;
  ld ret = infll;
  ckmin(ret, dist({x, y}, {x1, y1}, {x2, y1}));
  ckmin(ret, dist({x, y}, {x1, y1}, {x1, y2}));
  ckmin(ret, dist({x, y}, {x1, y2}, {x2, y2}));
  ckmin(ret, dist({x, y}, {x2, y1}, {x2, y2}));
  cout << ret << endl;
}
