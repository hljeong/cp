#include <bits/stdc++.h>
#define A first
#define B second
#define vc vector
#define pb push_back
using namespace std;
using ll = long long; using ld = long double;
using vi = vc<int>; using vll = vc<ll>;
using si = set<int>; using sll = set<ll>;
using pii = pair<int, int>; using pll = pair<ll, ll>;
using mii = map<int, int>;

template<class T> bool ckmin(T &a, const T &b) { return b < a ? a = b, 1 : 0; }
template<class T> bool ckmax(T &a, const T &b) { return a < b ? a = b, 1 : 0; }

const int inf = 1e9 + 7;
const int mod = inf;
const ll infll = 0x3f3f3f3f3f3f3f3fll;

using rect = array<int, 4>;

template<size_t N>
struct sgt {
  ll id = 0;
  vll val, lz;

  sgt() : val(4 * N + 5, id), lz(4 * N + 5, id) {}

  sgt(vi &a) : val(4 * N + 5, id), lz(4 * N + 5, id) { build(a); }

  ll merge(ll a, ll b) { return a + b; }

  ll update(ll a, ll b) { return a + b; }

  int mid(int l, int r) { return l + (r - l) / 2; }

  void pull(int u) { val[u] = merge(val[u << 1], val[u << 1 | 1]); }

  void push(int u, int l, int r) {
    if (lz[u] == id) return;
    val[u] += lz[u] * (r - l + 1);
    if (l != r) {
      lz[u << 1] = update(lz[u << 1], lz[u]);
      lz[u << 1 | 1] = update(lz[u << 1 | 1], lz[u]);
    }
    lz[u] = id;
  }

  void build(vi &a, int u = 1, int l = 0, int r = N - 1) {
    if (l > a.size()) return;
    if (l == r) val[u] = a[l];
    else {
      int m = mid(l, r);
      build(a, u << 1 , l, m);
      build(a, u << 1 | 1, m + 1, r);
      pull(u);
    }
  }

  void upd(int i, int j, ll x, int u = 1, int l = 0, int r = N - 1) {
    push(u, l, r);
    if (j < l || r < i) return;
    if (i <= l && r <= j) {
      lz[u] = x; push(u, l, r);
    } else {
      int m = mid(l, r);
      upd(i, j, x, u << 1, l, m);
      upd(i, j, x, u << 1 | 1, m + 1, r);
      pull(u);
    }
  }

  void upd(int i, ll x) {
    upd(i, i, x);
  }

  ll qry(int i, int j, int u = 1, int l = 0, int r = N - 1) {
    push(u, l, r);
    if (j < l || r < i) return id;
    if (i <= l && r <= j) return val[u];
    int m = mid(l, r);
    return merge(qry(i, j, u << 1, l, m), qry(i, j, u << 1 | 1, m + 1, r));
  }
  
  ll qry(int i) {
    return qry(i, i);
  }

  ll get(int u = 1, int l = 0, int r = N - 1) {
    if (lz[u] > 0) return r - l + 1;
    push(u, l, r);
    if (l == r) return !!val[u];
    if (!val[u]) return 0;
    int m = mid(l, r);
    return get(u << 1, l, m) + get(u << 1 | 1, m + 1, r);
  }
};

int main() {
  int n; cin >> n;
  vc<pair<pii, pii>> e;
  for (int i = 0; i < n; ++i) {
    ld x1d, y1d, x2d, y2d;
    cin >> x1d >> y1d >> x2d >> y2d;
    int x1 = round(x1d * 100) + 100000;
    int y1 = round(y1d * 100) + 100000;
    int x2 = round(x2d * 100) + 100000;
    int y2 = round(y2d * 100) + 100000;
    e.pb({{x1, 1}, {y1, y2}});
    e.pb({{x2, -1}, {y1, y2}});
  }
  sort(e.begin(), e.end());
  sgt<200001> t;
  int lastx = 0;
  ll ret = 0;
  for (auto ev : e) {
    int x = ev.A.A, type = ev.A.B, y1 = ev.B.A, y2 = ev.B.B - 1;
    ret += (x - lastx) * t.get();
    t.upd(y1, y2, type);
    lastx = x;
  }
  cout << setprecision(2) << fixed << ((ld) round((ld) ret / 100) / 100) << endl;
}
