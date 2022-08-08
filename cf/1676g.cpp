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

pii dfs(vc<vi> &g, string &s, int i, int p) {
  pii ans = make_pair(s[i] == 'B' ? -1 : 1, 0);
  for (int j : g[i]) {
    if (j != p) {
      pii x = dfs(g, s, j, i);
      ans.A += x.A;
      ans.B += x.B;
    }
  }
  if (!ans.A) ++ans.B;
  return ans;
}

int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    vc<vi> g(n);
    for (int i = 1; i < n; ++i) {
      int p;
      cin >> p, --p;
      g[i].push_back(p);
      g[p].push_back(i);
    }
    string s;
    cin >> s;
    cout << dfs(g, s, 0, -1).B << endl;
  }
}