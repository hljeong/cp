#include <bits/stdc++.h>
using namespace std;
using vi = vector<int>;

int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    vi a(n);
    for (int i = 0; i < n; ++i)
      cin >> a[i];
    bool good = true;
    for (int i = 1; i < n; ++i) {
      int d = abs(a[i] - a[i - 1]);
      good &= (d == 5) or (d == 7);
    }
    cout << (good ? "yes" : "no") << endl;
  }
}
