#include <bits/stdc++.h>
#define A first
#define B second
#define vc vector
using namespace std;
using ll = long long; using ld = long double;
using vi = vc<int>; using vll = vc<ll>;
using si = set<int>; using sll = set<ll>;
using pii = pair<int, int>; using mii = map<int, int>;
using gr = vc<vi>;

template<class T> bool ckmin(T &a, const T &b) { return b < a ? a = b, 1 : 0; }
template<class T> bool ckmax(T &a, const T &b) { return a < b ? a = b, 1 : 0; }

const int inf = 1e9 + 7;
const int mod = inf;

int id(char c){
    if (c == '(') return 0;
    if (c == ')') return 1;
    if (c == '[') return 2;
    if (c == ']') return 3;
    if (c == '{') return 4;
    if (c == '}') return 5;
    if (c == '<') return 6;
    if (c == '>') return 7;
    return -1;
}

bool open(char c) {
    return !(id(c) & 1);
}

bool match(char a, char b) {
    return (id(a) ^ id(b)) == 1 && open(a);
}

int main() {
  string s; cin >> s;
  int n = s.length();
  vc<vll> dp1(n + 1, vll(n + 1)), dp(n + 1, vll(n + 1));
  for (int i = 0; i <= n; ++i) dp1[i][i] = dp[i][i] = 1;
  for (int l = 2; l <= n; l += 2) {
    for (int i = 0; i <= n - l; ++i) {
      int j = i + l;
      char a = s[i], b = s[j - 1];
      if (a == '?' && b == '?') dp1[i][j] = 4 * dp[i + 1][j - 1];
      else if ((a == '?' && !open(b)) || (open(a) && b == '?') || match(a, b)) dp1[i][j] = dp[i + 1][j - 1];
      for (int k = i + 2; k <= j; k += 2) dp[i][j] += dp1[i][k] * dp[k][j];
    }
  }
  cout << dp[0][n] << endl;
}
