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

using edge = array<int, 3>;

int main() {
  int n, m; cin >> n >> m;
  vll ret(n);
  vc<edge> e(m);
  for (int i = 0; i < m; ++i) {
    int u, v, c; cin >> u >> v >> c; --u; --v;
    e[i] = {u, v, c};
  }
  vi ve(n);
  for (int i = 0; i < n; ++i) cin >> ve[i];
  for (int i = 0; i < m; ++i) {
    int u = e[i][0], v = e[i][1], c = e[i][2];
    if (u > v) swap(u, v);
    if (ve[u] < ve[v]) {
      ret[u] -= c;
      ret[v] += c;
    } else {
      ret[u] += c;
      ret[v] -= c;
    }
  }
  ll sret = 0;
  for (int i = 0; i < n; ++i) sret += (ll) ret[i] * ve[i];
  cout << sret << endl;
  for (int i = 0; i < n; ++i) cout << ret[i] << " \n"[i == n - 1];
}