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
ostream &operator<<(ostream &o, const pair<T, U> &p) { return o << '(' << p.A << ", " << p.B << ')'; }

template <class T, class U>
istream &operator>>(istream &i, pair<T, U> &p) { return i >> p.A >> p.B; }

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

  void cto(int from, int to, ll weight) { (*this)[from].pb(to); w[from][to] += weight; }
  void c(int from, int to, ll weight = 1) { cto(from, to, weight); cto(to, from, weight); }
};

template <class M>
concept monoid =
  requires {
    typename M::T;  // value type
  } &&
  requires(const typename M::T &x, const typename M::T &y) {
    { M::identity() } -> convertible_to<typename M::T>;
    { M::merge(x, y) } -> convertible_to<typename M::T>;
  };

template <class Ops>
concept lazy =
  monoid<Ops> &&
  requires {
    typename Ops::T;  // value type
    typename Ops::U;  // update type
  } &&
  requires(const typename Ops::U &u1, const typename Ops::U &u2,
           const typename Ops::T &x, int len) {
    { Ops::identity_update() } -> convertible_to<typename Ops::U>;
    { Ops::apply(u1, x, len) } -> convertible_to<typename Ops::T>;
    { Ops::compose(u1, u2) } -> convertible_to<typename Ops::U>;
  };

template <lazy Ops>
struct SegmentTree {
  using T = typename Ops::T;
  using U = typename Ops::U;

  int n;
  vec<T> t;
  vec<U> lz;

  SegmentTree(int n = 0) : n(n), t(4 * n, Ops::identity()), lz(4 * n, Ops::identity_update()) {}
  SegmentTree(const vec<T> &a) : SegmentTree(a.size()) { build(a, 1, 0, n - 1); }

  void pull(int u) {
    t[u] = Ops::merge(t[u << 1], t[u << 1 | 1]);
  }

  void push(int u, int l, int r) {
    if (lz[u] == Ops::identity_update()) return;
    t[u] = Ops::apply(lz[u], t[u], r - l + 1);
    if (l != r) {
      lz[u << 1] = Ops::compose(lz[u], lz[u << 1]);
      lz[u << 1 | 1] = Ops::compose(lz[u], lz[u << 1 | 1]);
    }
    lz[u] = Ops::identity_update();
  }

  void build(const vec<T> &a, int u, int l, int r) {
    if (l == r) t[u] = a[l];
    else {
      int m = l + (r - l) / 2;
      build(a, u << 1, l, m);
      build(a, u << 1 | 1, m + 1, r);
      pull(u);
    }
  }

  void update(int i, const U &upd) { update(i, i, upd); }
  void update(int i, int j, const U &upd) { update(i, j, upd, 1, 0, n - 1); }
  void update(int i, int j, const U &upd, int u, int l, int r) {
    push(u, l, r);
    if (j < l || r < i) return;
    if (i <= l && r <= j) { lz[u] = upd; push(u, l, r); }
    else {
      int m = l + (r - l) / 2;
      update(i, j, upd, u << 1, l, m);
      update(i, j, upd, u << 1 | 1, m + 1, r);
      pull(u);
    }
  }

  T query(int i) { return query(i, i); }
  T query(int i, int j) { return query(i, j, 1, 0, n - 1); }
  T query(int i, int j, int u, int l, int r) {
    push(u, l, r);
    if (j < l || r < i) return Ops::identity();
    if (i <= l && r <= j) return t[u];
    int m = l + (r - l) / 2;
    return Ops::merge(query(i, j, u << 1, l, m),
                      query(i, j, u << 1 | 1, m + 1, r));
  }
};

template <lazy Ops>
struct HeavyLightDecomposition {
  using T = Ops::T;
  using U = Ops::U;

  int n, p = 0;
  vi par, dep, sz, head, pos, end, heavy;
  SegmentTree<Ops> t;

  HeavyLightDecomposition(const Graph &g, const vec<T> &a, int r = 0)
    : n(g.size()), par(n), dep(n), sz(n), head(n), pos(n), end(n), heavy(n, -1) {
    assert(a.size() == n);
    par[r] = r;
    dfs(g, r);
    decompose(g, r, r);

    vector<T> ap(n);
    for (int i = 0; i < n; i++) ap[pos[i]] = a[i];
    t = SegmentTree<Ops>(ap);
  }

  HeavyLightDecomposition(const Graph &g, int r = 0)
    : HeavyLightDecomposition(g, vec<T>(g.size(), Ops::identity()), r) {}

  void update(int u, const U &upd) { t.update(pos[u], upd); }

  void update(int u, int v, const U &upd) {
    while (head[u] != head[v]) {
      if (dep[head[u]] > dep[head[v]]) swap(u, v);
      t.update(pos[head[v]], pos[v], upd);
      v = par[head[v]];
    }
    if (dep[u] > dep[v]) swap(u, v);
    t.update(pos[u], pos[v], upd);
  }

  void update_subtree(int u, const U &upd) { t.update(pos[u], end[u] - 1, upd); }

  T query(int u) { return t.query(pos[u]); }

  T query(int u, int v) {
    T ret = Ops::identity();
    while (head[u] != head[v]) {
      if (dep[head[u]] > dep[head[v]]) swap(u, v);
      ret = Ops::merge(t.query(pos[head[v]], pos[v]), ret);
      v = par[head[v]];
    }
    if (dep[u] > dep[v]) swap(u, v);
    return Ops::merge(t.query(pos[u], pos[v]), ret);
  }

  T query_subtree(int u) { return t.query(pos[u], end[u] - 1); }

  void dfs(const Graph &g, int u) {
    sz[u] = 1;
    int mx = 0;
    for (int v : g[u]) {
      if (v == par[u]) continue;
      par[v] = u;
      dep[v] = dep[u] + 1;
      dfs(g, v);
      sz[u] += sz[v];
      if (ckmax(mx, sz[v])) heavy[u] = v;
    }
  }

  void decompose(const Graph &g, int u, int h) {
    head[u] = h;
    pos[u] = p++;
    if (~heavy[u]) decompose(g, heavy[u], h);
    for (int v : g[u]) {
      if (v == par[u] || v == heavy[u]) continue;
      decompose(g, v, v);
    }
    end[u] = p;
  }
};

struct Ops {
  struct T {
    int suffix_max = -inf;
    int sum = 0;
  };
  struct U {
    bool tag = false;  // !tag -> add, tag -> assign
    int value = 0;  // always >= 0
    constexpr auto operator<=>(const U &) const = default;
  };
  static constexpr T identity()                             { return {}; }
  static constexpr U identity_update()                      { return {}; }

  static constexpr T merge(const T &x, const T &y) {
    return {
      .suffix_max = max(x.suffix_max + y.sum, y.suffix_max),
      .sum = x.sum + y.sum,
    };
  }

  static constexpr T apply(const U &u, const T &x, int len) {
    if (len > 1) {
      // cout << u.tag << ", " << u.value << ", " << len << endl << flush;
      // no range adds, only range sets
      assert(u == identity_update() || u.tag);
      return T{ .suffix_max = max(u.value, u.value * len), .sum = u.value * len };
    } else {
      return u.tag ? T{u.value, u.value} : T{x.suffix_max + u.value, x.sum + u.value};
    }
  }

  static constexpr U compose(const U &u1, const U &u2) {
    if (u1.tag) return u1;
    if (u2.tag) return {true, u2.value + u1.value};
    return {false, u1.value + u2.value};
  }
};

// https://codeforces.com/blog/entry/61081?#comment-450149
// hld (+ subtree updates): set all nodes to -1, per-query type:
// 1. add 1 to node
// 2. set all nodes in subtree to -1, add -query(v) - 1 to v
//    (make query(v) == -1 after this query)
// 3. check query(0, v) >= 0
//
// hld needs: range assign, range add, max suffix sum query (root to node)

void solve() {
  def(int, n, q);
  Graph g(n);
  for (int u = 1; u < n; u++) {
    def(int, v); v--;
    g.c(u, v);
  }

  HeavyLightDecomposition<Ops> hld(g, vec<Ops::T>(n, {-1, -1}));
  while (q--) {
    def(int, t, v); v--;
    // cout << t << ", " << v << endl;
    if (t == 1) {
      hld.update(v, {false, 1});
    } else if (t == 2) {
      hld.update_subtree(v, {true, -1});
      if (int value = hld.query(0, v).suffix_max; value >= 0) {
        hld.update(v, {false, -value - 1});
      }
    } else {
      cout << ((hld.query(0, v).suffix_max >= 0) ? "black" : "white") << endl;
    }
    // for (int u = 0; u < n; u++) {
    //   cout << "(" << hld.query(u).sum << ", " <<
    //                  hld.query(0, u).sum << ", " <<
    //                  hld.query(0, u).suffix_max << ")" << " \n"[u == n - 1];
    // }
  }
}

int main() {
  cin.tie(0)->sync_with_stdio(0);

  int t = 1;
  // int t = ri();
  while (t--) solve();
}

#endif
