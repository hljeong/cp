#include <bits/stdc++.h>
using namespace std;
using ll = long long;
template <typename T> using vc = vector<T>;
using vi = vc<int>;

#define max(a, b) ((a) > (b) ? (a) : (b))

int main() {
  ll a, b;
  cin >> a >> b;
  ll x, y, z;
  cin >> x >> y >> z;

  ll a_ = 2 * x + y;
  ll b_ = y + 3 * z;
  cout << (max(a_ - a, 0) + max(b_ - b, 0)) << endl;
}
