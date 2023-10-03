#include <bits/stdc++.h>
#define A first
#define B second
#define vc vector
#define pb push_back
#define endl '\n'
using namespace std;
using ll = long long; using ld = long double;
using vi = vc<int>; using vll = vc<ll>;
using si = set<int>; using sll = set<ll>;
using pi = pair<int, int>; using pll = pair<ll, ll>;
using qi = queue<int>; using mi = map<int, int>;

template<class T> bool ckmin(T &a, const T &b) { return b < a ? a = b, 1 : 0; }
template<class T> bool ckmax(T &a, const T &b) { return a < b ? a = b, 1 : 0; }

const int inf = 1e9 + 7;
const int mod = inf;
const ll infll = 0x3f3f3f3f3f3f3f3fll;

int main() {
  cin.tie(0) -> sync_with_stdio(0);

  int t; cin >> t;
  while (t--) {
    ll n, x, p, ox; cin >> n >> x >> p;
    ox = x;
    sll cyc;
    for (int i = 1; i < 2 * n; ++i) {
      x += i;
      x %= n;
      cyc.insert(x);
    }
    ll delta = ((x - ox) % n + n) % n;
    int g = 0;
    for (int i = 1; i <= min(p / (2 * n), n); ++i) {
      if (cyc.count((i * (n - delta)) % n)) {
        g = 1;
      }
    }
    x = (ox + p / (2 * n) * delta) % n;
    for (int i = 1; i <= p % (2 * n); ++i) {
      x += i;
      x %= n;
      if (!x) g = 1;
    }
    cout << (g ? "Yes" : "No") << endl;
  }
}
