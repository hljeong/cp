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
  int t; cin >> t;
  while (t--) {
    int n, m, l; cin >> n >> m >> l;
    gr g(n, vi());
    for (int i = 0; i < m; ++i) {
      int x, y; cin >> x >> y; --x; --y;
      g[x].push_back(y);
    }
    vc<bool> vis(n);
    int ret = 0;
    function<void(int)> dfs = [&](int i) {
      vis[i] = true;
      ++ret;
      for (int j : g[i]) {
        if (vis[j]) continue;
        dfs(j);
      }
    };
    for (int i = 0; i < l; ++i) {
      int z; cin >> z; --z;
      if (!vis[z]) dfs(z);
    }
    cout << ret << endl;
  }
}
