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

ll phi(ll n) {
  ll ret = n;
  for (ll i = 2; i * i <= n; ++i) {
    if (!(n % i)) {
      while (!(n % i)) n /= i;
      ret -= ret / i;
    }
  }
  if (n > 1) ret -= ret / n;
  return ret;
}

ll f(ll n, ll k) {
  if (k == 1) {
    return phi(n);
  } else if (k & 1) {
    if (phi(n) == n) return n;
    else return f(phi(n), k - 1);
  } else {
    return f(n, k - 1);
  }
}

// f(n) = phi(n)
// g(n) = n (why???)
// F_k(n) = phi(n), k = 1
// F_k(n) = F_{k - 1}(n), k even
// F_k(n) = phi(F_{k - 1}(n)), k = 1, k odd
int main() {
  cin.tie(0) -> sync_with_stdio(0);
  
  ll n, k; cin >> n >> k;
  cout << (f(n, k) % mod) << endl;
}
