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

int main() {
  int n, m, k; cin >> n >> m >> k;
  if (n == 2 && k == 1) {
    cout << "impossible" << endl;
    return 0;
  }
  for (int i = 0, _; i < n; ++i) cin >> _;
  gr g(n, vi());
  for (int i = 0; i < m; ++i) {
    int u, v; cin >> u >> v; --u; --v;
    g[u].push_back(v);
    g[v].push_back(u);
  }
  for (int i = 0; i < n; ++i) sort(g[i].rbegin(), g[i].rend());
  queue<int> bfs;
  vc<bool> v(n);
  string ret(n, ' ');
  bfs.push(0);
  v[0] = true;
  char N = 'N', S = 'S';
  if (k < n - k) {
    k = n - k;
    swap(N, S);
  }
  while (bfs.size()) {
    int i = bfs.front(); bfs.pop();
    if (k) {
      ret[i] = N;
      --k;
    } else ret[i] = S;
    for (int j : g[i]) {
      if (v[j]) continue;
      v[j] = true;
      bfs.push(j);
    }
  }
  cout << ret << endl;
}
