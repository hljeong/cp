#ifndef TMPL
#define TMPL
#include <bits/stdc++.h>
#define A first
#define B second
#define pb push_back
#define endl '\n'
using namespace std;
template <class T> using vc = vector<T>;
template <class T, int N> using ar = array<T, N>;
using ll = long long; using ld = long double;
using vi = vc<int>; using vll = vc<ll>;
using si = set<int>; using sll = set<ll>;
using pi = pair<int, int>; using pll = pair<ll, ll>;
using qi = queue<int>;
using mii = map<int, int>;
using str = string;

template <class T>
concept not_str = !(same_as<remove_cvref_t<T>, str> ||
                    same_as<remove_cvref_t<T>, string_view> ||
                    convertible_to<T, const char *>);

template <ranges::range R> requires not_str<R>
ostream &operator<<(ostream &os, const R& range) {
  auto it = ranges::begin(range); auto end = ranges::end(range);
  for (bool first = 1; it != end; it++) {
    if (!first) os << ' ';
    first = 0;
    os << *it;
  }
  return os;
}

template <class T, class U>
istream& operator>>(istream &i, pair<T, U> &p) { return i >> p.A >> p.B; }

template <class T> T rd() { T x; cin >> x; return x; }
int ri() { return rd<int>(); }
ll rll() { return rd<ll>(); }
str rs() { return rd<str>(); }

template <class T> concept torder = totally_ordered<T>;
constexpr auto max(torder auto a, torder auto b) { return a > b ? a : b; }
constexpr auto min(torder auto a, torder auto b) { return a < b ? a : b; }
constexpr bool ckmin(torder auto &a, torder auto b) { return b < a ? a = b, 1 : 0; }
constexpr bool ckmax(torder auto &a, torder auto b) { return b > a ? a = b, 1 : 0; }

constexpr auto nth_bit(integral auto x, int n) { return (x >> n) & 1; }
constexpr auto high_bit_idx(integral auto x) { assert(x); return 31 - __builtin_clz(x); }
constexpr auto high_bit(integral auto x) { assert(x); return 1 << high_bit_idx(x); }
constexpr auto low_bit(integral auto x) { assert(x); return x & -x; }
constexpr auto low_bit_idx(integral auto x) { assert(x); return high_bit_idx(low_bit(x)); }

constexpr auto minst(torder auto l, decltype(l) r, predicate<decltype(l)> auto pred) {
  while (l < r) {
    const decltype(l) m = l + (r - l) / 2;
    if (pred(m)) r = m;
    else l = m + 1;
  }
  return l;
}

constexpr auto maxst(torder auto l, decltype(l) r, predicate<decltype(l)> auto pred) {
  return minst(l, r + 1, [pred](decltype(l) x) { return !pred(x); }) - 1;
}

constexpr int inf = 1e9 + 7;
constexpr int mod = inf;
constexpr ll infll = 0x3f3f'3f3f'3f3f'3f3fll;

template <ranges::range R>
requires (ranges::random_access_range<R> && ranges::sized_range<R> && not_str<R>)
void read(R& range, int n) { for (int i = 0; i < n; i++) cin >> range[i]; }
void read(auto &...vars) { ((cin >> vars), ...); }
#define def(T, vars...) T vars; read(vars)
#define defv(E, var, n) vc<E> var(n); read(var, n)

template <class T, size_t N> struct nvec_t;
template <class T, size_t N> using nvec = nvec_t<T, N>::type;
template <class T, size_t N> struct nvec_t { using type = vc<nvec<T, N - 1>>; };
template <class T> struct nvec_t<T, 0> { using type = T; };

template <class T> T make_nvec(const T &value) { return value; }
template <class T, class... Dims>
auto make_nvec(size_t dim, Dims... dims) {
  using E = decltype(make_nvec<T>(dims...));
  return vc<E>(dim, make_nvec<T>(dims...));
}

// the editorial is fucking ragebait

void solve() {
  def(int, n, m, q);
  vi w(12); read(w, n); reverse(w.begin(), w.begin() + n);
  vi f(1 << 12);
  for (int mask = 1; mask < (1 << 12); mask++) {
    f[mask] = f[mask ^ low_bit(mask)] + w[low_bit_idx(mask)];
    ckmin(f[mask], 101);
  }

  vi cnt(1 << 12);
  for (int i = 0; i < m; i++) {
    int s = 0;
    for (char c : rs()) s = (s << 1) | (c - '0');
    cnt[s]++;
  }

  auto g = make_nvec<ll>(1 << 12, 102, 0ll);
  for (int i = 0; i < (1 << 12); i++) {
    for (int j = 0; j < (1 << 12); j++) {
      g[i][f[i ^ j ^ ((1 << 12) - 1)]] += cnt[j];
    }
  }

  while (q--) {
    int t = 0;
    for (char c : rs()) t = (t << 1) | (c - '0');
    int k = ri(), ret = 0;
    for (int i = 0; i <= k; i++) ret += g[t][i];
    cout << ret << endl;
  }
}

int main() {
  cin.tie(0)->sync_with_stdio(0);

  int t = 1;
  // int t = ri();
  while (t--) solve();
}

#endif
