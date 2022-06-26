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

template<class T> bool ckmin(T& a, const T& b) { return b < a ? a = b, 1 : 0; }
template<class T> bool ckmax(T& a, const T& b) { return a < b ? a = b, 1 : 0; }

const int mod = 1e9 + 7; 

ll fpow(ll a, ll b) {
  if (!a) return 0;
  ll ans = 1;
  while (b) {
    if (b & 1) {
      ans *= a;
      ans %= mod;
    }
    a *= a;
    a %= mod;
    b >>= 1;
  }
  return ans;
}

int main() {
  vll fact(4e5 + 1), ifact(4e5 + 1);
  fact[0] = fact[1] = ifact[0] = ifact[1] = 1;
  for (int i = 2; i <= 4e5; ++i) {
    fact[i] = i * fact[i - 1] % mod;
    ifact[i] = fpow(fact[i], mod - 2);
  }
  int n;
  cin >> n;
  ++n;
  vi a(n);
  ll ans = 0;
  for (int i = 0; i < n; ++i) cin >> a[i];
  for (int i = 0; i < n; ++i) {
    if (!a[i]) break;
    ans += fact[i + a[i]] * ifact[a[i] - 1] % mod * ifact[i + 1] % mod;
    ans %= mod;
  }
  cout << ans << endl;
}