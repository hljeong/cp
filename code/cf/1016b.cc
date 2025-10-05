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

tTU> constexpr T max(T a, U b) { return a > b ? a : b; }
tTU> constexpr T min(T a, U b) { return a < b ? a : b; }
tTU> constexpr bool ckmin(T &a, U b) { return b < a ? a = b, 1 : 0; }
tTU> constexpr bool ckmax(T &a, U b) { return a < b ? a = b, 1 : 0; }
tT> constexpr T nth_bit(T x, int n) { return (x >> n) & 1; }
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

  tT> using Map = ar<T, MAX_CHAR + 1>;
};

constexpr Alphabet lowercase{"abcdefghijklmnopqrstuvwxyz"sv};

auto prefix_automaton(str s, const Alphabet &alphabet = lowercase) {
  s += alphabet.delimiter;
  int n = s.size();
  vi pi = prefix(s);
  vc<Alphabet::Map<int>> transition(n, Alphabet::Map<int>{});
  for (int i = 0; i < n; i++) {
    for (char c : alphabet.symbols) {
      if (i && c != s[i]) transition[i][c] = transition[pi[i - 1]][c];
      else transition[i][c] = i + (c == s[i]);
    }
  }
  return transition;
}

void solve() {
  int n = ri(), m = ri(), q = ri();
  str s = rs(), t = rs();
  auto next = prefix_automaton(t);
  vi p(n + 1);
  int cur = 0;
  for (int i = 0; i < n; i++) {
    cur = next[cur][s[i]];
    // cout << i << ": " << s[i] << ", " << cur << endl;
    p[i + 1] = p[i] + (cur == m);
  }
  // cout << p << endl;
  for (int i = 0; i < q; i++) {
    int l = ri() - 1 + m - 1, r = ri();
    ckmin(l, r);
    // cout << l << ", " << r << ", " << p[l] << ", " << p[r] << endl;
    cout << p[r] - p[l] << endl;
  }
}

int main() {
  cin.tie(0)->sync_with_stdio(0);

  int t = 1;
  // int t = ri();
  while (t--) solve();
}

#endif
