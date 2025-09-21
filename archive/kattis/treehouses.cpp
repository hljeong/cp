#include <bits/stdc++.h>
#define A first
#define B second
#define vc vector
using namespace std;
using ll = long long; using ld = long double;
using vi = vc<int>; using vll = vc<ll>;
using si = set<int>; using sll = set<ll>;
using pii = pair<int, int>; using mii = map<int, int>;
using gr = vc<vi>;

template<class T> bool ckmin(T &a, const T &b) { return b < a ? a = b, 1 : 0; }
template<class T> bool ckmax(T &a, const T &b) { return a < b ? a = b, 1 : 0; }

const int inf = 1e9 + 7;
const int mod = inf;

ld dist(pair<ld, ld> &a, pair<ld, ld> &b) {
  ld dx = a.A - b.A, dy = a.B - b.B;
  return sqrt(dx * dx + dy * dy);
}

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
  int n, e, p; cin >> n >> e >> p;
  vc<pair<ld, ld>> pt(n);
  priority_queue<pair<ld, pii>> q;
  for (int i = 0; i < n; ++i) {
    cin >> pt[i].A >> pt[i].B;
    for (int j = 0; j < i; ++j) {
      q.push({ -dist(pt[i], pt[j]), { j, i } });
    }
  }
  dsu d(n);
  int c = n;
  for (int i = 1; i < e; ++i) {
    if (d.combine(i - 1, i)) --c;
  }
  for (int i = 0; i < p; ++i) {
    int a, b; cin >> a >> b; --a; --b;
    if (d.combine(a, b)) --c;
  }
  ld ans = 0;
  while (c > 1) {
    auto e = q.top(); q.pop();
    if (d.combine(e.B.A, e.B.B)) {
      --c;
      ans -= e.A;
    }
  }
  cout << ans << endl;
}
