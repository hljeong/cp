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

template<class T> bool ckmin(T &a, const T &b) { return b < a ? a = b, 1 : 0; }
template<class T> bool ckmax(T &a, const T &b) { return a < b ? a = b, 1 : 0; }

int main() {
  int g, t, n, w = 0; cin >> g >> t >> n;
  for (int i = 0; i < n; ++i) {
    int wi; cin >> wi;
    w += wi;
  }
  cout << (g - t) * 9 / 10 - w << endl;
}
