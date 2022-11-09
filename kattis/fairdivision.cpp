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
  int t; cin >> t;
  while (t--) {
    int p, n; cin >> p >> n;
    vc<pii> a(n); for (int i = 0; i < n; ++i) {
      cin >> a[i].A;
      a[i].B = -i;
    }
    sort(a.begin(), a.end());
    vi ret(n);
    for (int i = 0; i < n; ++i) {
      ret[-a[i].B] = min(a[i].A, p / (n - i));
      p -= ret[-a[i].B];
    }
    if (p) cout << "IMPOSSIBLE" << endl;
    else for (int i = 0; i < n; ++i) cout << ret[i] << " \n"[i == n - 1];
  }
}
