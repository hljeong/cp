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

template<class T> bool ckmin(T& a, const T& b) { return b < a ? a = b, 1 : 0; }
template<class T> bool ckmax(T& a, const T& b) { return a < b ? a = b, 1 : 0; }

int dfs(vc<vi> &g, int i, vc<bool> &v) {
  int ans = 1;
  v[i] = true;
  for (int j : g[i]) if (!v[j]) ans += dfs(g, j, v);
  return ans;
}

int main() {
  int h, n, m;
  cin >> h >> n >> m;
  vc<vi> mp(n, vi(m));  
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      char x;
      cin >> x;
      mp[i][j] = x == '.';
    }
  }
  vc<vi> g(n * m);
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      if (!mp[i][j]) continue;
      if (i < n - 1) {
        if (i & 1) {
          if (mp[i + 1][j]) {
            g[i * m + j].push_back(((i + 1) * m) + j);
            g[(i + 1) * m + j].push_back(i * m + j);
          }
          if (j < m - 1 && mp[i + 1][j + 1]) {
            g[i * m + j].push_back(((i + 1) * m) + j + 1);
            g[(i + 1) * m + j + 1].push_back(i * m + j);
          }
        } else {
          if (j && mp[i + 1][j - 1]) {
            g[i * m + j].push_back(((i + 1) * m) + j - 1);
            g[(i + 1) * m + j - 1].push_back(i * m + j);
          }
          if (mp[i + 1][j]) {
            g[i * m + j].push_back(((i + 1) * m) + j);
            g[(i + 1) * m + j].push_back(i * m + j);
          }
        }
      }
      if (j < m - 1 && mp[i][j + 1]) {
        g[i * m + j].push_back(i * m + j + 1);
        g[i * m + j + 1].push_back(i * m + j);
      }
    }
  }
  vc<bool> v(n * m);
  priority_queue<int> comps; 
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      if (mp[i][j] && !v[i * m + j]) {
        int s = dfs(g, i * m + j, v);
        comps.push(s);
      }
    }
  }
  int ans = 0;
  while (h > 0) {
    h -= comps.top();
    comps.pop();
    ++ans;
  }
  cout << ans << endl;
}