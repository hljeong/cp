#include <bits/stdc++.h>
#define A first
#define B second
#define vc vector
#define pb push_back
using namespace std;
using ll = long long; using ld = long double;
using vi = vc<int>; using vll = vc<ll>;
using si = set<int>; using sll = set<ll>;
using pii = pair<int, int>; using mii = map<int, int>;

template<class T> bool ckmin(T &a, const T &b) { return b < a ? a = b, 1 : 0; }
template<class T> bool ckmax(T &a, const T &b) { return b > a ? a = b, 1 : 0; }

const int inf = 1e9 + 7;
const int mod = inf;
const ll infll = 0x3f3f3f3f3f3f3f3fll;

int main() {
  int n, s, k; cin >> n >> s >> k;
  vll x(n); for (int i = 0; i < n; ++i) {
    cin >> x[i];
    x[i] <<= 1;
  }
  sort(x.begin(), x.end());
  for (int i = 1; i < n; ++i) {
    if (x[i] < x[i - 1] + 2 * s) return !printf("-1\n");
  }
  ll ret = 0, last = -infll;
  for (int i = 0; i < n - 1; ++i) {
    ll len = min(ll(k), min(x[i + 1] - x[i] - s, x[i] - last));
    last = x[i] + len;
    ret += len;
  }
  ll len = min(ll(k), x[n - 1] - last);
  ret += len;
  cout << ret << endl;
}