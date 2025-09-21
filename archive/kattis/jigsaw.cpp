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
  int c, e, m; cin >> c >> e >> m;
  if (c != 4 || e & 1) return !printf("impossible\n");
  if (!m) return !printf("%d 2", e / 2 + 2);
  for (ll ih = 1; ih * ih <= m; ++ih) {
    if (!(m % ih)) {
      int h = ih + 2, w = (int) (m / ih + 2);
      if (e == 2 * h + 2 * w - 8)
        return !printf("%d %d", w, h);
    }
  }
  cout << "impossible" << endl;
}