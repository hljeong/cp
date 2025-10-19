#ifndef TMPL
#define TMPL
#include <bits/stdc++.h>
#define A first
#define B second
#define pb push_back
#define fun constexpr auto
#define endl '\n'
#define self (*this)
using namespace std;
namespace r = ranges;
namespace rv = r::views;
template <class T> using vec = vector<T>;
template <class T, size_t N> using ar = array<T, N>;
template <class ...Ts> using tup = tuple<Ts...>;
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
ostream &operator<<(ostream &o, const R& range) {
  bool first = true;
  for (auto &value : range) {
    if (!first) o << ' ';
    first = false;
    o << value;
  }
  return o;
}

template <class T, class U> ostream& operator<<(ostream &o, const pair<T, U> &p) { return o << '(' << p.A << ' ' << p.B << ')'; }
template <class T, class U> istream& operator>>(istream &i, pair<T, U> &p) { return i >> p.A >> p.B; }

template <class T> T rd() { T x; cin >> x; return x; }
int ri() { return rd<int>(); }
ll rll() { return rd<ll>(); }
str rs() { return rd<str>(); }

template <r::range R>
requires (r::random_access_range<R> && r::sized_range<R> && not_str<R>)
void read(R& range, int n) { for (int i = 0; i < n; i++) cin >> range[i]; }
void read(auto &...vars) { ((cin >> vars), ...); }
#define def(T, vars...) T vars; read(vars)
#define defv(E, var, n) vec<E> var(n); read(var, n)

template <class T> concept torder = totally_ordered<T>;
template <class T, class U> concept mut_torder = totally_ordered_with<T, U>;
#define mut_torder_TU template <class T, class U> requires mut_torder<T, U>
mut_torder_TU fun max(T a, U b) { return a > b ? a : b; }
mut_torder_TU fun min(T a, U b) { return a < b ? a : b; }
mut_torder_TU constexpr bool ckmin(T &a, U b) { return b < a ? a = b, 1 : 0; }
mut_torder_TU constexpr bool ckmax(T &a, U b) { return b > a ? a = b, 1 : 0; }
#undef mut_torder_TU

fun nth_bit(integral auto x, int n) { return (x >> n) & 1; }
fun high_bit_idx(int x) { return 31 - __builtin_clz(x); }
fun high_bit_idx(ll x) { return 63 - __builtin_clz(x); }
fun high_bit(integral auto x) { return x ? (1 << high_bit_idx(x)) : -1; }
fun low_bit(integral auto x) { return x & -x; }
fun low_bit_idx(integral auto x) { return high_bit_idx(low_bit(x)); }
fun is_pow2(integral auto x) { return x && (x == low_bit(x)); }

fun mid(integral auto l, integral auto r) { return l + (r - l) / 2; }

template <torder T> constexpr T minst(T l, T r, predicate<T> auto pred) {
  T ret = r + 1;
  while (l <= r) {
    const T m = mid(l, r);
    if (pred(m)) r = (ret = m) - 1;
    else l = m + 1;
  }
  return ret;
}

template <torder T> constexpr T maxst(T l, T r, predicate<T> auto pred) {
  T ret = l - 1;
  while (l <= r) {
    const T m = mid(l, r);
    if (pred(m)) l = (ret = m) + 1;
    else r = m - 1;
  }
  return ret;
}

template <class T, size_t N> struct nvec_t;
template <class T, size_t N> using nvec = nvec_t<T, N>::type;
template <class T, size_t N> struct nvec_t { using type = vec<nvec<T, N - 1>>; };
template <class T> struct nvec_t<T, 0> { using type = T; };

template <class T> T make_nvec(const T &value) { return value; }
template <class T, class... Dims>
auto make_nvec(size_t dim, Dims... dims) { using E = decltype(make_nvec<T>(dims...)); return vec<E>(dim, make_nvec<T>(dims...)); }

template <integral T, integral U> fun range(T start, U end) { using V = common_type_t<T, U>; return rv::iota((V) start, (V) end); }
template <integral T> fun range(T end) { return range(T(0), end); }
template <r::range R> auto sliced(R &&r, size_t start, size_t end) { return std::forward<R>(r) | rv::drop(start) | rv::take(end - start); }
template <r::range R> auto sliced(R &&r, size_t start) { return std::forward<R>(r) | rv::drop(start); }

constexpr int inf = 1e9 + 7;
constexpr int mod = inf;
constexpr ll infll = 0x3f3f'3f3f'3f3f'3f3fll;

// ragebait contest https://codeforces.com/blog/entry/147524
// editorial solution

void solve() {
  def(int, n, k);
  defv(int, a, n);
  si s;
  for (int ai : a) s.insert(ai);
  if (s.size() == n) {
    vi ret;
    for (int i : range(k)) ret.pb(a[i % 3]);
    cout << ret << endl;
    return;
  }
  int x = 1; while (s.count(x)) x++;
  int z = a.back();
  int y = 1; while (y == x || y == z) y++;
  ar<int, 3> b = {x, y, z};
  vi ret;
  for (int i : range(k)) ret.pb(b[i % 3]);
  cout << ret << endl;
}

int main() {
  cin.tie(0)->sync_with_stdio(0);

  // int t = 1;
  int t = ri();
  while (t--) solve();
}

#endif
