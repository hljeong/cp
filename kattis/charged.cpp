#include <bits/stdc++.h>
#define A first
#define B second
#define vc vector
using namespace std;
using ll = long long;
using ld = long double;
using vi = vc<int>;
using vll = vc<ll>;
using pii = pair<int, int>;

template<class T> bool ckmin(T &a, const T &b) { return b < a ? a = b, 1 : 0; }
template<class T> bool ckmax(T &a, const T &b) { return a < b ? a = b, 1 : 0; }

const ld pie = 3.14159265358979l;

struct pt {
  ld x, y, s;
};

ld dist(ld x1, ld y1, ld x2, ld y2) {
  ld dx = x2 - x1;
  ld dy = y2 - y1;
  return sqrt(dx * dx + dy * dy);
}

int main() {
  int n, m, q; cin >> n >> m >> q;
  vc<pt> p(q, {0, 0, 0});
  for (int i = 0; i < q; ++i) {
    cin >> p[i].x >> p[i].y;
    char sgn; cin >> sgn;
    if (sgn == '+') p[i].s = 1;
    else p[i].s = -1;
  }
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      ld y = i + 1, x = j + 1;
      ld v = 0;
      bool cont = false;
      for (struct pt pi : p) {
        ld r = dist(x, y, pi.x, pi.y);
        if (r < 1e-5) {
          cout << (pi.s > 0 ? '+' : '-');
          cont = true;
          break;
        }
        v += pi.s / r;
      }
      if (cont) continue;
      if (v > 0) {
        if (v >= 1 / pie) {
          cout << '0';
        } else if (v >= 1 / pie / pie) {
          cout << 'O';
        } else if (v >= 1 / pie / pie / pie) {
          cout << 'o';
        } else {
          cout << '.';
        }
      } else {
        v = -v;
        if (v >= 1 / pie) {
          cout << '%';
        } else if (v >= 1 / pie / pie) {
          cout << 'X';
        } else if (v >= 1 / pie / pie / pie) {
          cout << 'x';
        } else {
          cout << '.';
        }

      }
    }
    cout << endl;
  }
}
