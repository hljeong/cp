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
  int a, b, c; cin >> a >> b >> c;
  if (b == 2 && c == 2 || c == 1 || a == 1) {
    cout << "What an excellent example!" << endl;
  } else {
    cout << "Oh look, a squirrel!" << endl;
  }
}
