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
  int n; cin >> n;
  vc<string> v(n); for (int i = 0; i < n; ++i) cin >> v[i];
  vc<string> inc = v, dec = v;
  sort(inc.begin(), inc.end());
  sort(dec.rbegin(), dec.rend());
  if (v == inc) {
    cout << "INCREASING" << endl;
  } else if (v == dec) {
    cout << "DECREASING" << endl;
  } else {
    cout << "NEITHER" << endl;
  }
}
