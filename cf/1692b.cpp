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
    vi a(n), f(10005);
    set<int> s;
    int cnt = 0;
    for (int i = 0; i < n; ++i) {
      cin >> a[i];
      ++f[a[i]];
      s.insert(a[i]);
    }
    for (int i = 0; i <= 10000; ++i) cnt += max(0, f[i] - 1);
    cout << (s.size() - (cnt & 1)) << endl;
  }
}