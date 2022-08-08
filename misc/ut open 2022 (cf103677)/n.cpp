#include <bits/stdc++.h>
#define A first
#define B second
#define vc vector
using namespace std;
using ll = long long;
using ld = long double;
using vi = vc<int>;
using vll = vc<ll>;
using pii = pair<int, int>;

template<class T> bool ckmin(T& a, const T& b) { return b < a ? a = b, 1 : 0; }
template<class T> bool ckmax(T& a, const T& b) { return a < b ? a = b, 1 : 0; }

const int maxn = 2e5 + 5, mod = 998244353;
int n, q;
ll x[maxn], sgt[4 * maxn], lza[4 * maxn], lzb[4 * maxn];

int mid(int l, int r) {
  return l + (r - l) / 2;
}

void push(int node, int l, int r) {
  if (l == r) {
    sgt[node] = sgt[node] * lza[node] % mod + lzb[node];
    if (sgt[node] >= mod) sgt[node] -= mod;
  } else if (l != r) {
    lza[node << 1] = (lza[node] * lza[node << 1]) % mod;
    lzb[node << 1] = (lza[node] * lzb[node << 1]) % mod + lzb[node];
    if (lzb[node << 1] >= mod) lzb[node << 1] -= mod;
    lza[node << 1 | 1] = (lza[node] * lza[node << 1 | 1]) % mod;
    lzb[node << 1 | 1] = (lza[node] * lzb[node << 1 | 1]) % mod + lzb[node];
    if (lzb[node << 1 | 1] >= mod) lzb[node << 1 | 1] -= mod;
  }
  lza[node] = 1;
  lzb[node] = 0;
}

void build(int node = 1, int l = 0, int r = n - 1) {
  lza[node] = 1;
  if (l == r) {
    sgt[node] = x[l];
  } else {
    int m = mid(l, r);
    build(node << 1, l, m);
    build(node << 1 | 1, m + 1, r);
  }
}

void upd(int i, int j, ll a, ll b, int node = 1, int l = 0, int r = n - 1) {
  push(node, l, r);
  if (r < i || j < l) {
    return;
  } else if (i <= l && r <= j) {
    lza[node] = a;
    lzb[node] = b;
    push(node, l, r);
  } else {
    int m = mid(l, r);
    upd(i, j, a, b, node << 1, l, m);
    upd(i, j, a, b, node << 1 | 1, m + 1, r);
  }
}

ll qry(int i, int node = 1, int l = 0, int r = n - 1) {
  push(node, l, r);
  if (l == r) {
    return sgt[node];
  } else {
    int m = mid(l, r);
    if (i <= m) return qry(i, node << 1, l, m);
    else return qry(i, node << 1 | 1, m + 1, r);
  }
}

void print(int node = 1, int l = 0, int r = n - 1, bool call = true) {
  if (call) {
    print(node, l, r, false);
    cout << endl;
  } else {
    push(node, l, r);
    if (l == r) {
      cout << sgt[node] << ' ';
    } else {
      int m = mid(l, r);
      print(node << 1, l, m, false);
      print(node << 1 | 1, m + 1, r, false);
    }
  }
}

ll qpow(ll a, int b) {
  if (!a) return 0;
  ll ans = 1;
  while (b) {
    if (b & 1) ans = ans * a % mod;
    a = a * a % mod;
    b >>= 1;
  }
  return ans;
}

int main() {
  scanf("%d %d", &n, &q);
  for (int i = 0; i < n; ++i) scanf("%d", &x[i]);
  build();
  while (q--) {
    int tp;
    scanf("%d", &tp);
    if (tp == 1) {
      int l, r, f, g, t;
      scanf("%d %d %d %d %d", &l, &r, &f, &g, &t);
      if (f == 1) {
        upd(l - 1, r - 1, 1, (int) ((ll) t * g % mod));
      } else {
        ll fm1 = f + mod - 1;
        if (fm1 >= mod) fm1 -= mod;
        ll ifm1 = qpow(fm1, mod - 2);
        ll ftm1 = qpow(f, t) + mod - 1;
        if (ftm1 >= mod) ftm1 -= mod;
        ll ft = qpow(f, t);
        ll geom = ftm1 * ifm1 % mod;
        upd(l - 1, r - 1, ft, g * geom % mod);
      }
    } else {
      int i;
      cin >> i;
      printf("%lld\n", qry(i - 1));
    }
    // print();
  }
}