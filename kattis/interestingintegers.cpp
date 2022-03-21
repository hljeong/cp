#include <bits/stdc++.h>
#define A first
#define B second
using namespace std;
using ll = long long;

pair<int, int> check(ll n, ll m) {
  int fn = n, fm = m;
  while (m <= n && m > 0) {
    fn = n;
    fm = m;
    n -= m;
    swap(n, m);
  }
  return {fm, fn};
}

bool lt(pair<int, int> &a, pair<int, int> &b) {
  if (a.B == b.B) {
    return a.A < b.A;
  }
  return a.B < b.B;
}

int main() {
  int t;
  cin >> t;
  while (t--) {
    ll n;
    pair<int, int> ans;
    cin >> n;
    for (int l = 1, r = n - 1; l <= r; ) {
      int m1 = l + (r - l) / 3;
      int m2 = r - (r - l) / 3;
      pair<int, int> rm1 = check(n, m1), rm2 = check(n, m2);
      if (lt(rm1, rm2)) {
        ans = rm1;
        r = m2 - 1;
      } else {
        ans = rm2;
        l = m1 + 1;
      }
    }
    cout << ans.A << ' ' << ans.B << endl;
  }
}