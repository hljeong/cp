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

int main() {
  int n, k, m;
  cin >> n >> k >> m;
  vc<vi> g(n, vi());
  vi deg(n);
  for (int i = 0; i < m; ++i) {
    int u, v;
    cin >> u >> v;
    g[u].push_back(v);
    g[v].push_back(u);
    ++deg[u];
    ++deg[v];
  }
  vc<bool> bad(n); 
  queue<int> q;
  for (int i = 0; i < n; ++i) {
    if (deg[i] <= 1) {
      bad[i] = true;
      q.push(i);
    }
  }
  while (q.size()) {
    int i = q.front();
    q.pop();
    for (int j : g[i]) {
      if (!bad[j] && --deg[j] <= 1) {
        bad[j] = true;
        q.push(j);
      }
    }
  }
  cout << (bad[k] ? "YES" : "NO");
}