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
  int n, m; cin >> n >> m;
  vi a(n + 2);
  for (int i = 1; i <= n; ++i) {
    cin >> a[i];
  }
  vll f(n + 1), b(n + 1);
  for (int i = 1; i <= n; ++i) {
    f[i] = f[i - 1] + max(0, a[i - 1] - a[i]);
  }
  for (int i = n - 1; i >= 0; --i) {
    b[i] = b[i + 1] + max(0, a[i + 2] - a[i + 1]);
  }
  for (int i = 0; i < m; ++i) {
    int s, t; cin >> s >> t;
    if (s > t) {
      cout << (b[t - 1] - b[s - 1]) << endl;
    } else {
      cout << (f[t] - f[s]) << endl;
    }
  }
}