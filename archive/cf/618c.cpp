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

constexpr int inf = 1e9 + 7;
constexpr int mod = inf;
constexpr ll infll = 0x3f3f3f3f3f3f3f3fll;

// return residual magnitude squared, -1 if collinear
ld get(vc<pi> &p, int p1, int i) {
  auto [x0, y0] = p[0];
  auto [x1, y1] = p[p1];
  auto [xi, yi] = p[i];
  ld vx = x1 - x0, vy = y1 - y0, px = xi - x0, py = yi - y0;
  // bad if collinear
  if (vx * py == vy * px) return -1;
  ld mv = sqrt(vx * vx + vy * vy);
  // unit vector
  ld ux = vx / mv, uy = vy / mv;
  ld dot = ux * px + uy * py;
  // projection
  ld projx = dot * ux, projy = dot * uy;
  // residual
  ld resx = px - projx, resy = py - projy;
  return resx * resx + resy * resy;
}

// return distance squared
ld dst(vc<pi>& p, int i) {
  auto [x0, y0] = p[0];
  auto [xi, yi] = p[i];
  ld dx = xi - x0, dy = yi - y0;
  return dx * dx + dy * dy;
}

// choose point 1, closest point to point 1, and closest point to line created by the first two points that is not on the line
int main() {
  cin.tie(0) -> sync_with_stdio(0);

  int n; cin >> n;
  vc<pi> p(n);
  for (int i = 0; i < n; ++i) cin >> p[i].A >> p[i].B;
  cout << "1 ";
  // choose closest point to point 1
  int mn = 1;
  ld best = dst(p, mn);
  for (int i = 2; i < n; ++i) {
    ld cur = dst(p, i);
    if (ckmin(best, cur)) mn = i;
  }
  int p1 = mn;
  cout << (p1 + 1) << " ";
  // choose closest point that is not collinear
  mn = 1;
  best = get(p, p1, mn);
  for (int i = 2; i < n; ++i) {
    ld cur = get(p, p1, i);
    if (best < 0) {
      mn = i;
      best = cur;
    } else if (cur > 0 && ckmin(best, cur)) mn = i;
  }
  cout << (mn + 1) << endl;
}
