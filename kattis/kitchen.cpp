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
  vll c(n); for (int i = 0; i < n; ++i) cin >> c[i];
  ll v; cin >> v;

  ll ans = -1;
  map<ll, ll> dist;
  priority_queue<pair<ll, ll>> pq;
  dist[c[0]] = 0;
  pq.push({0, c[0]});
  while (pq.size()) {
    pair<ll, ll> e = pq.top(); pq.pop();
    ll w = -e.A, sh = e.B;
    if (w > dist[sh]) continue;
    if ((sh & 127) == v) {
      ans = w;
      break;
    }
    vll s(n);
    for (int i = 0; i < n; ++i) s[i] = (sh >> (i * 7)) & 127;
    // cout << w << ": ";
    // for (int i = 0; i < n; ++i) cout << s[i] << ' ';
    // cout << endl;
    for (int i = 0; i < n; ++i) {
      if (!s[i]) continue;
      for (int j = 0; j < n; ++j) {
        if (i == j || !(c[j] - s[j])) continue;
        ll delta = min(s[i], c[j] - s[j]);
        ll hash = 0;
        for (int k = 0; k < n; ++k) {
          if (k == i) hash |= (s[i] - delta) << (k * 7);
          else if (k == j) hash |= (s[j] + delta) << (k * 7);
          else hash |= s[k] << (k * 7);
        }
        if (dist.find(hash) == dist.end() || ckmin(dist[hash], w + delta)) {
          dist[hash] = w + delta;
          pq.push({-dist[hash], hash});
        }
      }
      ll hash = sh & (~(127ll << (i * 7)));
      ll sum = 0;
      for (int j = 0; j < n; ++j) if (i != j) sum += s[j];
      if (sum < v) continue;
      if (dist.find(hash) == dist.end() || ckmin(dist[hash], w + s[i])) {
        dist[hash] = w + s[i];
        pq.push({-dist[hash], hash});
      }
    }
  }
  cout << ((ans == -1) ? "impossible" : to_string(ans)) << endl;
}
