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
  int n; cin >> n;
  int s = 0;
  map<int, int> f;
  for (int i = 0; i < n; ++i) {
    int x; cin >> x; ++x;
    if (f.find(x) == f.end()) s += x;
    if (++f[x] == x) f.erase(f.find(x));
  }
  cout << s << endl;
}
