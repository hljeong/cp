#include <bits/stdc++.h>
using namespace std;
using ll = long long;
template <typename T> using vc = vector<T>;
using vi = vc<int>;

#define max(a, b) ((a) > (b) ? (a) : (b))

int main() {
  ll n, k;
  cin >> n >> k;
  if (k > 1) {
    ll m = 1ll << 61;
    while (m > n)
      m >>= 1;
    if (!m)
      m = 1;
    else
      m <<= 1;
    cout << (m - 1) << endl;
  } else {
    cout << n << endl;
  }
}
