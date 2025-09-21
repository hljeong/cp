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
using gr = vc<vi>; using wgr = vc<vc<pii>>;

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

void get(int i, ll cur, vc<pii> &pv, sll &d) {
  if (i == pv.size()) {
    d.insert(cur);
    return;
  }
  ll ppd = 1;
  for (int j = 0; j <= pv[i].B; ++j) {
    get(i + 1, cur * ppd, pv, d);
    ppd *= pv[i].A;
  }
}

int main() {
  ll a, c; cin >> a >> c;
  vi d(1000005);
  si p;
  for (int i = 2; i <= 1000000; ++i) {
    if (!d[i]) {
      d[i] = i;
      p.insert(i);
      if ((ll) i * i <= 1000000) {
        int j = i * i;
        while (j <= 1000000) {
          d[j] = i;
          j += i;
        }
      }
    }
  }
  ll ca = a, cc = c;
  mii pf;
  for (int pr : p) {
    while (!(ca % pr)) {
      ca /= pr;
      ++pf[pr];
    }
  }
  for (int pr : p) {
    while (!(cc % pr)) {
      cc /= pr;
      ++pf[pr];
    }
  }
  /*
  mii pa, pc;
  for (int pr : p) {
    while (!(ca % pr)) {
      ca /= pr;
      ++pa[pr];
    }
  }
  for (int pr : p) {
    while (!(cc % pr)) {
      cc /= pr;
      ++pc[pr];
    }
  }
  vc<pii> pav, pcv;
  for (const auto &e : pa) {
    pav.push_back(e);
  }
  for (const auto &e : pc) {
    pcv.push_back(e);
  }
  sll da, dc;
  get(0, 1, pav, da);
  get(0, 1, pcv, dc);
  unordered_set<int> good;
  for (ll x : da) {
    for (ll y : dc) {
      mint u(x), v(y), uv = u * v;
      good.insert(int(uv));
    }
  }
  cout << good.size() << endl;
  */
  ll ret = 1;
  bool god_fkin_damn_it = false;
  for (const auto &e : pf) {
    ret *= e.B + 1;
    if (e.B & 1) god_fkin_damn_it = true;
  }
  if (!god_fkin_damn_it) ++ret;
  cout << ret << endl;
}
