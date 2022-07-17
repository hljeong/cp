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
  int t; cin >> t;
  while (t--) {
    int n, k; cin >> n >> k;
    vi u(n); for (int i = 0; i < n; ++i) cin >> u[i];
    map<int, int> f, l;
    for (int i = 0; i < n; ++i) {
      f[u[n - i - 1]] = n - i;
      l[u[i]] = i + 1;
    }
    while (k--) {
      int a, b; cin >> a >> b;
      cout << (f[a] && l[b] && f[a] <= l[b] ? "YES" : "NO") << endl;
    }
  }
}