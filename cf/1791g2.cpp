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

template<class T> T minst(function<bool(T)> pred, T i, T j) {
  T ret = j + 1;
  for (T l = i, r = j, m; l <= r; ) {
    if (pred(m = l + (r - l) / 2)) r = (ret = m) - 1;
    else l = m + 1;
  }
  return ret;
}

int main() {
  cin.tie(0) -> sync_with_stdio(0);

  int t; cin >> t;
  while (t--) {
    int n, c; cin >> n >> c;
    vll a(n), p(n + 1); for (int i = 0; i < n; ++i) cin >> a[i];
    vc<pair<ll, int>> cost(n);
    for (int i = 0; i < n; ++i) {
      cost[i].A = a[i] + min(i + 1, n - i);
      cost[i].B = i;
    }
    sort(cost.begin(), cost.end());
    vi pos(n);
    for (int i = 0; i < n; ++i) {
      pos[cost[i].B] = i;
      p[i + 1] = p[i] + cost[i].A;
    }
    int ret = 0;
    for (int i = 0; i < n; ++i) {
      if (c < a[i] + i + 1) continue;
      function<bool(int)> pred = [&](int use) {
        ll pcost = a[i] + i + 1 + p[use];
        if (pos[i] < use) pcost -= a[i] + min(i + 1, n - i);
        return c < pcost;
      };
      int cret = minst(pred, 0, n) - 1;
      if (cret <= pos[i]) ++cret;
      ckmax(ret, cret);
    }
    cout << ret << endl;
  }
}
