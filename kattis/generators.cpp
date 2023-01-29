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

template<class T> bool ckmin(T &a, const T &b) { return b < a ? a = b, 1 : 0; }
template<class T> bool ckmax(T &a, const T &b) { return b > a ? a = b, 1 : 0; }

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
  int n, m; cin >> n >> m;
  dsu d(n + 1);
  priority_queue<pair<int, pii>> pq;
  for (int i = 0; i < m; ++i) {
    int ci, ai; cin >> ci >> ai; --ci;
    pq.push({-ai, {ci, n}});
  }
  for (int i = 0; i < n; ++i) {
    int bi; cin >> bi;
    pq.push({-bi, {i, (i + 1) % n}});
  }
  int cnt = 0;
  ll ret = 0;
  while (cnt < n) {
    auto e = pq.top(); pq.pop();
    int w = -e.A, u = e.B.A, v = e.B.B;
    if (d.combine(u, v)) {
      ret += w;
      ++cnt;
    }
  }
  cout << ret;
}
