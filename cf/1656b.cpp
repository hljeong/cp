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

const int maxn = 2e5 + 5;

int main() {
  int t;
  cin >> t;
  while (t --> 0) {
    int n, k;
    cin >> n >> k;
    set<int> s;
    bool good = false;
    for (int i = 0; i < n; ++i) {
      int a;
      cin >> a;
      if (s.find(a - k) != s.end() || s.find(a + k) != s.end()) good = true;
      s.insert(a);
    }
    cout << (good ? "YES" : "NO") << endl;
  }
}