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
    cout << 2 << endl; 
    set<int> used;
    for (int i = 1; i <= n; ++i) {
      if (used.find(i) == used.end()) {
        if (i > 1) cout << ' ';
        cout << i;
        used.insert(i);
        int j = 2 * i;
        while (j <= n) {
          cout << ' ';
          cout << j;
          used.insert(j);
          j <<= 1;
        }
      }
    }
    cout << endl;
  }
}