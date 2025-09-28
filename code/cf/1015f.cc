#ifndef TMPL
#define TMPL
#include <bits/stdc++.h>
#define A first
#define B second
#define pb push_back
#define endl '\n'
#define tT template <typename T
#define tTU tT, class U
using namespace std;
tT> using vc = vector<T>;
tT, int N> using ar = array<T, N>;
using ll = long long; using ld = long double;
using vi = vc<int>; using vll = vc<ll>;
using si = set<int>; using sll = set<ll>;
using pi = pair<int, int>; using pll = pair<ll, ll>;
using qi = queue<int>;
using mii = map<int, int>;
using str = string;

tT> ostream &operator<<(ostream &os, const vc<T> &a) {
  for (int i = 0, n = a.size(); i < n; i++) os << (i ? " " : "") << a[i];
  return os;
}

tT, size_t N> ostream &operator<<(ostream &os, const ar<T, N> &a) {
  for (int i = 0; i < N; i++) os << (i ? " " : "") << a[i];
  return os;
}

tT> T rd() { T x; cin >> x; return x; }

tT> vc<T> rda(int n) {
  vc<T> v(n);
  for (int i = 0; i < n; i++) cin >> v[i];
  return v;
}

int ri() { return rd<int>(); }
ll rll() { return rd<ll>(); }
str rs() { return rd<str>(); }
vi ria(int n) { return rda<int>(n); }
vll rlla(int n) { return rda<ll>(n); }

tTU> T max(T a, U b) { return a > b ? a : b; }
tTU> T min(T a, U b) { return a < b ? a : b; }
tTU> bool ckmin(T &a, U b) { return b < a ? a = b, 1 : 0; }
tTU> bool ckmax(T &a, U b) { return a < b ? a = b, 1 : 0; }
tT> T nth_bit(T x, int n) { return (x >> n) & 1; }
tTU> T minst(T l, T r, U pred) {
  T ans = r + 1;
  while (l <= r) {
    T m = l + (r - l) / 2;
    if (pred(m)) r = (ans = m) - 1;
    else l = m + 1;
  }
  return ans;
}
tTU> T maxst(T l, T r, U pred) {
  T ans = l - 1;
  while (l <= r) {
    T m = l + (r - l) / 2;
    if (pred(m)) l = (ans = m) + 1;
    else r = m - 1;
  }
  return ans;
}

constexpr int inf = 1e9 + 7;
constexpr int mod = inf;
constexpr ll infll = 0x3f3f'3f3f'3f3f'3f3fll;

template <int M> struct modint {
  int v;

  explicit operator int() const { return v; }
  modint() : v(0) {}
  modint(ll x) : v((-M <= x && x < M) ? x : x % M) { if (v < 0) v += M; }
  bool operator==(modint o) const { return v == o.v; }
  bool operator!=(modint o) const { return v != o.v; }
  bool operator<(modint o) const { return v <= o.v; }
  modint &operator+=(modint o) { if ((v += o.v) >= M) v -= M; return *this; }
  modint &operator-=(modint o) { if ((v -= o.v) < 0) v += M; return *this; }
  modint &operator*=(modint o) { v = int(ll(v) * o.v % M); return *this; }
  modint &operator/=(modint o) { return (*this) *= inv(o); }
  modint inv(const modint &x) { assert(x.v != 0); return pow(x, M - 2); }
  friend modint pow(modint b, ll e) { return e < 0 ? qpow(b.inv(), -e) : qpow(b, e); }

  modint operator-() const { return modint(-v); }
  modint &operator++() { return *this += 1; }
  modint &operator--() { return *this -= 1; }
  friend modint operator+(modint a, modint b) { a += b; return a; }
  friend modint operator-(modint a, modint b) { a -= b; return a; }
  friend modint operator*(modint a, modint b) { a *= b; return a; }
  friend modint operator/(modint a, modint b) { a /= b; return a; }
  friend ostream &operator<<(ostream &os, modint x) { return os << int(x); }
  friend istream &operator>>(istream &os, modint x) { return os >> x.v; }
};

using mint = modint<inf>;

vi prefix(const str &s) {
  int n = s.size();
  vi pi(n);
  for (int i = 1; i < n; i++) {
    int j = pi[i - 1];
    while (j > 0 && s[i] != s[j]) j = pi[j - 1];
    pi[i] = j + (s[i] == s[j]);
  }
  return pi;
}

struct Alphabet {
  static constexpr int MAX_CHAR = numeric_limits<char>::max();
  const string_view symbols;
  const char delimiter;
  const int size;
  const ar<int, MAX_CHAR> idx;
  static constexpr auto build_idx(string_view symbols) { 
    ar<int, MAX_CHAR> idx{};
    for (int i = 0; i < symbols.size(); i++) idx[symbols[i]] = i;
     return idx;
  }
  constexpr Alphabet(string_view symbols) :
    symbols{symbols},
    delimiter(ranges::max(symbols) + 1),
    size(symbols.size()),
    idx(build_idx(symbols)) {}
  constexpr char operator[](int idx) const { return symbols[idx]; };
  constexpr int operator[](char c) const { return idx[c]; };
};

constexpr Alphabet lowercase{"abcdefghijklmnopqrstuvwxyz"sv};

vc<vi> prefix_automaton(str s, const Alphabet &alphabet = lowercase) {
  s += alphabet.delimiter;
  int n = s.size();
  vi pi = prefix(s);
  vc<vi> transition(n, vi(alphabet.size));
  for (int i = 0; i < n; i++) {
    for (int c = 0; c < alphabet.size; c++) {
      if (i && alphabet[c] != s[i]) transition[i][c] = transition[pi[i - 1]][c];
      else transition[i][c] = i + (alphabet[c] == s[i]);
    }
  }
  return transition;
}


// dp[i][j][k] = # of partial bracket sequences with:
// - length i
// - balance j
// - prefix match of length k with s

void solve() {
  int n = ri(); auto s = rs(); int m = s.size();
  vc<vc<vc<mint>>> dp(2 * n + 1, vc<vc<mint>>(n + 1, vc<mint>(m + 1)));
  vc<vc<mint>> cnt(2 * n + 1, vc<mint>(n + 1));
  dp[0][0][0] = cnt[0][0] = 1;
  Alphabet S{"()"sv};
  auto next = prefix_automaton(s, S);
  // for (auto a : next) cout << a << endl;
  vc<map<char, int>> nxt(m);
  for (int i = 0; i < 2 * n; i++) {
    for (int j = 0; j <= n; j++) {
      if (j) cnt[i + 1][j - 1] += cnt[i][j];
      if (j < n) cnt[i + 1][j + 1] += cnt[i][j];
      for (int k = 0; k < m; k++) {
        if (j) dp[i + 1][j - 1][next[k][S[')']]] += dp[i][j][k];
        if (j < n) dp[i + 1][j + 1][next[k][S['(']]] += dp[i][j][k];
      }
    }
  }
  mint complement = 0;
  for (int i = 0; i < m; i++) complement += dp[2 * n][0][i];
  cout << cnt[2 * n][0] - complement << endl;
}

int main() {
  cin.tie(0)->sync_with_stdio(0);

  int t = 1;
  // int t = ri();
  while (t--) solve();
}

#endif
