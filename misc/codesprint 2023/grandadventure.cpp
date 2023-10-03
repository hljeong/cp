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

  int n, x; cin >> n >> x;
  vc<pll> good, bad;
  for (int i = 0; i < n; ++i) {
    pll p; cin >> p.A >> p.B;
    if (p.A <= p.B) good.pb({p.A, p.B});
    else bad.pb({p.A, p.B});
  }
  sort(good.begin(), good.end());
  for (pll p : good) {
    if (x <= p.A) return !printf("%s\n", "no shot");
    else x += p.B - p.A;
  }
}
