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
    int n, m, k; cin >> n >> m >> k;
    string a; cin >> a;
    string b; cin >> b;
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    string c = "";
    int last = -1, run = 0, i = 0, j = 0;
    while (i < n && j < m) {
      if (a[i] < b[j]) {
        if (last == 0 && run == k) {
          c += b[j++];
          last = 1;
          run = 1;
        } else {
          c += a[i++];
          if (last == 1) run = 0;
          last = 0;
          ++run;
        }
      } else {
        if (last == 1 && run == k) {
          c += a[i++];
          last = 0;
          run = 1;
        } else {
          c += b[j++];
          if (last == 0) run = 0;
          last = 1;
          ++run;
        }
      }
    }
    cout << c << endl;
  }
}