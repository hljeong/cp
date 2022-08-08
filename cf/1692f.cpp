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
    vi a(n), f(10);
    for (int i = 0; i < n; ++i) cin >> a[i], ++f[a[i] % 10];
    bool good = false;
    for (int i = 0; i < 10; ++i) {
      for (int j = 0; j < 10; ++j) {
        for (int k = 0; k < 10; ++k) {
          if ((i + j + k) % 10 == 3) {
            bool bad = false;
            if (--f[i] < 0) bad = true;
            if (--f[j] < 0) bad = true;
            if (--f[k] < 0) bad = true;
            ++f[i];
            ++f[j];
            ++f[k];
            if (!bad) good = true;
          }
        }
      }
    }
    cout << (good ? "YES" : "NO") << endl;
  }
}