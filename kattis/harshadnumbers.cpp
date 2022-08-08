#include <bits/stdc++.h>
#define A first
#define B second
#define vc vector
using namespace std;
using ll = long long;
using ld = long double;
using vi = vc<int>;
using vll = vc<ll>;
using pii = pair<int, int>;

template<class T> bool ckmin(T& a, const T& b) { return b < a ? a = b, 1 : 0; }
template<class T> bool ckmax(T& a, const T& b) { return a < b ? a = b, 1 : 0; }

bool good(int n) {
  int dsum = 0, np = n;
  while (np) {
    dsum += np % 10;
    np /= 10;
  }
  return !(n % dsum);
}

int main() {
  int n;
  cin >> n;
  while (!good(n)) ++n;
  cout << n << endl;
}