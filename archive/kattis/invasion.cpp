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
  while (true) {
    int n, m, a, k; cin >> n >> m >> a >> k;
    if (!n) return 0;
    vc<vc<pii>> g(n, vc<pii>());

    for (int i = 0; i < m; ++i) {
      int u, v, w; cin >> u >> v >> w; --u; --v;
      g[u].push_back({v, w});
      g[v].push_back({u, w});
    }

    vi dist(n, inf);
    si bad;
    priority_queue<pii> pq;
    for (int i = 0; i < a; ++i) {
      int b; cin >> b; --b;
      dist[b] = 0;
      bad.insert(b);
      pq.push({0, b});
      while (pq.size()) {
        pii p = pq.top(); pq.pop();
        int d = -p.A, j = p.B;
        if (d > dist[j]) continue;
        if (d < k) bad.insert(j);
        for (pii e : g[j]) {
          int nei = e.A, w = e.B;
          if (ckmin(dist[nei], d + w)) {
            pq.push({-dist[nei], nei});
          }
        }
      }
      cout << n - bad.size() << endl;
    }
    cout << endl;
  }
}
