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
const int mod = 998244353;
const ll infll = 0x3f3f3f3f3f3f3f3fll;

template<int M>
struct modint {
  int v;
  explicit operator int() const { return v; }

  modint() : v(0) {}
  modint(ll _v) { 
    v = int((-M <= _v && _v < M) ? _v : _v % M);
    if (v < 0) v += M;
  }

  bool operator==(const modint &o) const { return v == o.v; }
  friend bool operator!=(const modint &a, const modint &b) { return !(a == b); }
  friend bool operator<(const modint &a, const modint &b) { return a.v < b.v; }
   
  modint& operator+=(const modint &o) { if ((v += o.v) >= M) v -= M; return *this; }
  modint& operator-=(const modint &o) { if ((v -= o.v) < 0) v += M; return *this; }
  modint& operator*=(const modint &o) { v = int((ll)v * o.v % M); return *this; }
  modint& operator/=(const modint &o) { return (*this) *= inv(o); }

  friend modint inv(const modint &x);
  friend modint pow(modint b, ll e) {
    if (e < 0) return pow(inv(b), -e);
    modint ans = 1;
    for (; e; e >>= 1, b *= b) if (e & 1) ans *= b;
    return ans;
  }
  friend modint inv(const modint &x) {
    assert(x.v != 0); 
    return pow(x, M - 2);
  }
    
  modint operator-() const { return modint(-v); }
  modint& operator++() { return *this += 1; }
  modint& operator--() { return *this -= 1; }
  friend modint operator+(modint a, const modint& b) { return a += b; }
  friend modint operator-(modint a, const modint& b) { return a -= b; }
  friend modint operator*(modint a, const modint& b) { return a *= b; }
  friend modint operator/(modint a, const modint& b) { return a /= b; }

  friend ostream& operator<<(ostream& stream, const modint& x) { stream << int(x); return stream; }
  friend istream& operator>>(istream& stream, modint& x) { stream >> x.v; return stream; }
};

using mint = modint<mod>;

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

int main() {
  cin.tie(0) -> sync_with_stdio(0);

  vi dv = sieve(1000005);
  vc<mint> fact(4050), ifact(4050);
  fact[0] = fact[1] = ifact[0] = ifact[1] = 1;
  for (int i = 2; i < 4050; ++i) {
    fact[i] = i * fact[i - 1];
    ifact[i] = 1 / fact[i];
  }
  int n; cin >> n;
  mi f; for (int i = 0, ai; i < 2 * n; ++i) {
    cin >> ai;
    ++f[ai];
  }
  vi pf;
  mint ret = fact[n];
  for (auto [x, fx] : f) {
    if (dv[x] == x) pf.pb(fx);
    else ret *= ifact[fx];
  }
  int k = pf.size();
  if (k < n) {
    cout << 0 << endl;
    return 0;
  }
  vc<vc<mint>> dp(k + 1, vc<mint>(n + 1));
  dp[0][0] = 1;
  for (int i = 0; i < k; ++i) {
    for (int j = 0; j <= n; ++j) {
      dp[i + 1][j] += dp[i][j] * ifact[pf[i]];
      if (j) dp[i + 1][j] += dp[i][j - 1] * ifact[pf[i] - 1];
    }
  }
  cout << (ret * dp[k][n]) << endl;
}
