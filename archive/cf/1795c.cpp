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

// for each tea, find taster who will finish it
// each taster drinks all the finishes + b[i] * number of unfinished tea
int main() {
  cin.tie(0) -> sync_with_stdio(0);

  int t; cin >> t;
  while (t--) {
    int n; cin >> n;
    vi a(n), b(n);
    for (int i = 0; i < n; ++i) cin >> a[i];
    for (int i = 0; i < n; ++i) cin >> b[i];
    // p = prefix sum on b
    vll ret(n), p(n + 1);
    vi finish(n);
    for (int i = 0; i < n; ++i) {
      p[i + 1] = p[i] + b[i];
    }
    for (int i = 0; i < n; ++i) {
      int fin = n;
      // binary search for taster who finishes a[i]
      for (int l = i, r = n - 1; l <= r;) {
        int m = l + (r - l) / 2;
        if (p[m + 1] - p[i] >= a[i]) {
          fin = m;
          r = m - 1;
        } else l = m + 1;
      }
      // add amt of finished tea to taster
      // add to count of finished teas of taster
      if (fin < n) {
        ret[fin] += a[i] - (p[fin] - p[i]);
        ++finish[fin];
      }
    }
    ll cnt = 0;
    for (int i = 0; i < n; ++i) {
      // cumulatively keep track of finished drinks
      cnt += 1 - finish[i];
      ret[i] += cnt * b[i];
    }
    // for (int i = 0; i < n; ++i) cout << finish[i] << " \n"[i == n - 1];
    for (int i = 0; i < n; ++i) cout << ret[i] << " \n"[i == n - 1];
  }
}
