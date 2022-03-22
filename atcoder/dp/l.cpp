#include <bits/stdc++.h>
#define A first
#define B second
#define vc vector
using namespace std;
using ll = long long;
using ld = long double;
using vi = vc<int>;
using vll = vc<ll>;
using pii = pair<int, int>;

template<class T> bool ckmin(T& a, const T& b) { return b < a ? a = b, 1 : 0; }
template<class T> bool ckmax(T& a, const T& b) { return a < b ? a = b, 1 : 0; }

// another ez game theory

const int maxn = 3005;
ll a[maxn], dp[maxn][maxn];

int main() {
  int n;
  cin >> n;
  for (int i = 0; i < n; ++i) cin >> a[i];
  for (int l = 0; l < n; ++l) {
    for (int i = 0; i < n - l ; ++i) {
      dp[i][i + l] = max(a[i] - dp[i + 1][i + l], a[i + l] - dp[i][i + l - 1]);
    }
  }
  cout << dp[0][n - 1] << endl;
}