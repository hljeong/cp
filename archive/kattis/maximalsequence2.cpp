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
using si = set<int>;
using usi = unordered_set<int>;
using mii = map<int, int>;
using umii = unordered_map<int, int>;

template<class T> bool ckmin(T &a, const T &b) { return b < a ? a = b, 1 : 0; }
template<class T> bool ckmax(T &a, const T &b) { return a < b ? a = b, 1 : 0; }

umii merge(const umii &a, const umii &b) {
  umii c = a;
  for (auto const &e : b) c[e.A] += e.B;
  return c;
}

bool subset(const umii &a, const usi &b) {
  for (auto const &e : a) if (b.find(e.A) == b.end()) return false;
  return true;
}

const int maxn = 1e5 + 5;

int n;
vi a;
umii sgt[4 * maxn + 5];

int mid(int l, int r) { return l + (r - l) / 2; } 

void pull(int u) { sgt[u] = merge(sgt[u << 1], sgt[u << 1 | 1]); }

void build(int u = 1, int l = 0, int r = n - 1) {
  if (l == r) {
    sgt[u] = umii();
    sgt[u][a[l]] = 1;
  } else {
    int m = mid(l, r);
    build(u << 1, l, m);
    build(u << 1 | 1, m + 1, r);
    pull(u);
  }
}

int qry(int i, const usi& b, int u = 1, int l = 0, int r = n - 1) {
  if (i <= l) {
    if (subset(sgt[u], b)) {
      // cout << l << ", " << r << ", " << r - l + 1 << endl;
      return r - l + 1;
    } else if (l < r) {
      int m = mid(l, r);
      int ans = qry(i, b, u << 1, l, m);
      if (ans == m - l + 1) ans += qry(i, b, u << 1 | 1, m + 1, r);
      // cout << l << ", " << r << ", " << ans << endl;
      return ans;
    } else {
      // cout << l << ", " << r << ", " << 0 << endl;
      return 0;
    }
  } else {
    int m = mid(l, r);
    int ans = 0;
    if (i <= m) {
      ans = qry(i, b, u << 1, l, m);
      if (ans == m - i + 1) ans += qry(i, b, u << 1 | 1, m + 1, r);
    } else {
      ans = qry(i, b, u << 1 | 1, m + 1, r);
    }
    // cout << l << ", " << r << ", " << ans << endl;
    return ans;
  }
}

int main() {
  cin.tie(0);
  ios::sync_with_stdio(0);

  cin >> n;
  a = vi(n);
  for (int i = 0; i < n; ++i) cin >> a[i];
  build();

  int q; cin >> q;
  while (q--) {
    int i, m; cin >> i >> m; --i;
    usi b; for (int j = 0; j < m; ++j) {
      int bj; cin >> bj;
      b.insert(bj);
    }
    cout << qry(i, b) << endl;
  }
}
