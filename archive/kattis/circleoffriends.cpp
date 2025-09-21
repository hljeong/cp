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

// http://serjudging.vanb.org/wp-content/uploads/circle_of_friends.pdf

const int inf = 1e9 + 7;
const int mod = 998244353;

struct mint {
  int v;
  explicit operator int() const { return v; }

  mint() : v(0) {}
  mint(ll _v) { 
    v = int((-mod <= _v && _v < mod) ? _v : _v % mod);
    if (v < 0) v += mod;
  }

  bool operator==(const mint& o) const { return v == o.v; }
  friend bool operator!=(const mint& a, const mint& b) { return !(a == b); }
  friend bool operator<(const mint& a, const mint& b) { return a.v < b.v; }
   
  mint& operator+=(const mint& o) { if ((v += o.v) >= mod) v -= mod; return *this; }
  mint& operator-=(const mint& o) { if ((v -= o.v) < 0) v += mod; return *this; }
  mint& operator*=(const mint& o) { v = int((ll)v * o.v % mod); return *this; }
  mint& operator/=(const mint& o) { return (*this) *= inv(o); }

  friend mint inv(const mint& x);
  friend mint pow(mint b, ll e) {
    if (e < 0) return pow(inv(b), -e);
    mint ans = 1;
    for (; e; e >>= 1, b *= b) if (e & 1) ans *= b;
    return ans;
  }
  friend mint inv(const mint& x) {
    assert(x.v != 0); 
    return pow(x, mod - 2);
  }
    
  mint operator-() const { return mint(-v); }
  mint& operator++() { return *this += 1; }
  mint& operator--() { return *this -= 1; }
  friend mint operator+(mint a, const mint& b) { return a += b; }
  friend mint operator-(mint a, const mint& b) { return a -= b; }
  friend mint operator*(mint a, const mint& b) { return a *= b; }
  friend mint operator/(mint a, const mint& b) { return a /= b; }

  friend ostream& operator<<(ostream& stream, const mint& x) { stream << int(x); return stream; }
  friend istream& operator>>(istream& stream, mint& x) { stream >> x.v; return stream; }
};

vc<mint> solve(vll &a) {
  int n = a.size();
  vc<vll> st(n, vll(20, 0));
  for (int i = 0; i < n; ++i) st[i][0] = a[i];
  for (int j = 0; j < 19; ++j) {
    for (int i = (1 << j); i < n; ++i) {
      st[i][j + 1] = st[i][j] & st[i - (1 << j)][j];
    }
  }
  vi l(n);
  for (int i = 0; i < n; ++i) {
    l[i] = i;
    ll kp = a[i];
    for (int j = 19; l[i] >= 0 && j >= 0; --j) {
      if (kp & st[l[i]][j]) {
        kp &= st[l[i]][j];
        l[i] -= 1 << j;
      }
    }
    ++l[i];
  }
  // for (int i = 0; i < n; ++i) cout << l[i] << " \n"[i == n - 1];
  vc<mint> dp(n + 1), pref(n + 2);
  dp[0] = pref[1] = 1;
  for (int i = 0; i < n; ++i) {
    dp[i + 1] = pref[i + 1] - pref[l[i]];
    pref[i + 2] = pref[i + 1] + dp[i + 1];
  }
  // for (int i = 0; i < n; ++i) cout << l[i] << " \n"[i == n - 1];
  // for (int i = 0; i <= n; ++i) cout << dp[i] << " \n"[i == n];
  // return pref[n + 1] - pref[n];
  return dp;
}

int main() {
  int n; cin >> n;
  mint on = n;
  vll a(n); for (int i = 0; i < n; ++i) cin >> a[i];
  mint ret = 0;
  vc<mint> last_ret;
  ll last = a[0] - 1;
  while (a.size() && a[0]) {
    if (a[0] != last) ret += (last_ret = solve(a))[n];
    else ret += last_ret[n];
    // for (int i = 0; i <= n; ++i) cout << last_ret[i] << " \n"[i == n];
    last = a[0];
    a[0] &= a[--n];
    a.pop_back();
  }
  if (!n) ret -= on - 1;
  cout << ret << endl;
}
