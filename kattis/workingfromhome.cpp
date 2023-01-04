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
  int m, p, n; cin >> m >> p >> n;
  int target = m, ret = 0;
  for (int i = 0; i < n; ++i) {
    int w; cin >> w;
    if (w >= target) ++ret;
    int delta = w - target;
    if (delta < 0) target = m + (-delta * p + 99) / 100;
    else target = m - delta * p / 100;
    // cout << delta << ", " << target << endl;
  }
  cout << ret << endl;
}