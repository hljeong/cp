#include <bits/stdc++.h>
#define vc vector
using namespace std;
using ll = long long;
using vi = vc<int>;

int main() {
  int n; cin >> n;
  vi a(n);
  for (int i = 0; i < n; ++i) cin >> a[i];
  sort(a.begin(), a.end());
  int ret = 1e9;
  for (int i = 0; i < n / 2; ++i) ret = min(ret, a[i] + a[n - i - 1]);
  cout << ret << endl;
}
