#include <bits/stdc++.h>
using namespace std;
#define vc vector
using vi = vc<int>;
using ll = long long;

const int maxn = 1e5+5;
const int inf = 1e9;

int main() {
  ll n, m, a; cin >> n >> m >> a;
  ll b = n * m - a;
  if (!(a % m) || !(a % n) || !(b % m) || !(b % n)) {
    cout << 1 << endl;
    return 0;
  }
  for (ll w = 1; w * w <= a; ++w) {
    if (!(a % w)) {
      ll h = a / w;
      if (w < n && h < m || w < m && h < n) {
        cout << 2 << endl;
        return 0;
      }
    }
  }
  for (ll w = 1; w * w <= b; ++w) { 
    if (!(b % w)) {
      ll h = b / w;
      if (w < n && h < m || w < m && h < n) {
        cout << 2 << endl;
        return 0;
      }
    }
  }
  cout << 3 << endl;
}