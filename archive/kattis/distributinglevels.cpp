#include <bits/stdc++.h>
#define A first
#define B second
using namespace std;
using ll = long long;
using vi = vector<int>;
using vll = vector<ll>;

template<class T> bool ckmin(T& a, const T& b) { return b < a ? a = b, 1 : 0; }
template<class T> bool ckmax(T& a, const T& b) { return a < b ? a = b, 1 : 0; }

int main() {
  int n, min = 100;
  cin >> n;
  vi l(n), f(102);
  for (int i = 0; i < n; ++i) {
    cin >> l[i];
    ++f[l[i]];
    ckmin(min, l[i]);
  }
  if (f[100] && min < 99) return !printf("impossible\n");
  cout << (f[min] * (min - 1) + f[min + 1] * min >= n - f[min] - f[min + 1] ? "possible" : "impossible") << endl;
}
