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

using mint = modint<998244353>;

int main() {
  cin.tie(0) -> sync_with_stdio(0);

  int n, k; cin >> n >> k;
  vi a(n); for (int i = 0; i < n; ++i) cin >> a[i];
  mint ret = 1;
  // fs = count for same number on each side
  // fd = count for diff number on each side
  vc<mint> fs(n + 1), fd(n + 1);
  fs[0] = 0;
  fs[1] = k - 1;
  fd[0] = 1;
  fd[1] = k - 2;
  for (int i = 2; i <= n; ++i) {
    fs[i] = (k - 1) * fd[i - 1];
    fd[i] = fs[i - 1] + (k - 2) * fd[i - 1];
  }
  // observation: no two numbers 2 apart from each other can be the same
  // split into odd and even indices
  for (int j = 0; j < 2; ++j) {
    int lst = -1, run = 0;
    for (int i = j; i < n; i += 2) {
      if (a[i] == -1) ++run;
      else {
        if (lst == -1) ret *= pow(mint(k - 1), run);
        else if (a[i] == lst) ret *= fs[run];
        else ret *= fd[run];
        run = 0;
        lst = a[i];
      }
    }
    if (run) {
      if (lst == -1) ret *= k * pow(mint(k - 1), run - 1);
      else ret *= pow(mint(k - 1), run);
    }
  }
  cout << ret << endl;
}
