#include <bits/stdc++.h>
#define A first
#define B second
#define vc vector
#define pb push_back
using namespace std;
using ll = long long; using ld = long double;
using vi = vc<int>; using vll = vc<ll>;
using si = set<int>; using sll = set<ll>;
using pii = pair<int, int>; using mii = map<int, int>;
using gr = vc<vi>; using wgr = vc<vc<pii>>;

template<class T> bool ckmin(T &a, const T &b) { return b < a ? a = b, 1 : 0; }
template<class T> bool ckmax(T &a, const T &b) { return a < b ? a = b, 1 : 0; }

const int inf = 1e9 + 7;
const int mod = inf;
const ll infll = 0x3f3f3f3f3f3f3f3fll;

using um = array<int, 4>;

bool in(int x, int y, um u) {
  ld dx = abs(x - u[0]), dy = abs(y - u[1]);
  return dx * dx * dx + dy * dy * dy <= u[2];
}

bool in(int x1, int y1, int x2, int y2, um u) {
  return in(x1, y1, u) && 
         in(x1, y2, u) && 
         in(x2, y1, u) && 
         in(x2, y2, u);
}

bool inter(int x1, int y1, int x2, int y2, um u) {
  int ux1 = u[0] - u[3], uy1 = u[1] - u[3], ux2 = u[0] + u[3], uy2 = u[1] + u[3];
  return x1 <= ux2 && ux1 <= x2 && y1 <= uy2 && uy1 <= y2;
}

ll solve(int x1, int y1, int x2, int y2, vc<um> &ums) {
  if (x2 < x1 || y2 < y1) return 0;
  vc<um> cands;
  for (um u : ums) {
    if (in(x1, y1, x2, y2, u)) {
      return 0;
    } else if (inter(x1, y1, x2, y2, u)) cands.pb(u);
  }
  if (x1 == x2 && y1 == y2 || !cands.size()) return (ll) (x2 - x1 + 1) * (y2 - y1 + 1);
  int xm = x1 + (x2 - x1) / 2, ym = y1 + (y2 - y1) / 2;
  return solve(x1, y1, xm, ym, cands) + 
         solve(xm + 1, y1, x2, ym, cands) + 
         solve(x1, ym + 1, xm, y2, cands) + 
         solve(xm + 1, ym + 1, x2, y2, cands);
}

int main() {
  int n, k; cin >> n >> k;
  vc<um> ums(k);
  for (int i = 0; i < k; ++i) {
    cin >> ums[i][0] >> ums[i][1] >> ums[i][2];
    ums[i][3] = (int) ceil(pow(ums[i][2], 1.0l / 3));
  }
  cout << solve(0, 0, n, n, ums) << endl;
}
