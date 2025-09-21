#include <bits/stdc++.h>
#define A first
#define B second
#define vc vector
#define pb push_back
using namespace std;
using ll = long long; using ld = long double;
using vi = vc<int>; using vll = vc<ll>;
using si = set<int>; using sll = set<ll>;
using pii = pair<int, int>; using pll = pair<ll, ll>;
using mii = map<int, int>;

template<class T> bool ckmin(T &a, const T &b) { return b < a ? a = b, 1 : 0; }
template<class T> bool ckmax(T &a, const T &b) { return a < b ? a = b, 1 : 0; }

const int inf = 1e9 + 7;
const int mod = inf;
const ll infll = 0x3f3f3f3f3f3f3f3fll;

int main() {
  ll n, a; cin >> n >> a;
  ll sum = 0;
  vll d(n);
  for (int i = 0; i < n; ++i) {
    cin >> d[i];
    sum += d[i];
  }
  for (int i = 0; i < n; ++i) {
    ll qsum = sum - d[i];
    ll lb = max(1ll, (ll) a - qsum);
    ll ub = min((ll) d[i], (ll) a - (n - 1));
    ll bad = min((ll) d[i], max(0ll, (ll) d[i] - (ub - lb + 1)));
    cout << bad << " \n"[i == n - 1];
  }
}
