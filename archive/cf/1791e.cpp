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
    vll a(n); for (int i = 0; i < n; ++i) cin >> a[i];
    ll f = -a[0] - a[1], nf = -f, mx2 = -infll;
    for (int i = 2; i < n; ++i) {
      // cout << f2 << ' ' << nf2 << ' ' << f << ' ' << nf << endl;
      ll newf, newnf;
      newf = max(f + 2 * a[i - 1] - a[i], nf - 2 * a[i - 1] - a[i]);
      newnf = max(f + a[i], nf + a[i]);
      ckmax(newf, mx2 - a[i - 1] - a[i]);
      ckmax(newnf, mx2 + a[i - 1] + a[i]);
      mx2 = max(f, nf); f = newf; nf = newnf;
    }
    cout << max(f, nf) << endl;
  }
}
