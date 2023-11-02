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

  // n pairs, k known
  // flip known: k / (2 * n - k)
  // flip unknown: 2 * (n - k) / (2 * n - k)
  // flip unknown then match: 2 * (n - k) / (2 * n - k) * 1 / (2 * n - k - 1)
  // flip pair in 1: p1 = 1 / (2 * n - 1)
  // p2 = (1 - p1) * (1 / (n - 1) + (n - 2) / (n - 1) / (2 * n - 3))

  int n; cin >> n;
  // e[i][j] = expectation to get to i pairs remain, j cards known
  vc<vc<ld>> e(n + 1, vc<ld>(n + 1));
  for (int i = 0; i <= n; ++i) {
    for (int j = i; j >= 0; --j) {
      ld to_pick = 2 * i - j;
      ld p_unknown = (ld) 2 * (i - j) / to_pick;
      // flip 2 unknown
      if (j <= i - 2) e[i][j] += p_unknown * ((ld) (to_pick - 1 - j - 1) / (to_pick - 1)) * (1 + e[i][j + 2]);
      // flip unkown pair
      if (i && j < i) e[i][j] += p_unknown * ((ld) 1 / (to_pick - 1)) * (1 + e[i - 1][j]);
      // flip 1 unknown 1 known
      if (i && j < i) e[i][j] += p_unknown * ((ld) j / (to_pick - 1)) * (2 + e[i - 1][j]);
      // flip 1 known
      if (i && j) e[i][j] += ((ld) j / to_pick) * (1 + e[i - 1][j - 1]);
    }
  }
  /*
  for (int i = 0; i <= n; ++i) {
    for (int j = 0; j <= i; ++j) {
      cout << e[i][j] << " \n"[j == i];
    }
  }
  */
  cout << fixed << setprecision(8) << e[n][0] << endl;
}
