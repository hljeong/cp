#include "../misc/tmpl.cc"

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

template <class Value = ll>
struct Sum_Update_Sum_Query {
  using T = Value;
  using U = Value;
  static constexpr T identity()                             { return 0; }
  static constexpr U identity_update()                      { return 0; }
  static constexpr T merge(const T &x, const T &y)          { return x + y; }
  static constexpr T apply(const U &u, const T &x, int len) { return x + u * len; }
  static constexpr U compose(const U &u1, const U &u2)      { return u1 + u2; }
};

template <class Value = ll>
struct Sum_Update_Min_Query {
  using T = Value;
  using U = Value;
  static constexpr T identity()                             { return numeric_limits<T>::max(); }
  static constexpr U identity_update()                      { return 0; }
  static constexpr T merge(const T &x, const T &y)          { return min(x, y); }
  static constexpr T apply(const U &u, const T &x, int len) { return x + u; }
  static constexpr U compose(const U &u1, const U &u2)      { return u1 + u2; }
};

template <class Value = ll>
struct Sum_Update_Max_Query {
  using T = Value;
  using U = Value;
  static constexpr T identity()                             { return numeric_limits<T>::min(); }
  static constexpr U identity_update()                      { return 0; }
  static constexpr T merge(const T &x, const T &y)          { return max(x, y); }
  static constexpr T apply(const U &u, const T &x, int len) { return x + u; }
  static constexpr U compose(const U &u1, const U &u2)      { return u1 + u2; }
};

template <class Value = ll>
struct Assign_Update_Sum_Query {
  using T = Value;
  using U = optional<Value>;
  static constexpr T identity()                             { return 0; }
  static constexpr U identity_update()                      { return nullopt; }
  static constexpr T merge(const T &x, const T &y)          { return x + y; }
  static constexpr T apply(const U &u, const T &x, int len) { return u ? (*u) * len : x; }
  static constexpr U compose(const U &u1, const U &u2)      { return u1 ? u1 : u2; }
};

template <class Value = ll>
struct Affine_Update_Sum_Query {
  using T = Value;
  struct U { Value a, b; };  // f(x) = a * x + b
  static constexpr T identity()                             { return 0; }
  static constexpr U identity_update()                      { return {1, 0}; }
  static constexpr T merge(const T &x, const T &y)          { return x + y; }
  static constexpr T apply(const U &u, const T &x, int len) { return u.a * x + u.b * len; }
  static constexpr U composee(const U &u1, const U &u2)     { return {u1.a * u2.a, u1.a * u2.b + u2.b}; }
};

template <class Value = ll>
struct Assign_Update_Min_Query {
  using T = Value;
  using U = optional<Value>;
  static constexpr T identity()                             { return numeric_limits<T>::max(); }
  static constexpr U identity_update()                      { return nullopt; }
  static constexpr T merge(const T &x, const T &y)          { return min(x, y); }
  static constexpr T apply(const U &u, const T &x, int len) { return u ? *u : x; }
  static constexpr U compose(const U &u1, const U &u2)      { return u1 ? u1 : u2; }
};

template <class Value = ll>
struct Assign_Update_Max_Query {
  using T = Value;
  using U = optional<Value>;
  static constexpr T identity()                             { return numeric_limits<T>::min(); }
  static constexpr U identity_update()                      { return nullopt; }
  static constexpr T merge(const T &x, const T &y)          { return max(x, y); }
  static constexpr T apply(const U &u, const T &x, int len) { return u ? *u : x; }
  static constexpr U compose(const U &u1, const U &u2)      { return u1 ? u1 : u2; }
};

template <class Value = ll>
struct Min_Update_Min_Query {
  using T = Value;
  using U = Value;
  static constexpr T identity()                             { return numeric_limits<T>::max(); }
  static constexpr U identity_update()                      { return 0; }
  static constexpr T merge(const T &x, const T &y)          { return min(x, y); }
  static constexpr T apply(const U &u, const T &x, int len) { return min(x, u); }
  static constexpr U compose(const U &u1, const U &u2)      { return min(u1, u2); }
};

template <class Value = ll>
struct Max_Update_Max_Query {
  using T = Value;
  using U = Value;
  static constexpr T identity()                             { return numeric_limits<T>::min(); }
  static constexpr U identity_update()                      { return 0; }
  static constexpr T merge(const T &x, const T &y)          { return max(x, y); }
  static constexpr T apply(const U &u, const T &x, int len) { return max(x, u); }
  static constexpr U compose(const U &u1, const U &u2)      { return max(u1, u2); }
};

template <class Value = ll>
struct Min_Update_Max_Query {
  using T = Value;
  using U = Value;
  static constexpr T identity()                             { return numeric_limits<T>::min(); }
  static constexpr U identity_update()                      { return numeric_limits<U>::max(); }
  static constexpr T merge(const T &x, const T &y)          { return max(x, y); }
  static constexpr T apply(const U &u, const T &x, int len) { return min(x, u); }
  static constexpr U compose(const U &u1, const U &u2)      { return min(u1, u2); }
};

template <class Value = ll>
struct Max_Update_Min_Query {
  using T = Value;
  using U = Value;
  static constexpr T identity()                             { return numeric_limits<T>::max(); }
  static constexpr U identity_update()                      { return numeric_limits<U>::min(); }
  static constexpr T merge(const T &x, const T &y)          { return min(x, y); }
  static constexpr T apply(const U &u, const T &x, int len) { return max(x, u); }
  static constexpr U compose(const U &u1, const U &u2)      { return max(u1, u2); }
};

template <monoid M>
struct Simple {
  using T = M::T;
  using U = T;
  static constexpr T identity()                             { return M::identity(); }
  static constexpr U identity_update()                      { return M::identity_update(); }
  static constexpr T merge(const T &x, const T &y)          { return M::merge(x, y); }
  static constexpr T apply(const U &u, const T &x, int)     { return M::merge(u, x); }
  static constexpr U compose(const U &u1, const U &u2)      { return M::merge(u1, u2); }
};
