#include <bits/stdc++.h>
#define A first
#define B second
#define vc vector
#define pb push_back
using namespace std;
using ll = long long; using ld = long double;
using vi = vc<int>; using vll = vc<ll>;
using si = set<int>; using sll = set<ll>;
using pii = pair<int, int>; using pll = pair<ll, ll>;
using mii = map<int, int>;

template<class T> bool ckmin(T &a, const T &b) { return b < a ? a = b, 1 : 0; }
template<class T> bool ckmax(T &a, const T &b) { return a < b ? a = b, 1 : 0; }

const int inf = 1e9 + 7;
const int mod = inf;
const ll infll = 0x3f3f3f3f3f3f3f3fll;

int main() {
  string s; cin >> s;
  int n = s.length(), mx = 1;
  vi dp(26);
  for (int i = 0; i < n; ++i) {
    int pmx = 0;
    for (int j = 0; j < s[i] - 'a'; ++j) ckmax(pmx, dp[j]);
    ckmax(dp[s[i] - 'a'], pmx + 1);
    ckmax(mx, pmx + 1);
  }
  cout << (26 - mx) << endl;
}
