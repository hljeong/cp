#include <bits/stdc++.h>
#define A first
#define B second
#define vc vector
using namespace std;
using ll = long long;
using ld = long double;
using vi = vc<int>;
using vll = vc<ll>;
using pii = pair<int, int>;

template<class T> bool ckmin(T &a, const T &b) { return b < a ? a = b, 1 : 0; }
template<class T> bool ckmax(T &a, const T &b) { return a < b ? a = b, 1 : 0; }

int main() {
  int n; cin >> n;
  vi c(n); for (int i = 0; i < n; ++i) cin >> c[i];
  int v; cin >> v;

  int ans = -1;
  map<vi, int> dist;
  priority_queue<pair<int, vi>> pq;
  vi st = c;
  for (int i = 1; i < n; ++i) st[i] = 0;
  dist[st] = 0;
  pq.push({0, st});
  while (pq.size()) {
    pair<int, vi> e = pq.top(); pq.pop();
    int w = -e.A;
    vi s = e.B;
    if (w > dist[s]) continue;
    if (s[0] == v) {
      ans = w;
      break;
    }
    for (int i = 0; i < n; ++i) {
      if (!s[i]) continue;
      for (int j = 0; j < n; ++j) {
        if (i == j || !(c[j] - s[j])) continue;
        int delta = min(s[i], c[j] - s[j]);
        vi ns = s;
        ns[i] -= delta;
        ns[j] += delta;
        if (dist.find(ns) == dist.end() || ckmin(dist[ns], w + delta)) {
          dist[ns] = w + delta;
          pq.push({-dist[ns], ns});
        }
      }
      vi ns = s;
      ns[i] = 0;
      int sum = 0;
      for (int j = 0; j < n; ++j) ns[j];
      if (sum < v) continue;
      if (dist.find(ns) == dist.end() || ckmin(dist[ns], w + s[i])) {
        dist[ns] = w + s[i];
        pq.push({-dist[ns], ns});
      }
    }
  }
  cout << ((ans == -1) ? "impossible" : to_string(ans)) << endl;
}
