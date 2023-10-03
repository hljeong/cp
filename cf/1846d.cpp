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

int main() {
  cin.tie(0) -> sync_with_stdio(0);

  int t; cin >> t;
  while (t--) {
    int n, d, h; cin >> n >> d >> h;
    int ly = -inf;
    ld ret = 0;
    for (int i = 0; i < n; ++i) {
      int y; cin >> y;
      ld dy = y - ly;
      if (dy < h)
        ret -= (ld) (h - dy) * (((h - dy) / h) * d) / 2;
      ret += (ld) h * d / 2;
      ly = y;
    }
    cout << fixed << setprecision(10) << ret << endl;
  }
}
