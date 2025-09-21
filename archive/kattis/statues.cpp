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
  int n, m; cin >> n >> m;
  vc<vll> a(n, vll(m));
  vll sorted, rsorted;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      cin >> a[i][j];
      if (a[i][j] != -1) {
        sorted.pb(a[i][j]);
        rsorted.pb(a[i][j]);
      }
    }
  }
  sort(sorted.begin(), sorted.end());
  sort(rsorted.rbegin(), rsorted.rend());
  int p = 0, rp = 0, ret = inf, mv = 0, rmv = 0;
  for (int d = 0; d < n + m - 1; ++d) {
    sll s, rs;
    for (int i = 0; i < n; ++i) {
      int j = d - i;
      if (j < 0 || j >= m) continue;
      if (a[i][j] != -1) {
        s.insert(sorted[p++]);
        rs.insert(rsorted[rp++]);
      }
    }
    for (int i = 0; i < n; ++i) {
      int j = d - i;
      if (j < 0 || j >= m) continue;
      if (a[i][j] != -1) {
        if (!s.count(a[i][j])) ++mv;
        if (!rs.count(a[i][j])) ++rmv;
      }
    }
  }
  ckmin(ret, mv);
  ckmin(ret, rmv);
  // cout << mv << ' ' << rmv << endl;
  p = rp = mv = rmv = 0;
  for (int d = 0; d < n + m - 1; ++d) {
    sll s, rs;
    for (int i = 0; i < n; ++i) {
      int j = m - 1 - (d - i);
      if (j < 0 || j >= m) continue;
      if (a[i][j] != -1) {
        s.insert(sorted[p++]);
        rs.insert(rsorted[rp++]);
      }
    }
    for (int i = 0; i < n; ++i) {
      int j = m - 1 - (d - i);
      if (j < 0 || j >= m) continue;
      if (a[i][j] != -1) {
        if (!s.count(a[i][j])) ++mv;
        if (!rs.count(a[i][j])) ++rmv;
      }
    }
  }
  ckmin(ret, mv);
  ckmin(ret, rmv);
  // cout << mv << ' ' << rmv << endl;
  cout << ret << endl;
}