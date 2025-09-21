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
    int x; cin >> x;
    vi k(4); cin >> k[1] >> k[2] >> k[3];
    set<int> v;
    v.insert(x);
    for (int i = 0; i < 3; ++i) {
      set<int> nv;
      for (int key : v) {
        nv.insert(key);
        if (k[key]) nv.insert(k[key]);
      }
      v = nv;
    }
    cout << (v.size() == 3 ? "YES" : "NO") << endl;
  }
}  