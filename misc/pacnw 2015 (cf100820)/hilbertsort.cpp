#include <bits/stdc++.h>
#define vc vector
#define A first
#define B second
#define pb push_back
using namespace std;
using ll = long long;
using vi = vc<int>;
using vll = vc<ll>;
using ld = long double;
using pld = pair<ld, ld>;
using pt = pair<pld, int>;

void solve(vc<pt> pts, ld s, vc<string> &ret, vc<string> &names) {
  if (pts.size() <= 1) {
    for (pt p : pts) ret.pb(names[p.B]);
    return;
  }
  vc<pt> bl, tl, tr, br;
  for (pt p : pts) {
    if (p.A.A < s / 2) {
      if (p.A.B < s / 2) {
        bl.pb({{p.A.B, p.A.A}, p.B});
      } else {
        tl.pb({{p.A.A, p.A.B - s / 2}, p.B});
      }
    } else {
      if (p.A.B < s / 2) {
        br.pb({{s / 2 - p.A.B, s - p.A.A}, p.B});
      } else {
        tr.pb({{p.A.A - s / 2, p.A.B - s / 2}, p.B});
      }
    }
  }
  solve(bl, s / 2, ret, names);
  solve(tl, s / 2, ret, names);
  solve(tr, s / 2, ret, names);
  solve(br, s / 2, ret, names);
}

int main() {
  int n; ld s; cin >> n >> s;
  vc<string> names(n);
  vc<pt> pts(n);
  for (int i = 0; i < n; ++i) {
    ld x, y; string name; cin >> x >> y >> name;
    pts[i].A.A = x;
    pts[i].A.B = y;
    pts[i].B = i;
    names[i] = name;
  }
  vc<string> ret;
  solve(pts, s, ret, names);
  for (int i = 0; i < n; ++i)
    cout << ret[i] << endl;
}