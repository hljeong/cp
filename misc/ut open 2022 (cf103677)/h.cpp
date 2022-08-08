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

const int maxn = 1e5 + 5, mod = 1e9 + 7; 
ll e[maxn], ans = 0;
vc<vc<pair<int, ll>>> g(maxn, vc<pair<int, ll>>());

ll qpow(ll a, int b) {
  if (!a) return 0;
  ll ans = 1;
  while (b) {
    if (b & 1) ans = ans * a % mod;
    a = a * a % mod;
    b >>= 1;
  }
  return ans;
}

void dfs(int i = 0, int p = -1) {
  e[i] = 1; 
  for (auto ed : g[i]) {
    int j = ed.A;
    ll pb = ed.B;
    if (j == p) continue;
    dfs(j, i);
    e[i] += e[j] * pb % mod;
    if (e[i] >= mod) e[i] -= mod;
  }
}

void dp(int i = 0, int p = -1) {
  ans += e[i];
  if (ans >= mod) ans -= mod;
  for (auto ed : g[i]) {
    int j = ed.A;
    ll pb = ed.B;
    if (j == p) continue;
    ll oei = e[i], oej = e[j];
    e[i] += mod - e[j] * pb % mod;
    if (e[i] >= mod) e[i] -= mod;
    e[j] += e[i] * (mod + 1 - pb) % mod;
    if (e[j] >= mod) e[j] -= mod;
    dp(j, i);
    e[i] = oei;
    e[j] = oej;
  }
}

int main() {
  int n;
  cin >> n;
  for (int i = 1; i < n; ++i) {
    int u, v;
    ll p, q;
    cin >> u >> v >> p >> q, --u, --v;   
    g[u].push_back({v, p * qpow(q, mod - 2) % mod});
    g[v].push_back({u, (q - p) * qpow(q, mod - 2) % mod});
  }
  dfs();
  dp();
  cout << ans * qpow(n, mod - 2) % mod << endl;
}