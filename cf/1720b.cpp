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
    int n; cin >> n;
    vi a(n); for (int i = 0; i < n; ++i) cin >> a[i];
    int mx = -1, mx2 = -1, mn = inf, mn2 = inf;
    for (int i = 0; i < n; ++i) {
      if (a[i] >= mx) {
        mx2 = mx;
        mx = a[i];
      } else if (a[i] > mx2) mx2 = a[i];
      if (a[i] <= mn) {
        mn2 = mn;
        mn = a[i];
      } else if (a[i] < mn2) mn2 = a[i];
    }
    cout << mx + mx2 - mn - mn2 << endl;
  }
}
