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

using mint = modint<mod>;
using nint = modint<998244353>;

vc<vc<mint>> mula(vc<vc<mint>>& a, vc<vc<mint>>& b) {
  int n = a.size();
  vc<vc<mint>> ret(n, vc<mint>(n));
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      for (int k = 0; k < n; ++k) {
        ret[i][j] += a[i][k] * b[k][j];
      }
    }
  }
  return ret;
}

vc<vc<nint>> mulb(vc<vc<nint>>& a, vc<vc<nint>>& b) {
  int n = a.size();
  vc<vc<nint>> ret(n, vc<nint>(n));
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      for (int k = 0; k < n; ++k) {
        ret[i][j] += a[i][k] * b[k][j];
      }
    }
  }
  return ret;
}

vc<vc<mint>> expa(vc<vc<mint>> b, ll e) {
  int n = b.size();
  vc<vc<mint>> ret(n, vc<mint>(n));
  for (int i = 0; i < n; ++i) ret[i][i] = 1;
  while (e) {
    if (e & 1) {
      ret = mula(ret, b);
    }
    b = mula(b, b);
    e >>= 1;
  }
  return ret;
}

vc<vc<nint>> expb(vc<vc<nint>> b, ll e) {
  int n = b.size();
  vc<vc<nint>> ret(n, vc<nint>(n));
  for (int i = 0; i < n; ++i) ret[i][i] = 1;
  while (e) {
    if (e & 1) {
      ret = mulb(ret, b);
    }
    b = mulb(b, b);
    e >>= 1;
  }
  return ret;
}

// directly compute probability
// double modint to ensure precision
int main() {
  cin.tie(0) -> sync_with_stdio(0);

  int n, l; cin >> n >> l;
  vc<vi> a(n, vi(n));
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      cin >> a[i][j];
    }
  }
  vc<vc<mint>> pa(n, vc<mint>(n));
  vc<vc<nint>> pbb(n, vc<nint>(n));
  for (int i = 0; i < n - 1; ++i) {
    mint sa = 0;
    nint sb = 0;
    for (int j = 0; j < n; ++j) {
      sa += a[i][j];
      sb += a[i][j];
    }
    if (sa == 0) continue;
    for (int j = 0; j < n; ++j) {
      pa[i][j] = a[i][j] / sa;
      pbb[i][j] = a[i][j] / sb;
    }
  }
  pa[n - 1][n - 1] = 1;
  pbb[n - 1][n - 1] = 1;
  mint tgta = mint(95) / mint(100);
  nint tgtb = nint(95) / nint(100);
  auto ppa = expa(pa, l);
  auto ppb = expb(pbb, l);
  for (int i = 0; i < 10; ++i) {
    if (ppa[0][n - 1] == tgta && ppb[0][n - 1] == tgtb) {
      cout << (l + i) << endl;
      return 0;
    } else {
      ppa = mula(ppa, pa);
      ppb = mulb(ppb, pbb);
    }
  }
  cout << -1 << endl;
}
