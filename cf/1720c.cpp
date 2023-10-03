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
    int n, m; cin >> n >> m;
    vc<string> mp(n);
    for (int i = 0; i < n; ++i) cin >> mp[i];
    int tcnt = 0, ret = 0;
    for (int i = 0; i < n; ++i) for (int j = 0; j < m; ++j) tcnt += mp[i][j] - '0';
    for (int i = 0; i < n - 1; ++i) {
      for (int j = 0; j < m - 1; ++j) {
        int cnt = mp[i][j] + mp[i][j + 1] + mp[i + 1][j] + mp[i + 1][j + 1] - 4 * '0';
        ckmax(ret, tcnt - cnt + min(cnt, 2));
      }
    }
    cout << ret << endl;
  }
}
