#include <bits/stdc++.h>
#define A first
#define B second
#define vc vector
using namespace std;
using ll = long long;
using vi = vc<int>;
using vll = vc<ll>;
using pii = pair<int, int>;

template<class T> bool ckmin(T& a, const T& b) { return b < a ? a = b, 1 : 0; }
template<class T> bool ckmax(T& a, const T& b) { return a < b ? a = b, 1 : 0; }

const int maxn = 1005, mod = 1e9 + 7;
int dp[2][maxn];

int main() {
  int h, w;
  cin >> h >> w;
  dp[0][0] = 1;
  string s;
  for (int i = 0; i < h; ++i) {
    cin >> s;
    for (int j = 0; j < w; ++j) {
      if (!i && !j) continue;
      if (s[j] == '#') dp[i & 1][j] = 0;
      else dp[i & 1][j] = (dp[(i & 1) ^ 1][j] + (j ? dp[i & 1][j - 1] : 0)) % mod;
    }
  }
  cout << dp[(h & 1) ^ 1][w - 1] << endl;
}