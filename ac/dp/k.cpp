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

// ez game theory; nim

const int maxn = 105, maxk = 1e5 + 5;
int a[maxn];
bool dp[maxk];

int main() {
  int n, k;
  cin >> n >> k;
  for (int i = 0; i < n; ++i) cin >> a[i];
  for (int i = 1; i <= k; ++i) {
    for (int j = 0; j < n; ++j) {
      if (a[j] > i) break;
      if (!dp[i - a[j]]) dp[i] = true;
    }
  }
  cout << (dp[k] ? "First" : "Second") << endl;
}