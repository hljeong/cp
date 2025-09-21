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
using gr = vc<vi>; using wgr = vc<vc<pii>>;

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

int main() {
  int m, n; cin >> m >> n;
  vc<vc<ld>> p(m, vc<ld>(n));
  for (int i = 0; i < m; ++i) {
    for (int j = 0; j < n; ++j) {
      cin >> p[i][j];
    }
  }
  dsu d(m + n);
  vc<vi> c(m);
  for (int i = 0; i < m; ++i) {
    int k; cin >> k;
    for (int j = 0; j < k; ++j) {
      int cj; cin >> cj;
      c[i].pb(cj);
      d.combine(i, m + cj);
    }
  }
  vc<pii> ret;
  vi comp(m + n);
  map<int, set<int>> comps;
  map<int, set<pii>> buttons;
  for (int i = 0; i < m + n; ++i) {
    comp[i] = d.find(i);
    if (!comps.count(comp[i])) comps[comp[i]] = set<int>();
    comps[comp[i]].insert(i);
  }
  for (int i = 0; i < m; ++i) {
    for (int cj : c[i]) {
      buttons[comp[i]].insert({i, cj});
    }
  }
  dsu d2(m + n);
  for (int i = 0; i < m + n; ++i) {
    if (d.find(i) == i) {
      priority_queue<pair<ld, pii>> pq;
      for (const auto &e : buttons[i]) {
        int x = e.A, y = e.B;
        pq.push({p[x][y], {x, y}});
      }
      int cnt = comps[i].size() - 1;
      while (cnt) {
        pair<ld, pii> e = pq.top(); pq.pop();
        int x = e.B.A, y = e.B.B;
        if (d2.find(x) != d2.find(m + y)) {
          d2.combine(x, m + y);
          ret.pb({x, y});
          --cnt;
        }
      }
    }
  }
  sort(ret.begin(), ret.end());
  for (const auto &e : ret) {
    cout << e.A << ' ' << e.B << endl;
  }
}
