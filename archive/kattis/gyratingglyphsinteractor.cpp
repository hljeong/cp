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

mt19937 rng(rand());

int main() {
  int n; cin >> n;
  ll mask = rng() % (1ll << n);
  for (int i = 0; i < n; ++i) cout << (((mask >> i) & 1) ? '+' : 'x');
  cout << endl;
  while (true) {
    vi a(n + 1); for (int i = 0; i <= n; ++i) cin >> a[i];
    ll ret = a[0];
    for (int i = 0; i < n; ++i) {
      if ((mask >> i) & 1) ret = (ret + a[i + 1]) % mod;
      else ret = (ret * a[i + 1]) % mod;
    }
    cout << ret << endl;
  }
}