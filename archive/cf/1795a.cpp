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

// can't have more than 1 adjacent same colors
// check bottom of each stack if there is adjacent same color
int main() {
  cin.tie(0) -> sync_with_stdio(0);

  int t; cin >> t;
  while (t--) {
    int n, m; cin >> n >> m;
    string a, b; cin >> a >> b;
    int same = 0;
    for (int i = 1; i < n; ++i) same += a[i] == a[i - 1];
    for (int i = 1; i < m; ++i) same += b[i] == b[i - 1];
    if (same == 1 && a[n - 1] == b[m - 1]) same = 2;
    cout << (same <= 1 ? "YES" : "NO") << endl;
  }
}
