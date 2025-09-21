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

int main() {
  cin.tie(0) -> sync_with_stdio(0);

  // use only segments covering k
  // find intersection of all such segments and see if width 1
  int t; cin >> t;
  while (t--) {
    int n, k; cin >> n >> k;
    vi l(n), r(n);
    for (int i = 0; i < n; ++i) cin >> l[i] >> r[i];
    int lb = -inf, rb = inf;
    for (int i = 0; i < n; ++i) {
      if (l[i] <= k && k <= r[i]) {
        ckmax(lb, l[i]);
        ckmin(rb, r[i]);
      }
    }
    cout << (lb == rb ? "YES" : "NO") << endl;
  }
}
