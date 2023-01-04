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

template<class T> bool ckmin(T &a, const T &b) { return b < a ? a = b, 1 : 0; }
template<class T> bool ckmax(T &a, const T &b) { return b > a ? a = b, 1 : 0; }

const int inf = 1e9 + 7;
const int mod = inf;
const ll infll = 0x3f3f3f3f3f3f3f3fll;

int main() {
  int n; cin >> n;
  int x1, y1, x2, y2; cin >> x1 >> y1 >> x2 >> y2;
  int x, y; cin >> x >> y;
  while (x1 != 1 || y1 != 1 || x2 != n || y2 != n) {
    if (x1 != 1) cout << (x1 -= 1) << ' ' << y1 << ' ';
    else if (y1 != 1) cout << x1 << ' ' << (y1 -= 1) << ' ';
    else cout << x1 << ' ' << y1 << ' ';
    if (x2 != n) cout << (x2 += 1) << ' ' << y2 << endl;
    else if (y2 != n) cout << x2 << ' ' << (y2 += 1) << endl;
    else cout << x2 << ' ' << y2 << endl;
    cout << flush;
    cin >> x >> y;
    if (!x) return 0;
  }
  while (x) {
    if (x < x1) {
      cout << (x1 -= 1) << ' ' << y1 << ' ' << (x2 -= 1) << ' ' << y2 << endl;
    } else if (x > x2) {
      cout << (x1 += 1) << ' ' << y1 << ' ' << (x2 += 1) << ' ' << y2 << endl;
    } else if (y < y1) {
      cout << x1 << ' ' << (y1 -= 1) << ' ' << x2 << ' ' << (y2 -= 1) << endl;
    } else if (y > y2) {
      cout << x1 << ' ' << (y1 += 1) << ' ' << x2 << ' ' << (y2 += 1) << endl;
    } else if (y >= x) {
      cout << x1 << ' ' << (y1 += 1) << ' ' << (x2 -= 1) << ' ' << y2 << endl;
    } else {
      cout << (x1 += 1) << ' ' << y1 << ' ' << x2 << ' ' << (y2 -= 1) << endl;
    }
    cout << flush;
    cin >> x >> y;
  }
}