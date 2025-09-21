#include <bits/stdc++.h>
#define A first
#define B second
#define vc vector
#define pb push_back
using namespace std;
using ll = long long; using ld = long double;
using vi = vc<int>; using vll = vc<ll>;
using si = set<int>; using sll = set<ll>;
using pii = pair<int, int>; using mii = map<int, int>;

template<class T> bool ckmin(T &a, const T &b) { return b < a ? a = b, 1 : 0; }
template<class T> bool ckmax(T &a, const T &b) { return a < b ? a = b, 1 : 0; }

const int inf = 1e9 + 7;
const int mod = inf;
const ll infll = 0x3f3f3f3f3f3f3f3fll;

using a64 = array<ll, 64>;
using sgt_type = pair<array<a64, 2>, pair<ll, int>>;
const int sgt_maxn = 2e5 + 5;
const sgt_type sgt_id = sgt_type();
vc<sgt_type> sgt(4 * sgt_maxn + 5, sgt_id);

sgt_type merge(const sgt_type &a, const sgt_type &b) {
  sgt_type ret;
  for (int i = 0; i < 64; ++i) {
    ret.A[0][i] = a.A[0][i] + b.A[0][i ^ a.B.B]; // prefix freq
    ret.A[1][i] = b.A[1][i] + a.A[1][i ^ b.B.B]; // suffix freq
    ret.B.A += a.A[1][i] * b.A[0][i]; // count 0
  }
  ret.B.A += a.B.A + b.B.A;
  ret.B.B = a.B.B ^ b.B.B; // sum
  return ret;
}

sgt_type update(const sgt_type &a, const sgt_type &b) {
  return b;
}

int mid(int l, int r) { return l + (r - l) / 2; }

void pull(int u) { sgt[u] = merge(sgt[u << 1], sgt[u << 1 | 1]); }

void build(const vc<sgt_type> &a, int u = 1, int l = 0, int r = sgt_maxn - 1) {
  if (l > a.size()) return;
  if (l == r) sgt[u] = a[l];
  else {
    int m = mid(l, r);
    build(a, u << 1, l, m);
    build(a, u << 1 | 1, m + 1, r);
    pull(u);
  }
}

sgt_type ch2s(char c) {
  int x = 1 << (c - 'a');
  sgt_type ret;
  ret.A[0][x] = ret.A[1][x] = 1;
  ret.B.A = 0;
  ret.B.B = x;
  return ret;
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
  if (i <= l && r <= j) return sgt[u];

  int m = mid(l, r);
  return merge(qry(i, j, u << 1, l, m), qry(i, j, u << 1 | 1, m + 1, r));
}

int main() {
  string s; cin >> s;
  int n = s.length();
  vc<sgt_type> b(n);
  for (int i = 0; i < n; ++i) b[i] = ch2s(s[i]);
  build(b);
  int q; cin >> q;
  while (q--) {
    int t; cin >> t;
    if (t == 1) {
      int l, r; cin >> l >> r; --l; --r;
      cout << qry(l, r).B.A << endl;
    } else {
      int i; string x; cin >> i >> x; --i;
      upd(i, ch2s(x[0]));
    }
  }
}
