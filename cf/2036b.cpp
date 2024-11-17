#include <bits/stdc++.h>
using namespace std;
using vi = vector<int>;

int main() {
  int t;
  cin >> t;
  while (t--) {
    int n, k;
    cin >> n >> k;
    vi sc(k);
    for (int i = 0; i < k; ++i) {
      int b, c;
      cin >> b >> c;
      --b;
      sc[b] += c;
    }
    sort(sc.begin(), sc.end());
    reverse(sc.begin(), sc.end());
    n = min(n, k);
    long long ans = 0;
    for (int i = 0; i < n; ++i)
      ans += sc[i];
    cout << ans << endl;
  }
}
