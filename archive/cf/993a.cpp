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

// check if each of the corners is in the other square
// then check if center of diagonal square in aabb

bool in_aabb(int x, int y, int x1, int x2, int y1, int y2) {
  return x1 <= x && x <= x2 && y1 <= y && y <= y2;
}

bool in_diag(int x, int y, int x1, int x2, int y1, int y2) {
  int xm = (x1 + x2) / 2;
  int ym = (y1 + y2) / 2;
  // y = m (x - x0) + y0
  // under (x1, ym) - (xm, y2)
  //   y <= x - x1 + ym
  // above (x1, ym) - (xm, y1)
  //   y >= -(x - x1) + ym
  // under (xm, y2) - (x2, ym)
  //   y <= -(x - xm) + y2
  // above (xm, y1) - (x2, ym)
  //   y >= x - xm + y1
  return 
    y <= x - x1 + ym && 
    y >= -(x - x1) + ym && 
    y <= -(x - xm) + y2 && 
    y >= x - xm + y1;
}

int main() {
  cin.tie(0) -> sync_with_stdio(0);

  vi x(8), y(8);
  cin >> x[0] >> y[0];
  cin >> x[1] >> y[1];
  cin >> x[2] >> y[2];
  cin >> x[3] >> y[3];
  cin >> x[4] >> y[4];
  cin >> x[5] >> y[5];
  cin >> x[6] >> y[6];
  cin >> x[7] >> y[7];
  int ax1 = x[0], ax2 = x[0];
  ckmin(ax1, x[1]);
  ckmax(ax2, x[1]);
  ckmin(ax1, x[2]);
  ckmax(ax2, x[2]);
  ckmin(ax1, x[3]);
  ckmax(ax2, x[3]);
  int ay1 = y[0], ay2 = y[0];
  ckmin(ay1, y[1]);
  ckmax(ay2, y[1]);
  ckmin(ay1, y[2]);
  ckmax(ay2, y[2]);
  ckmin(ay1, y[3]);
  ckmax(ay2, y[3]);
  int bx1 = x[4], bx2 = x[4];
  ckmin(bx1, x[5]);
  ckmax(bx2, x[5]);
  ckmin(bx1, x[6]);
  ckmax(bx2, x[6]);
  ckmin(bx1, x[7]);
  ckmax(bx2, x[7]);
  int by1 = y[4], by2 = y[4];
  ckmin(by1, y[5]);
  ckmax(by2, y[5]);
  ckmin(by1, y[6]);
  ckmax(by2, y[6]);
  ckmin(by1, y[7]);
  ckmax(by2, y[7]);
  // cout << in_aabb(x[4], y[4], ax1, ax2, ay1, ay2) << endl;
  // cout << in_aabb(x[5], y[5], ax1, ax2, ay1, ay2) << endl;
  // cout << in_aabb(x[6], y[6], ax1, ax2, ay1, ay2) << endl;
  // cout << in_aabb(x[7], y[7], ax1, ax2, ay1, ay2) << endl;
  // cout << in_diag(x[0], y[0], bx1, bx2, by1, by2) << endl;
  // cout << in_diag(x[1], y[1], bx1, bx2, by1, by2) << endl;
  // cout << in_diag(x[2], y[2], bx1, bx2, by1, by2) << endl;
  // cout << in_diag(x[3], y[3], bx1, bx2, by1, by2) << endl;
  cout << (
    in_aabb(x[4], y[4], ax1, ax2, ay1, ay2) || 
    in_aabb(x[5], y[5], ax1, ax2, ay1, ay2) || 
    in_aabb(x[6], y[6], ax1, ax2, ay1, ay2) || 
    in_aabb(x[7], y[7], ax1, ax2, ay1, ay2) || 
    in_diag(x[0], y[0], bx1, bx2, by1, by2) || 
    in_diag(x[1], y[1], bx1, bx2, by1, by2) || 
    in_diag(x[2], y[2], bx1, bx2, by1, by2) || 
    in_diag(x[3], y[3], bx1, bx2, by1, by2) || 
    in_aabb((bx1 + bx2) / 2, (by1 + by2) / 2, ax1, ax2, ay1, ay2)
   ? "YES" : "NO") << endl;
}
