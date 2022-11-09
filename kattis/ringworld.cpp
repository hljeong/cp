#include <bits/stdc++.h>
#define A first
#define B second
#define vc vector
using namespace std;
using ll = long long; using ld = long double;
using vi = vc<int>; using vll = vc<ll>;
using si = set<int>; using sll = set<ll>;
using pii = pair<int, int>; using mii = map<int, int>;
using gr = vc<vi>;

template<class T> bool ckmin(T &a, const T &b) { return b < a ? a = b, 1 : 0; }
template<class T> bool ckmax(T &a, const T &b) { return a < b ? a = b, 1 : 0; }

const int inf = 1e9 + 7;
const int mod = inf;

using sgt_type = int;
const int sgt_maxn = 1e9 + 5;
const sgt_type sgt_id = 0;
vi sgt_l(2, -1), sgt_r(2, -1);
vc<sgt_type> sgt(2, sgt_id);

sgt_type merge(const sgt_type &a, const sgt_type &b) {
  return a + b;
}

sgt_type update(const sgt_type &a, const sgt_type &b) {
  return a + b;
}

int mid(int l, int r) { return l + (r - l) / 2; }

void make(int u) {
  sgt_l[u] = sgt.size(); sgt.push_back(sgt_id);
  sgt_l.push_back(-1); sgt_r.push_back(-1);

  sgt_r[u] = sgt.size(); sgt.push_back(sgt_id);
  sgt_l.push_back(-1); sgt_r.push_back(-1);
}

void pull(int u) { sgt[u] = merge(sgt[sgt_l[u]], sgt[sgt_r[u]]); }

void clear() {
  sgt_l = vi(2, -1);
  sgt_r = vi(2, -1);
  sgt = vc<sgt_type>(2, sgt_id);
}

void build(const vc<sgt_type> &a, int u = 1, int l = 0, int r = sgt_maxn - 1) {
  if (l == r) sgt[u] = a[l];
  else {
    make(u);
    int m = mid(l, r);
    build(a, sgt_l[u], l, m);
    build(a, sgt_r[u], m + 1, r);
    pull(u);
  }
}

void upd(int i, const sgt_type &v, int u = 1, int l = 0, int r = sgt_maxn - 1) {
  if (l == r) sgt[u] = update(sgt[u], v);
  else {
    int m = mid(l, r);
    if (!~sgt_l[u]) make(u);
    if (i <= m) upd(i, v, sgt_l[u], l, m);
    else upd(i, v, sgt_r[u], m + 1, r);
    pull(u);
  }
}

sgt_type qry(int i, int j, int u = 1, int l = 0, int r = sgt_maxn - 1) {
  if (j < l || r < i) return sgt_id;
  if (i <= l && r <= j) return sgt[u];

  if (!~sgt_l[u]) make(u);
  int m = mid(l, r);
  return merge(qry(i, j, sgt_l[u], l, m), qry(i, j, sgt_r[u], m + 1, r));
}

int minst_r(function<bool(sgt_type, int, int)> pred, int i, int j, int u, int l, int r, sgt_type &acc) {
  if (r < i) return -1;
  if (j < l) return j + 1;
  if (i <= l && r <= j && !pred(merge(acc, sgt[u]), i, r)) {
    acc = merge(acc, sgt[u]);
    if (r == j) return j + 1;
    return -1;
  }
  if (l == r) return l;

  int m = mid(l, r), ret;
  if (!~sgt_l[u]) make(u);
  if (~(ret = minst_r(pred, i, j, sgt_l[u], l, m, acc))) return ret;
  return minst_r(pred, i, j, sgt_r[u], m + 1, r, acc);
}

int minst(function<bool(sgt_type, int, int)> pred, int i = 0, int j = sgt_maxn - 1) {
  sgt_type acc = sgt_id;
  return minst_r(pred, i, j, 1, 0, sgt_maxn - 1, acc);
}

int main() {
  cin.tie(0);
  ios_base::sync_with_stdio(0);

  int t; cin >> t;
  while (t--) {
    clear();
    int m, n; cin >> m >> n;
    vc<pii> r(n); for (int i = 0; i < n; ++i) cin >> r[i].A >> r[i].B;
    vc<pii> lin;
    for (int i = 0; i < n; ++i) {
      if (r[i].A <= r[i].B) {
        lin.push_back({ r[i].B, -r[i].A });
        lin.push_back({ r[i].B + m, -(r[i].A + m) });
      } else {
        lin.push_back({ r[i].B + m, -r[i].A });
      }
    }
    sort(lin.begin(), lin.end());
    function<bool(int, int, int)> check = [&](int x, int l, int r) { return x < r - l + 1; };
    bool good = n <= m;
    if (good) for (const auto &seg : lin) {
      int asgn = minst(check, -seg.B, seg.A);
      if (asgn > seg.A) {
        good = false;
        break;
      }
      upd(asgn, 1);
    }
    cout << (good ? "YES" : "NO") << endl;
  }
}
