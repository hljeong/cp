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

const int maxn = 1e5 + 5;

int n, m, a[maxn], mx[maxn], ans = 0;
vc<vi> g(maxn);

void dfs(int i = 0, int p = -1) {
  ckmax(mx[i], a[i]);
  if (p != -1 && g[i].size() == 1 && mx[i] <= m) ++ans;
  for (int j : g[i]) {
    if (j == p) continue;
    a[j] *= a[i] + 1;
    ckmax(mx[j], mx[i]);
    dfs(j, i);
  }
}

int main() {
  cin >> n >> m;
  for (int i = 0; i < n; ++i) cin >> a[i];
  for (int i = 1; i < n; ++i) {
    int u, v;
    cin >> u >> v, --u, --v;
    g[u].push_back(v);
    g[v].push_back(u);
  }
  dfs();
  cout << ans << endl;
}