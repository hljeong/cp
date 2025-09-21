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
using gr = vc<vi>; using wgr = vc<vc<pii>>;

template<class T> bool ckmin(T &a, const T &b) { return b < a ? a = b, 1 : 0; }
template<class T> bool ckmax(T &a, const T &b) { return a < b ? a = b, 1 : 0; }

const int inf = 1e9 + 7;
const int mod = inf;
const ll infll = 0x3f3f3f3f3f3f3f3fll;

int main() {
  int n; cin >> n;
  vc<vll> v(n, vll());
  for (int i = 0; i < n; ++i) {
    ll vi; cin >> vi;
    v[0].pb(vi);
  }
  {
    ll mn = infll, mx = -infll;
    for (int i = 0; i < n; ++i) {
      ckmin(mn, v[0][i]);
      ckmax(mx, v[0][i]);
    }
    if (mn == mx) {
      cout << "0 " << v[0][0] << endl;
      return 0;
    }
  }
  int d = n - 1;
  for (int i = 1; i < n; ++i) {
    ll mn = infll, mx = -infll;
    for (int j = 0; j < n - i; ++j) {
      v[i].pb(v[i - 1][j + 1] - v[i - 1][j]);
      ckmin(mn, v[i][j]);
      ckmax(mx, v[i][j]);
    }
    if (mn == mx) {
      d = i;
      break;
    }
  }
  v[d].pb(v[d][0]);
  for (int i = d - 1; i > 0; --i) {
    v[i].pb(v[i][v[i].size() - 1] + v[i + 1][v[i + 1].size() - 1]);
  }
  cout << d << " " << (v[0][n - 1] + v[1][n - 1]) << endl;
}
