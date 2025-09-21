#include <bits/stdc++.h>
#define A first
#define B second
#define vc vector
using namespace std;
using ll = long long; using ld = long double;
using vi = vc<int>; using vll = vc<ll>;
using si = set<int>; using sll = set<ll>;
using pii = pair<int, int>; using mii = map<int, int>;
using gr = vc<vi>;

template<class T> bool ckmin(T &a, const T &b) { return b < a ? a = b, 1 : 0; }
template<class T> bool ckmax(T &a, const T &b) { return a < b ? a = b, 1 : 0; }

const int inf = 1e9 + 7;
const int mod = inf;

int main() {
  int n, m, k; cin >> n >> m >> k;
  int h = n;
  vi a(m); for (int i = 0; i < m; ++i) cin >> a[i];
  bool good = true;
  for (int i = 0; i < m; ++i) {
    n -= a[i];
    if (n <= 0) {
      if (k) {
        --k;
        n = h - a[i];
      }
      if (n <= 0) {
        good = false;
        break;
      }
    }
    int d = min(k, (h - n) / 20);
    k -= d;
    n += d * 20;
  }
  cout << (good ? "champion" : "next time") << endl;
}
