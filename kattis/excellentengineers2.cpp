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

const int inf = 1e9 + 7;
const int mod = inf;
const ll infll = 0x3f3f3f3f3f3f3f3fll;

int mid(int l, int r) {
  return l + (r - l) / 2;
}

const int maxn = 1e5 + 5;
vi val(4 * maxn + 5, inf);

void pull(int u) {
  val[u] = min(val[u << 1], val[u << 1 | 1]);
}

void rst(int u = 1, int l = 0, int r = maxn - 1) {
  if (l == r) val[u] = inf;
  else {
    int m = mid(l, r);
    val[u] = inf;
    rst(u << 1, l, m);
    rst(u << 1 | 1, m + 1, r);
  }
}

void upd(int i, const int x, int u = 1, int l = 0, int r = maxn - 1) {
  if (l == r) ckmin(val[u], x);
  else {
    int m = mid(l, r);
    if (i <= m) upd(i, x, u << 1, l, m);
    else upd(i, x, u << 1 | 1, m + 1, r);
    pull(u);
  }
}

int qry(int i, int j, int u = 1, int l = 0, int r = maxn - 1) {
  if (j < l || r < i) return inf;
  if (i <= l && r <= j) return val[u];
  int m = mid(l, r);
  return min(qry(i, j, u << 1, l, m), qry(i, j, u << 1 | 1, m + 1, r));
}

using a3 = array<int, 3>;

// sort then min segtree
int main() {
  cin.tie(0) -> sync_with_stdio(0);
  
  int t; cin >> t;
  while (t--) {
    rst();
    int n, ret = 0; cin >> n;
    vc<a3> p(n);
    for (int i = 0; i < n; ++i) {
      cin >> p[i][0] >> p[i][1] >> p[i][2];
    }
    sort(p.begin(), p.end());
    for (auto [_, y, z] : p) {
      if (qry(1, y - 1) >= z) {
        ++ret;
        // cout << _ << " " << y << " " << z << endl;
      }
      upd(y, z);
    }
    cout << ret << endl;
  }
}
