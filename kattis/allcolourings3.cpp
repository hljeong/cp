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

template<class T> bool ckmin(T &a, const T &b) { return b < a ? a = b, 1 : 0; }
template<class T> bool ckmax(T &a, const T &b) { return a < b ? a = b, 1 : 0; }

const int mod = 1e9 + 9;

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

using dsu = pair<vi, vi>;

int find(dsu &d, int i) {
  return d.A[i] == i ? i : (d.A[i] = find(d, d.A[i]));
}

bool combine(dsu &d, int i, int j) {
  i = find(d, i); j = find(d, j);
  if (i != j) {
    if (d.B[i] < d.B[j]) swap(i, j);
    d.A[j] = i; d.B[i] += d.B[j];
    return true;
  }
  return false;
}

int main() {
  int n, m, k; cin >> n >> m >> k;
  vc<vi> g(n, vi());
  vc<pii> e(m);
  for (int i = 0; i < m; ++i) {
    int u, v; cin >> u >> v; --u; --v;
    g[u].push_back(v);
    g[v].push_back(u);
    e[i].A = u;
    e[i].B = v;
  }
  vc<mint> ans(m + 1);
  for (int mask = 0; mask < (1 << m); ++mask) {
    vi par(n), sz(n);
    dsu d = {par, sz};
    for (int i = 0; i < n; ++i) {
      d.A[i] = i;
      d.B[i] = 1;
    }
    for (int i = 0; i < m; ++i) {
      if ((mask & (1 << i))) combine(d, e[i].A, e[i].B);
    }
    int id = 0;
    map<int, int> mp;
    for (int i = 0; i < n; ++i) {
      if (mp.find(find(d, i)) == mp.end()) {
        mp[find(d, i)] = id++;
      }
    }
    int pcnt = __builtin_popcount(mask);
    ans[pcnt] += pow(k, id);
  }
  mint fact[m + 1];
  fact[0] = fact[1] = 1;
  for (int i = 2; i <= m; ++i) {
    fact[i] = i * fact[i - 1];
  }
  for (int i = 0; i <= m; ++i) {
    for (int j = i + 1; j <= m; ++j) {
      if ((j - i) & 1) {
        ans[i] -= fact[j] / fact[i] / fact[j - i] * ans[j];
      } else {
        ans[i] += fact[j] / fact[i] / fact[j - i] * ans[j];
      }
    }
  }
  for (int i = 0; i <= m; ++i) cout << ans[i] << " \n"[i == m];
}
