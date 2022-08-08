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
  while (t --> 0) {
    int n;
    cin >> n;
    set<int> s;
    bool good = true, one = false;
    for (int i = 0; i < n; ++i) {
      int a;
      cin >> a;
      if (a == 1) one = true;
      if (s.find(a - 1) != s.end() || s.find(a + 1) != s.end()) good = false;
      s.insert(a);
    }
    cout << (good || !one ? "YES" : "NO") << endl;
  }
}