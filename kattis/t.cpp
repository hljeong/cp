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
template<class T> bool ckmax(T &a, const T &b) { return a < b ? a = b, 1 : 0; }

const int inf = 1e9 + 7;
const int mod = inf;
const ll infll = 0x3f3f3f3f3f3f3f3fll;

struct mint {
  int v;
  explicit operator int() const { return v; }

  mint() : v(0) {}
  mint(ll _v) { 
    v = int((-mod <= _v && _v < mod) ? _v : _v % mod);
    if (v < 0) v += mod;
  }

  bool operator==(const mint& o) const {return v == o.v;}
  friend bool operator!=(const mint& a, const mint& b) {return !(a == b);}
  friend bool operator<(const mint& a, const mint& b) {return a.v < b.v;}
   
  mint& operator+=(const mint& o) {if ((v += o.v) >= mod) v -= mod; return *this;}
  mint& operator-=(const mint& o) {if ((v -= o.v) < 0) v += mod; return *this;}
  mint& operator*=(const mint& o) {v = int((ll)v * o.v % mod); return *this;}
  mint& operator/=(const mint& o) {return (*this) *= inv(o);}

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
    
  mint operator-() const {return mint(-v);}
  mint& operator++() {return *this += 1;}
  mint& operator--() {return *this -= 1;}
  friend mint operator+(mint a, const mint& b) {return a += b;}
  friend mint operator-(mint a, const mint& b) {return a -= b;}
  friend mint operator*(mint a, const mint& b) {return a *= b;}
  friend mint operator/(mint a, const mint& b) {return a /= b;}

  friend ostream& operator<<(ostream& stream, const mint& x) {stream << int(x); return stream;}
  friend istream& operator>>(istream& stream, mint& x) {stream >> x.v; return stream;}
};

int main() {
  int n; cin >> n;
  string s; cin >> s;
  vc<mint> dp(2);
  dp[1] = 1;
  for (int i = 0; i < n - 1; ++i) {
    vc<mint> ndp(2 + i);
    if (s[i] == '<') {
      for (int j = 1; j <= i + 1 ; ++j) {
        ndp[j] = dp[j];
      }
    } else {
      for (int j = 0; j <= i; ++j) {
        ndp[j] = dp[i + 1] - dp[j];
      }
    }
    dp = vc<mint>(3 + i);
    for (int j = 0; j < i + 2; ++j) {
      dp[j + 1] = dp[j] + ndp[j];
    }
  }
  cout << dp[n] << endl;
}
