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
template <class T> using pq = priority_queue<T>;
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

constexpr auto mid(integral auto l, integral auto r) { return l + (r - l) / 2; }

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

// define f(i) = a[i + n / 2] - a[i]
// we are to find i s.t. f(i) == 0
// note that if n / 2 is odd then f(i) is always odd -> no solution
// note that f(i) = -f(i + n / 2) and
// abs(f(i + 1) - f(i)) in {-2, 0, 2}
// so there must exist i in [0, n / 2) s.t. f(i) = 0

void solve() {
  def(int, n);
  if ((n / 2) & 1) {
    cout << "! -1" << endl;
    return;
  }

  auto f = [n](int i) {
    cout << "? " << (i + 1) << endl << flush;
    def(int, l);
    cout << "? " << (i + n / 2 + 1) << endl << flush;
    return ri() - l;
  };

  int l = 0, r = n / 2, fl = f(l), fr = -fl;
  while (true) {
    int m = mid(l, r), fm = f(m);
    if (fm == 0) {
      cout << "! " << (m + 1) << endl;
      return;
    }
    // set bounds s.t. f(l) and f(r) have opposite signs
    if (ll(fl) * fm < 0) r = m;
    else l = m;
  }
}

int main() {
  cin.tie(0)->sync_with_stdio(0);

  int t = 1;
  // int t = ri();
  while (t--) solve();
}

#endif
