#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin >> n;
  while (n--) {
    int x, y, g, u, v;
    cin >> x >> y;
    g = __gcd(x - 1, y - 1);
    u = (x - 1) / g;
    v = (y - 1) / g;
    cout << g * u * v + 1 - (u - 1) * (v - 1) / 2 << endl;
  }
}