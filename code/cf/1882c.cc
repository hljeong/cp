#include <bits/stdc++.h>
#define A first
#define B second
#define pb push_back
#define endl '\n'
using namespace std;
template <typename T> using vc = vector<T>;
using ll = long long;
using ld = long double;
using vi = vc<int>;
using vll = vc<ll>;
using si = set<int>;
using sll = set<ll>;
using pi = pair<int, int>;
using pll = pair<ll, ll>;
using qi = queue<int>;
using mi = map<int, int>;

// #define max(a, b) ((a) > (b) ? (a) : (b))
// #define min(a, b) ((a) < (b) ? (a) : (b))
template <class T, class U> T max(T a, U b) { return a > b ? a : b; }
template <class T, class U> T min(T a, U b) { return a < b ? a : b; }
template <class T, class U> bool ckmin(T &a, U b) {
  return b < a ? a = b, 1 : 0;
}
template <class T, class U> bool ckmax(T &a, U b) {
  return a < b ? a = b, 1 : 0;
}

constexpr int inf = 1e9 + 7;
constexpr int mod = 1e9 + 7;
constexpr ll infll = 0x3f3f'3f3f'3f3f'3f3fll;

int main() {
  cin.tie(0)->sync_with_stdio(0);

  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    vi a(n);
    for (int i = 0; i < n; i++) {
      cin >> a[i];
    }
    vll sufmax(n + 1);
    for (int i = n - 1; i >= 0; i--) {
      sufmax[i] = sufmax[i + 1] + max(a[i], 0);
    }
    ll ans = 0;
    // given a set of indices to be taken, parity only matters for the lowest
    // index:
    //   take as many of non-lowest indices as possible. only even indices will
    //   remain now take the lowest index. all other indices will become odd,
    //   take in reverse order
    //
    // after reading https://codeforces.com/contest/1882/submission/225101650
    // the lowest index to take can always be 0 or 1... (or dont take anything)
    for (int i = 0; i < n; i++) {
      if (i & 1) {
        ckmax(ans, sufmax[i + 1]);
      } else {
        ckmax(ans, a[i] + sufmax[i + 1]);
      }
    }
    cout << ans << endl;
  }
}
