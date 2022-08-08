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
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    vi a(n), b(n);
    for (int i = 0; i < n; ++i) cin >> a[i];
    for (int i = 0; i < n; ++i) cin >> b[i];
    bool bad = false;
    for (int i = 0; i < n; ++i) if (a[i] < b[i]) bad = true;
    int d = 0;
    for (int i = 0; i < n; ++i) ckmax(d, a[i] - b[i]);
    for (int i = 0; i < n; ++i) a[i] = max(0, a[i] - d);
    for (int i = 0; i < n; ++i) if (a[i] != b[i]) bad = true;
    cout << (bad ? "NO" : "YES") << endl;
  }
}