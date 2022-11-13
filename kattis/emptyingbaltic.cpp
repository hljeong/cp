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

const int dx[8] = { -1, 0, 1, -1, 1, -1, 0, 1 };
const int dy[8] = { -1, -1, -1, 0, 0, 1, 1, 1 };

int main() {
  int h, w; cin >> h >> w;
  vc<vi> l(h, vi(w));
  for (int i = 0; i < h; ++i) for (int j = 0; j < w; ++j) cin >> l[i][j];
  int x, y; cin >> x >> y; --x; --y;
  vc<vc<bool>> vis(h, vc<bool>(w));
  priority_queue<pair<int, pii>> bfs;
  bfs.push({ -l[x][y], { x, y } });
  vis[x][y] = true;
  ll ans = max(0, -l[x][y]);
  auto oob = [&](int i, int j) {
    return i < 0 || h <= i || j < 0 || w <= j;
  };
  while (bfs.size()) {
    auto p = bfs.top(); bfs.pop();
    int i = p.B.A, j = p.B.B;
    for (int di : dx) {
      for (int dj : dy) {
        int ni = i + di, nj = j + dj;
        if (oob(ni, nj) || vis[ni][nj]) continue;
        vis[ni][nj] = true;
        bfs.push({ -l[ni][nj], { ni, nj } });
        ckmax(l[ni][nj], l[i][j]);
        ans += max(0, -l[ni][nj]);
      }
    }
  }
  cout << ans << endl;
}
