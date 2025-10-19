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
template <class T, class U> concept mut_torder = totally_ordered_with<T, U>;
#define mut_torder_TU template <class T, class U> requires mut_torder<T, U>
mut_torder_TU fun max(T a, U b) { return a > b ? a : b; }
mut_torder_TU fun min(T a, U b) { return a < b ? a : b; }
mut_torder_TU constexpr bool ckmin(T &a, U b) { return b < a ? a = b, 1 : 0; }
mut_torder_TU constexpr bool ckmax(T &a, U b) { return b > a ? a = b, 1 : 0; }
#undef mut_torder_TU

fun nth_bit(integral auto x, int n) { return (x >> n) & 1; }
fun high_bit_idx(integral auto x) { assert(x); return bit_width(x) - 1; }
fun high_bit(integral auto x) { assert(x); return 1 << high_bit_idx(x); }
fun low_bit(integral auto x) { assert(x); return x & -x; }
fun low_bit_idx(integral auto x) { assert(x); return high_bit_idx(low_bit(x)); }

fun mid(integral auto l, integral auto r) { return l + (r - l) / 2; }

template <torder T> constexpr T minst(T l, T r, predicate<T> auto pred) {
  while (l < r) {
    const T m = mid(l, r);
    if (pred(m)) r = m;
    else l = m + 1;
  }
  return l;
}

template <torder T> constexpr T maxst(T l, T r, predicate<T> auto pred) {
  return minst(l, r + 1, [pred](T x) { return !pred(x); }) - 1;
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

constexpr struct Directed {} directed;

struct Graph : vec<vi> {
  using base = vec<vi>;
  using base::begin;
  using base::end;
  using base::size;
  using base::operator[];

  vec<map<int, ll>> w;

  Graph(int n) : base(n), w(n) {}
  Graph(const Graph &g) = default;
  Graph(int n, int m, int off = 1) : Graph(n) {
    for (int i = 0; i < m; i++) {
      def(int, u, v);
      c(u - off, v - off);
    }
  }
  Graph(Directed, int n, int m, int off = 1) : Graph(n) {
    for (int i = 0; i < m; i++) {
      def(int, u, v);
      cto(u - off, v - off);
    }
  }

  void cto(int from, int to) { self[from].pb(to); }
  void c(int from, int to) { cto(from, to); cto(to, from); }

  Graph transpose() const {
    int n = size();
    Graph g(n);
    for (int u = 0; u < n; u++)
      for (int v : self[u])
        g.cto(v, u);
    return g;
  }
};

constexpr int inf = 1e9 + 7;
constexpr int mod = inf;
constexpr ll infll = 0x3f3f'3f3f'3f3f'3f3fll;

void solve() {
  def(int, n, m);
  Graph g(directed, n, m);

  vi order, vis(n, 0);
  for (int u = 0; u < n; u++) if (!vis[u]) {
    vis[u] = 1;
    order.pb(u);
    for (int v : g[u])
      vis[v] = 1;
  }
  si ret, r1;
  for (int u : order | rv::reverse) if (!r1.count(u)) {
    ret.insert(u + 1);
    for (int v : g[u])
      r1.insert(v);
  }

  cout << ret.size() << endl << ret << endl;
}

int main() {
  cin.tie(0)->sync_with_stdio(0);

  int t = 1;
  // int t = ri();
  while (t--) solve();
}

#endif
