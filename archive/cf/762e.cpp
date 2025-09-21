#include <bits/stdc++.h>
#define A first
#define B second
#define vc vector
#define pb push_back
#define endl '\n'
using namespace std;
using ll = long long; using ld = long double;
using vi = vc<int>; using vll = vc<ll>;
using si = set<int>; using sll = set<ll>;
using pi = pair<int, int>; using pll = pair<ll, ll>;
using qi = queue<int>; using mi = map<int, int>;

template<class T> bool ckmin(T &a, const T &b) { return b < a ? a = b, 1 : 0; }
template<class T> bool ckmax(T &a, const T &b) { return a < b ? a = b, 1 : 0; }

constexpr int inf = 1e9 + 7;
constexpr int mod = inf;
constexpr ll infll = 0x3f3f3f3f3f3f3f3fll;

using a3 = array<int, 3>;

constexpr int N = 300005;
using T = int;
/*
vi msgt(4 * N + 5);
*/

int mid(int l, int r) {
  return l + (r - l) / 2;
}

/*
void pull(int u) {
  msgt[u] = msgt[u << 1] + msgt[u << 1 | 1];
}

void upd(int i, const T &x, int u = 1, int l = 0, int r = N - 1) {
  if (l == r) msgt[u] += x;
  else {
    int m = mid(l, r);
    if (i <= m) upd(i, x, u << 1, l, m);
    else upd(i, x, u << 1 | 1, m + 1, r);
    pull(u);
  }
}

T qry(int i, int j, int u = 1, int l = 0, int r = N - 1) {
  if (j < l || r < i) return 0;
  if (i <= l && r <= j) return msgt[u];
  int m = mid(l, r);
  return qry(i, j, u << 1, l, m) + qry(i, j, u << 1 | 1, m + 1, r);
}
*/

vi mfwt(N + 1);

int lowbit(int i) {
  return i & (-i);
}

void upd(int i, int x) {
  ++i;
  while (i <= N) {
    mfwt[i] += x;
    i += lowbit(i);
  }
}

int qry(int i) {
  int ret = 0;
  while (i) {
    ret += mfwt[i];
    i -= lowbit(i);
  }
  return ret;
}

template<typename T, size_t N>
struct fwt {
  vc<T> val;
  function<T(const T&, const T&)> merge;
  function<T()> identity;

  fwt(function<T(const T&, const T&)> merge) : 
      val(N + 1), 
      merge(merge) {
    identity = []() { return T(); };
  }

  fwt(function<T(const T&, const T&)> merge, 
      function<T()> identity) : 
      val(N + 1), 
      merge(merge), 
      identity(identity) {}

  void upd(int i, const T &x) {
    ++i;
    while (i < val.size()) {
      val[i] = merge(val[i], x);
      i += lowbit(i);
    }
  }

  T qry(int i) {
    T ret = identity();
    while (i) {
      ret = merge(ret, val[i]);
      i -= lowbit(i);
    }
    return ret;
  }
};

template<typename T, size_t N>
struct sgt {
  vc<T> val;
  function<T(const T&, const T&)> merge, update;
  function<T()> identity;

  sgt(function<T(const T&, const T&)> combine) : 
      val(4 * N + 5), 
      merge(combine), 
      update(combine) {
    identity = []() { return T(); };
  }

  sgt(function<T(const T&, const T&)> combine, 
      function<T()> identity) : 
      val(4 * N + 5), 
      merge(combine), 
      update(combine), 
      identity(identity) {}

  sgt(function<T(const T&, const T&)> merge, 
      function<T(const T&, const T&)> update) : 
      val(4 * N + 5), 
      merge(merge), 
      update(update) {
    identity = []() { return T(); };
  }

  sgt(const vc<T> &a, 
      function<T(const T&, const T&)> combine) : 
      val(4 * N + 5), 
      merge(combine), 
      update(combine) {
    identity = []() { return T(); };
    build(a);
  }

  sgt(const vc<T> &a, 
      function<T(const T&, const T&)> combine, 
      function<T()> identity) : 
      val(4 * N + 5), 
      merge(combine), 
      update(combine), 
      identity(identity) {
    build(a);
  }

  sgt(const vc<T> &a, 
      function<T(const T&, const T&)> merge, 
      function<T(const T&, const T&)> update) : 
      val(4 * N + 5), 
      merge(merge), 
      update(update) {
    identity = []() { return T(); };
    build(a);
  }

  sgt(const vc<T> &a, 
      function<T(const T&, const T&)> merge, 
      function<T(const T&, const T&)> update, 
      function<T()> identity) : 
      val(4 * N + 5), 
      merge(merge), 
      update(update), 
      identity(identity){
    identity = []() { return T(); };
    build(a);
  }

  void pull(int u) {
    val[u] = val[u << 1] + val[u << 1 | 1];
  }

  void build(const vc<T> &a, int u = 1, int l = 0, int r = N - 1) {
    if (l >= a.size()) return;
    if (l == r) val[u] = a[l];
    else {
      int m = mid(l, r);
      build(a, u << 1 , l, m);
      build(a, u << 1 | 1, m + 1, r);
      pull(u);
    }
  }

  void upd(int i, const T &x, int u = 1, int l = 0, int r = N - 1) {
    if (l == r) val[u] += x;
    else {
      int m = mid(l, r);
      if (i <= m) upd(i, x, u << 1, l, m);
      else upd(i, x, u << 1 | 1, m + 1, r);
      pull(u);
    }
  }

  T qry(int i, int j, int u = 1, int l = 0, int r = N - 1) {
    if (j < l || r < i) return 0;
    if (i <= l && r <= j) return val[u];
    int m = mid(l, r);
    return qry(i, j, u << 1, l, m) + qry(i, j, u << 1 | 1, m + 1, r);
  }
};

// editorial sol
int main() {
  cin.tie(0) -> sync_with_stdio(0);

  int n, k; cin >> n >> k;
  vc<vc<pi>> st(10005);
  si xs; unordered_map<int, int> comp; int id = 0;
  for (int i = 0; i < n; ++i) {
    int x, r, f; cin >> x >> r >> f;
    st[f].pb({ x, r });
    xs.insert(x - r);
    xs.insert(x);
    xs.insert(x + r);
  }
  // coordinate compression
  for (int x : xs) comp[x] = id++;
  ll ret = 0;
  for (int i = 1; i <= 10000; ++i) {
    if (!st[i].size()) continue;
    vc<a3> e;
    // left station
    for (auto [x, r] : st[i]) e.pb({ x, 1, r });
    for (int j = max(0, i - k); j <= min(i + k, 10000); ++j) {
      // right station
      for (auto [x, r] : st[j]) e.pb({ x - r, 0, x });
    }
    sort(e.begin(), e.end());
    for (auto [x, tp, v] : e) {
      // if (tp) ret += qry(comp[x] + 1, comp[x + v]);
      if (tp) ret += qry(comp[x + v] + 1) - qry(comp[x] + 1);
      else upd(comp[v], 1);
    }
    for (auto [x, tp, v] : e) if (!tp) upd(comp[v], -1);
  }
  cout << ret << endl;
}
