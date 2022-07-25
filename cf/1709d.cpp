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

template<class T> bool ckmin(T &a, const T &b) { return b < a ? a = b, 1 : 0; }
template<class T> bool ckmax(T &a, const T &b) { return a < b ? a = b, 1 : 0; }

const int maxn = 2e5 + 5; 

ll sgt[4 * maxn], sid = 0;

ll merge(ll a, ll b) { return max(a, b); }

int mid(int l, int r) { return l + (r - l) / 2; }

void pull(int u) { sgt[u] = merge(sgt[u << 1], sgt[u << 1 | 1]); }

void build(vll &a, int u = 1, int l = 0, int r = maxn - 1) {
  if (l != r) {
    int m = mid(l, r);
    build(a, u << 1, l, m); build(a, u << 1 | 1, m + 1, r);
    pull(u);
  } else if (l < a.size()) sgt[u] = a[l];
}

ll qry(int i, int j, int u = 1, int l = 0, int r = maxn - 1) {
  if (r < i || j < l) return sid;
  else if (i <= l && r <= j) return sgt[u];
  else {
    int m = mid(l, r);
    return merge(qry(i, j, u << 1, l, m), qry(i, j, u << 1 | 1, m + 1, r));
  }
}

ll qry(int i) { return qry(i, i); }

int main() {
  int n, m; scanf("%d %d", &n, &m);
  vll a(m); for (int i = 1; i <= m; ++i) scanf("%I64d", &a[i]);
  build(a);
  int q; scanf("%d", &q);
  while (q--) {
    int xs, ys, xf, yf, k; scanf("%d %d %d %d %d", &xs, &ys, &xf, &yf, &k);
    bool good = !((xf - xs) % k) && !((yf - ys) % k);
    ll high = qry(min(ys, yf), max(ys, yf)) + 1;
    high = xs + (high - xs + k - 1) / k * k;
    good &= high <= n;
    printf(good ? "YES\n" : "NO\n");
  }
}