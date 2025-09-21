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

usi merge(const usi &a, const usi &b) {
  usi c = a;
  for (auto const &x : b) c.insert(x);
  return c;
}

bool subset(const usi &a, const usi &b) {
  int s = a.size();
  for (auto const &x : b) if (a.find(x) != a.end()) --s;
  return s == 0;
}

const int maxn = 1e5 + 5;

int n;
vi a;
usi sgt[4 * maxn + 5];

int mid(int l, int r) { return l + (r - l) / 2; } 

void pull(int u) { sgt[u] = merge(sgt[u << 1], sgt[u << 1 | 1]); }

void build(int u = 1, int l = 0, int r = n - 1) {
  if (l == r) {
    sgt[u] = usi();
    sgt[u].insert(a[l]);
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
      return r - l + 1;
    } else if (l < r) {
      int m = mid(l, r);
      int ans = qry(i, b, u << 1, l, m);
      if (ans == m - l + 1) ans += qry(i, b, u << 1 | 1, m + 1, r);
      return ans;
    } else {
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
