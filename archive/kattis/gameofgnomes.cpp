#include <bits/stdc++.h>
using namespace std;
#define vc vector
using vi = vc<int>;
using ll = long long;

const int maxn = 1e5+5;
const int inf = 1e9;

int main() {
  ll n, m, k; cin >> n >> m >> k;
  ll tot = n % k, ret = 0;
  while (tot <= n && tot <= m * (k - 1)) {
    ll q = tot / m, r = tot % m, e = (n - tot) / k;
    ret = max(ret, r * (r + 1) / 2 + q * m * (m + 1) / 2 + k * e * (e + 1) / 2 + tot * e);
    tot += k;
  }
  cout << ret << endl;
}