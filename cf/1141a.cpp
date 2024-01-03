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

// divide by 2s first and then divide by 3s

int main() {
  cin.tie(0) -> sync_with_stdio(0);

  int n, m; cin >> n >> m;
  // divide both by 2s until n is odd
  while (!(n & 1)) {
    n >>= 1;
    if (m & 1) return !printf("-1\n");
    m >>= 1;
  }
  int ans = 0;
  // keep dividing m by 2
  while (!(m & 1)) {
    ++ans;
    m >>= 1;
  }
  // divide m by 3 until <= n
  while (m > n) {
    if (m % 3) return !printf("-1\n");
    m /= 3;
    ++ans;
  }
  if (m == n) cout << ans << endl;
  else cout << "-1" << endl;
}
