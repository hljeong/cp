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
  int n, m; cin >> n >> m;
  gr g(n, vi());
  for (int i = 0; i < m; ++i) {
    int a, b; cin >> a >> b; --a; --b;
    g[a].push_back(b);
    g[b].push_back(a);
  }
  queue<int> bfs;
  vi dist(n);
  vc<bool> v(n);
  v[0] = true;
  bfs.push(0);
  while (bfs.size()) {
    int i = bfs.front(); bfs.pop();
    for (int j : g[i]) {
      if (v[j]) continue;
      dist[j] = dist[i] + 1;
      v[j] = true;
      bfs.push(j);
    }
  }
  cout << (dist[n - 1] - 1) << endl;
}
