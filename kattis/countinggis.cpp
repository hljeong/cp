#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int maxn = 1e6 + 5;
int n, l, g[maxn]; 
ll ans = 1, mod = 1e9 + 7;
bool seq[maxn], bad = false;

int main() {
  cin >> n >> l;
  for (int i = 0; i < l; ++i) {
    cin >> g[i];
    --g[i];
    if (i && g[i] <= g[i - 1]) bad = true;
    seq[g[i]] = true;
  }
  if (bad) {
    cout << 0 << endl;
    return 0;
  }
  for (int i = n - 1; i >= 0; --i) {
    if (!seq[i]) {
      ans = ans * (n - i - 1) % mod;
    }
  }
  cout << ans << endl;
}