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

int main() {
  int n;
  cin >> n;
  vi v(n);
  for (int i = 0; i < n; ++i) cin >> v[i];
  ll tot = 0, mn = 0;
  for (int i = 0; i < n; ++i) {
    tot += v[i];
    ckmax(mn, (tot + i) / (i + 1));
  }
  int q;
  cin >> q;
  while (q--) {
    int t;
    cin >> t;
    cout << (t < mn ? -1 : (tot + t - 1) / t) << endl;
  }
}