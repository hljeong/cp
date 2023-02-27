#include <bits/stdc++.h>
using namespace std;
using vi = vector<int>;

const int maxn = 1e5+5;
const int inf = 1e9;

int main(){
  int n;
  cin >> n;
  vi t(n); for (int i = 0; i < n; ++i) cin >> t[i];
  int ret = -1, mx = inf;
  for (int i = 0; i < n - 2; ++i) {
    if (max(t[i], t[i + 2]) < mx) {
      mx = max(t[i], t[i + 2]);
      ret = i;
    }
  }
  cout << (ret + 1) << ' ' << mx << endl;
}