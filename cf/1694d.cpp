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

// tot, use?, give
pair<int, pair<int, ll>> dfs(vc<vi> &g, int i, int p, vi &l, vi &r) {  
  ll take = 0;
  int ans = 0;
  for (int j : g[i]) {
    if (j == p) continue;
    auto pr = dfs(g, j, i, l, r);
    take += pr.B.B;
    ans += pr.A;
  }
  ll give = max((ll) l[i], min((ll) r[i], take));
  int use = take >= l[i] ? 0 : 1;
  return {ans + use, {use, take < l[i] ? r[i] : min((ll) r[i], take)}};
}

int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    vc<vi> g(n, vi());
    vi l(n), r(n);
    for (int i = 1; i < n; ++i) {
      int p;
      cin >> p;
      --p;
      g[i].push_back(p);
      g[p].push_back(i);
    }
    for (int i = 0; i < n; ++i) {
      cin >> l[i] >> r[i]; 
    }
    cout << dfs(g, 0, -1, l, r).A << endl;
  }
}