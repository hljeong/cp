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

int main() {
  int n, w; cin >> n >> w;
  gr g(n + 1, vi());
  vi c(n + 1), u(n + 1);
  c[0] = w;
  for (int i = 1; i <= n; ++i) {
    int d; cin >> d >> c[i] >> u[i];
    g[d].push_back(i);
  }
  ll ans = w;
  function<void(int, int, ll)> solve = [&](int i, int p, ll need) {
    need = max(need, (ll) c[i]) - u[i];
    ckmin(ans, need);
    for (int j : g[i]) {
      if (j == p) continue;
      solve(j, i, need);
    }
  };
  solve(0, -1, 0);
  cout << ans << endl;
}
