#ifndef TMPL
#define TMPL
#include <bits/stdc++.h>
#define A first
#define B second
#define pb push_back
#define endl '\n'
using namespace std;
template <class T> using vec = vector<T>;
template <class T, int N> using ar = array<T, N>;
using ll = long long; using ld = long double;
using vi = vec<int>; using vll = vec<ll>;
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

template <ranges::range R>
requires (ranges::random_access_range<R> && ranges::sized_range<R> && not_str<R>)
void read(R& range, int n) { for (int i = 0; i < n; i++) cin >> range[i]; }
void read(auto &...vars) { ((cin >> vars), ...); }
#define def(T, vars...) T vars; read(vars)
#define defv(E, var, n) vec<E> var(n); read(var, n)

template <class T> concept torder = totally_ordered<T>;
constexpr auto max(torder auto a, torder auto b) { return a > b ? a : b; }
constexpr auto min(torder auto a, torder auto b) { return a < b ? a : b; }
constexpr bool ckmin(torder auto &a, torder auto b) { return b < a ? a = b, 1 : 0; }
constexpr bool ckmax(torder auto &a, torder auto b) { return b > a ? a = b, 1 : 0; }

constexpr auto nth_bit(integral auto x, int n) { return (x >> n) & 1; }
constexpr auto high_bit_idx(integral auto x) { assert(x); return bit_width(x) - 1; }
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

template <class T, size_t N> struct nvec_t;
template <class T, size_t N> using nvec = nvec_t<T, N>::type;
template <class T, size_t N> struct nvec_t { using type = vec<nvec<T, N - 1>>; };
template <class T> struct nvec_t<T, 0> { using type = T; };

template <class T> T make_nvec(const T &value) { return value; }
template <class T, class... Dims>
auto make_nvec(size_t dim, Dims... dims) {
  using E = decltype(make_nvec<T>(dims...));
  return vec<E>(dim, make_nvec<T>(dims...));
}

constexpr int inf = 1e9 + 7;
constexpr int mod = inf;
constexpr ll infll = 0x3f3f'3f3f'3f3f'3f3fll;

using ui = uint64_t;

// total 16252325 ~= 1.6e7 primes <= 3e8
// => 65009300 bytes
void count() {
  vi div(3e8 + 1);
  int cnt = 0;
  for (int p = 2; p <= 3e8; p++) {
    if (div[p]) continue;
    int q = p;
    cnt++;
    while (q <= 3e8) {
      div[q] = p;
      q += p;
    }
  }
  cout << cnt << endl;
}

constexpr ui N = 3e8;
// sieve[2k] -> 6k + 1
// sieve[2k + 1] -> 6k + 5
bitset<N / 3 + 1> sieve;

// each prime contributes cnt(p) * f(p)
// where cnt(p) = sum(floor(n / p^k))
//
// benq: https://codeforces.com/contest/1017/problem/F
// cnt(n, p) = n ? n / p + cnt(n / p, p) : 0;
// horner's for evaluating f:
//   f(p) = d + p * (c + p * (b + p * a))

void solve() {
  def(ui, n, a, b, c, d);
  ui ret = 0;
  auto f = [&](ui p) { return a * p * p * p + b * p * p + c * p + d; };
  auto apply = [&](ui p) {
    ui pk = p, cnt = 0;
    while (pk <= n) {
      cnt += n / pk;
      pk *= p;
    }
    ret += cnt * f(p);
  };
  {
    ui p = 2, q = 2;
    apply(p);
    while (q <= N) {
      if ((q % 6 == 5) || (q % 6 == 1)) {
        sieve[q / 3] = 1;
      }
      q += p;
    }
  }
  {
    ui p = 3, q = 3;
    apply(p);
    while (q <= N) {
      if ((q % 6 == 5) || (q % 6 == 1)) {
        sieve[q / 3] = 1;
      }
      q += p;
    }
  }
  for (ui p = 5; p <= N; p++) {
    if ((p % 6 != 5) && (p % 6 != 1)) continue;
    if (sieve[p / 3]) continue;
    apply(p);
    ui q = p;
    while (q <= N) {
      if ((q % 6 == 5) || (q % 6 == 1)) {
        sieve[q / 3] = 1;
      }
      q += p;
    }
  }
  cout << uint32_t(ret) << endl;
}

int main() {
  cin.tie(0)->sync_with_stdio(0);

  int t = 1;
  // int t = ri();
  while (t--) solve();
}

#endif
