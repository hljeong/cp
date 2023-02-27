#include <bits/stdc++.h>
#define A first
#define B second
#define vc vector
#define pb push_back
using namespace std;
using ll = long long; using ld = long double;
using vi = vc<int>; using vll = vc<ll>;
using si = set<int>; using sll = set<ll>;
using pii = pair<int, int>; using pll = pair<ll, ll>;
using mii = map<int, int>;

template<class T> bool ckmin(T &a, const T &b) { return b < a ? a = b, 1 : 0; }
template<class T> bool ckmax(T &a, const T &b) { return a < b ? a = b, 1 : 0; }

const int inf = 1e9 + 7;
const int mod = inf;
const ll infll = 0x3f3f3f3f3f3f3f3fll;

using e = array<int, 3>;

stack<pii> defer;

struct dsu {
  vi par, sz;
  vc<set<pair<pii, int>>> qs;

  dsu(int n) : par(vi(n)), sz(vi(n)), qs(n) {
    for (int i = 0; i < n; ++i) { par[i] = i; sz[i] = 1; }
  }

  int find(int i) {
    return par[i] == i ? i : (par[i] = find(par[i]));
  }

  bool combine(int i, int j, int t, vc<pii> &ret) {
    int a = i;
    i = find(i); j = find(j);
    if (i != j) {
      if (sz[i] < sz[j]) swap(i, j);
      if (qs[i].size() < qs[j].size()) swap(qs[i], qs[j]);
      for (pair<pii, int> qry : qs[j]) {
        pair<pii, int> aqry = {{qry.A.B, qry.A.A}, qry.B};
        if (qs[i].count(aqry)) {
          ret[qry.B] = {t, sz[i] + sz[j]};
          qs[i].erase(qs[i].find(aqry));
          defer.push({a, qry.B});
        } else qs[i].insert(qry);
      }
      par[j] = i; sz[i] += sz[j];
    }
    return i != j;
  }
};

int main() {
  int n, m, q; cin >> n >> m >> q;
  vc<e> ed(m);
  for (int i = 0; i < m; ++i) {
    cin >> ed[i][1] >> ed[i][2] >> ed[i][0]; --ed[i][1]; --ed[i][2];
  }
  dsu d(n);
  for (int i = 0; i < q; ++i) {
    int a, b; cin >> a >> b; --a; --b;
    d.qs[a].insert({{b, a}, i});
    d.qs[b].insert({{a, b}, i});
  }
  sort(ed.begin(), ed.end());
  vc<pii> ret(q);
  int last = -1;
  for (int i = 0; i < m; ++i) {
    int u = ed[i][1], v = ed[i][2], t = ed[i][0];
    if (t > last) {
      while (defer.size()) {
        pii dq = defer.top(); defer.pop();
        ret[dq.B].B = d.sz[d.find(dq.A)];
      }
    }
    d.combine(u, v, t, ret);
    last = t;
  }
  while (defer.size()) {
    pii dq = defer.top(); defer.pop();
    ret[dq.B].B = d.sz[d.find(dq.A)];
  }
  for (int i = 0; i < q; ++i) {
    cout << ret[i].A << ' ' << ret[i].B << endl;
  }
}
