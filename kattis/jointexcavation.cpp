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

const int maxn = 2e5 + 5; 
vc<vi> g(maxn, vi());
set<int> a, b;
stack<int> pt;
vc<bool> v(maxn);

bool dfs(int i = 0) {
  v[i] = true;
  pt.push(i);
  a.erase(i);
  if (a.size() == b.size()) return true;
  for (int j : g[i]) {
    if (v[j]) continue;
    if (dfs(j)) return true;
    b.insert(j);
    if (a.size() == b.size()) return true;
  }
  pt.pop();
  return false;
}

int main() {
  int n, m;
  cin >> n >> m; 
  for (int i = 0; i < n; ++i) a.insert(i);
  for (int i = 0; i < m; ++i) {
    int u, v;
    cin >> u >> v, --u, --v;
    g[u].push_back(v);
    g[v].push_back(u);
  }
  dfs();
  cout << pt.size() << ' ' << (n - pt.size()) / 2 << endl;
  while (pt.size()) {
    cout << pt.top() + 1 << ' ';
    pt.pop();
  }
  cout << endl;
  for (int i : a) cout << i + 1 << ' ';
  cout << endl;
  for (int i : b) cout << i + 1 << ' ';
  cout << endl;
}