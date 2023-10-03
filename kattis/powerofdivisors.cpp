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

vi sieve(int n) {
  vi ret(n + 1);
  for (int i = 2, j = i; i <= n; j = ++i) {
    if (ret[i]) continue;
    while (j <= n) {
      ret[j] = i;
      j += i;
    }
  }
  return ret;
}

bool is_prime(ll n) {
  for (int i = 2; i * i <= n; ++i) {
    if (!(n % i)) return false;
  }
  return true;
}

ll ipow(int b, ll e) {
  if (!e) return 1;
  if (e == 1) return b;

  ll h = ipow(b, e / 2);
  if (e & 1) return b * h * h;
  return h * h;
}

int main() {
  cin.tie(0) -> sync_with_stdio(0);

  ll x; cin >> x;
  ll r1 = (ll) floor(sqrt(x)), r2 = (ll) ceil(sqrt(x));
  if (r1 * r1 == x && is_prime(r1)) return !printf("%lld\n", r1);
  if (r2 * r2 == x && is_prime(r2)) return !printf("%lld\n", r2);
  map<ll, int> mp; mp[1] = 1;
  vi div = sieve(1000000);
  for (int i = 2; i <= 1000000; ++i) {
    int ndiv = 1, j = i;
    while (div[j]) {
      int cnt = 0, k = div[j];
      while (!(j % k)) {
        j /= k;
        ++cnt;
      }
      ndiv *= cnt + 1;
    }
    if (ndiv > 2 && ndiv * log(i) <= log(2e18)) {
      mp[ipow(i, ndiv)] = i;
    }
  }
  if (mp.count(x)) cout << mp[x] << endl;
  else cout << -1 << endl;
}
