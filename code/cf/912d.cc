#include <bits/stdc++.h>
using namespace std;
using ll = long long;
template <typename T> using vc = vector<T>;
using vi = vc<int>;
using pii = pair<int, int>;

#define max(a, b) ((a) > (b) ? (a) : (b))
#define min(a, b) ((a) < (b) ? (a) : (b))

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout << fixed << setprecision(12);

  ll n, m, r, k;
  cin >> n >> m >> r >> k;

  // fish at (x, y) contributes
  // (min(n, x + r) - max(x, r) + 1) * (min(m, y + r) - max(y, r) + 1) /
  auto f = [=](pii p) {
    auto [x, y] = p;
    return ll(min(x, n - r) - max(0, x - r + 1) + 1) *
           (min(y, m - r) - max(0, y - r + 1) + 1);
  };

  set<pii> seen;
  priority_queue<pair<ll, pii>> bfs;
  pii og = {n / 2, m / 2};
  seen.insert(og);
  bfs.push({f(og), og});
  ll nom = 0;
  ll denom = ll(n - r + 1) * (m - r + 1);
  while (k--) {
    auto [w, p] = bfs.top();
    auto [x, y] = p;
    // cout << x << ", " << y << ", " << w << endl;
    nom += w;
    bfs.pop();
    for (auto np : {
             pii{x - 1, y},
             pii{x + 1, y},
             pii{x, y - 1},
             pii{x, y + 1},
         }) {
      auto [nx, ny] = np;
      if (nx >= 0 and nx < n and ny >= 0 and ny < m) {
        if (!seen.count(np)) {
          seen.insert(np);
          bfs.push({f(np), np});
        }
      }
    }
  }
  cout << ((long double)nom / denom) << endl;
}
