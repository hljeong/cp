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
    int n; cin >> n;
    vi a(n); for (int i = 0; i < n; ++i) cin >> a[i];
    vi b(n); for (int i = 0; i < n; ++i) cin >> b[i];
    vi l(32 * n), r(32 * n), c(32 * n);
    int id = 1;
    for (int x : b) {
      int bit = 31, cur = 0;
      while (!((x >> bit) & 1)) --bit;
      while (bit >= 0) {
        if ((x >> bit) & 1) {
          if (!r[cur]) r[cur] = id++;
          cur = r[cur];
        } else {
          if (!l[cur]) l[cur] = id++;
          cur = l[cur];
        }
        --bit;
        ++c[cur];
      }
    }
    bool good = true;
    for (int x : a) {
      int bit = 31, cur = 0;
      while (!((x >> bit) & 1)) --bit;
      while (bit >= 0 && (x & ((1 << (bit + 1)) - 1))) {
        if ((x >> bit) & 1) {
          if (!r[cur]) {
            good = false;
            break; 
          }
          cur = r[cur];
        } else {
          if (!l[cur]) {
            good = false;
            break;
          }
          cur = l[cur];
        }
        --bit;
        good &= --c[cur] >= 0;
      }
    }
    cout << (good ? "YES" : "NO") << endl;
  }
}