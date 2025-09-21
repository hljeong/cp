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
const int sgt_maxn = 22;
const sgt_type sgt_id = 0;
vc<sgt_type> sgt(4 * sgt_maxn + 5, sgt_id);

sgt_type merge(const sgt_type &a, const sgt_type &b) {
  return a + b;
}

sgt_type update(const sgt_type &a, const sgt_type &b) {
  return a + b;
}

int mid(int l, int r) { return l + (r - l) / 2; }

void pull(int u) { sgt[u] = merge(sgt[u << 1], sgt[u << 1 | 1]); }

void build(const vc<sgt_type> &a, int u = 1, int l = 0, int r = sgt_maxn - 1) {
  if (l == r) sgt[u] = a[l];
  else {
    int m = mid(l, r);
    build(a, u << 1, l, m);
    build(a, u << 1 | 1, m + 1, r);
    pull(u);
  }
}

void upd(int i, const sgt_type &v, int u = 1, int l = 0, int r = sgt_maxn - 1) {
  if (l == r) sgt[u] = update(sgt[u], v);
  else {
    int m = mid(l, r);
    if (i <= m) upd(i, v, u << 1, l, m);
    else upd(i, v, u << 1 | 1, m + 1, r);
    pull(u);
  }
}

sgt_type qry(int i, int j, int u = 1, int l = 0, int r = sgt_maxn - 1) {
  if (j < l || r < i) return sgt_id;
  else if (i <= l && r <= j) return sgt[u];
  else {
    int m = mid(l, r);
    return merge(qry(i, j, u << 1, l, m), qry(i, j, u << 1 | 1, m + 1, r));
  }
}

ll cnt(vi &x) {
  fill(sgt.begin(), sgt.end(), sgt_id);
  ll ret = 0;
  for (int i : x) {
    ret += qry(i + 1, sgt_maxn - 1);
    upd(i, 1);
  }
  return ret;
}

int main() {
  int n; cin >> n;
  int ts, tt; cin >> ts >> tt;
  vi x(n); for (int i = 0; i < n; ++i) cin >> x[i], --x[i];
  ll cost = (ll) inf * inf;
  for (int msk = 0; msk < (1 << n); ++msk) {
    vi nx;
    for (int i = 0; i < n; ++i) if ((msk >> i) & 1) nx.push_back(x[i]);
    ckmin(cost, cnt(nx) * ts + (ll) (n - __builtin_popcount(msk)) * tt);
  }
  cout << cost << endl;
}
