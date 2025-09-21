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
  ld a, b, c, d; cin >> c >> d >> a >> b;
  cout << ((a * c + b * d) / (a * a + b * b)) << ' ' << ((a * d - b * c) / (a * a + b * b)) << endl;
}
