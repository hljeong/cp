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

int cdiv(int a, int b) {
  return (a + b - 1) / b;
}

int main() {
  cin.tie(0) -> sync_with_stdio(0);

  int t; cin >> t;
  while (t--) {
    int n; cin >> n;
    vi a(n); for (int i = 0; i < n; ++i) {
      cin >> a[i];
    }
    vc<pi> ret;
    bool good = true;
    int j = -1;
    for (int i = 1; i < n; ++i) {
      if (a[i] != a[0]) j = i;
    }
    while (j != -1) {
      if (a[0] < a[j]) {
        ret.pb({j, 0});
        a[j] = cdiv(a[j], a[0]);
      } else {
        ret.pb({0, j});
        a[0] = cdiv(a[0], a[j]);
      }
      if (ret.size() > 30 * n) {
        good = false;
        break;
      }
      j = -1;
      for (int i = 1; i < n; ++i) {
        if (a[i] != a[0]) j = i;
      }
    }
    if (!good) {
      cout << -1 << endl;
      continue;
    }
    cout << ret.size() << endl;
    for (int i = 0; i < ret.size(); ++i) {
      cout << (ret[i].A + 1) << ' ' << (ret[i].B + 1) << endl;
    }
  }
}
