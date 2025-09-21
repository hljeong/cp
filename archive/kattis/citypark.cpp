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

struct dsu {
  vi par, sz;

  dsu(int n) : par(vi(n)), sz(vi(n)) {
    for (int i = 0; i < n; ++i) { par[i] = i; sz[i] = 1; }
  }

  int find(int i) {
    return par[i] == i ? i : (par[i] = find(par[i]));
  }

  bool combine(int i, int j) {
    i = find(i); j = find(j);
    if (i != j) {
      if (sz[i] < sz[j]) swap(i, j);
      par[j] = i; sz[i] += sz[j];
    }
    return i != j;
  }
};

using a3 = array<int, 4>;

// impl
int main() {
  cin.tie(0) -> sync_with_stdio(0);

  int n; cin >> n;
  vi area;
  dsu d(n);
  map<int, vc<a3>> xx, yy;
  for (int i = 0; i < n; ++i) {
    int x, y, w, h; cin >> x >> y >> w >> h;
    area.pb(w * h);
    xx[y].pb({ x, x + w, i });
    xx[y + h].pb({ x, x + w, i });
    yy[x].pb({ y, y + h, i });
    yy[x + w].pb({ y, y + h, i });
  }
  auto f = [&](vi& v) {
    sort(v.begin(), v.end());
    for (int i = 0; i < v.size()) {
      int j = i + 1;
      int s = v[i][0], e = v[i][1];
      while (j < v.size() && v[j][0] <= e) {
        ckmax(e, v[j][1]);
        d.combine(v[i][2], v[j][2]);
        ++j;
      }
      i = j;
    }
  };
  for (auto [k, v] : xx) f(v);
  for (auto [k, v] : yy) f(v);
  ld ret = 0;
  vc<ld> sz(n);
  for (int i = 0; i < n; ++i) {
    int f = d.find(i);
    sz[f] += area[i];
    ckmax(ret, sz[f]);
  }
  cout << ret << endl;
}
