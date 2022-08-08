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

template<class T> bool ckmin(T &a, const T &b) { return b < a ? a = b, 1 : 0; }
template<class T> bool ckmax(T &a, const T &b) { return a < b ? a = b, 1 : 0; }

const int maxn = 2e5 + 5, mod = 1e9 + 7;

ll fact[maxn], ifact[maxn];
int n, k;

ll qpow(ll a, ll b) {
  if (!a) return 0;
  ll ans = 1;
  while (b) {
    if (b & 1) {
      ans *= a;
      ans %= mod;
    }
    a *= a;
    a %= mod;
    b >>= 1;
  }
  return ans;
}

ll inv(ll x) {
  return qpow(x, mod - 2);
}

void dfs(vc<vi> &g, vll &sz, int i = 0, int p = -1) {
  sz[i] = 1;
  for (int j : g[i]) {
    if (j == p) continue;
    dfs(g, sz, j, i);
    sz[i] += sz[j];
  }
}

ll choose(int m) {
  if (k > m) return 0;
  ll ans = fact[m] * ifact[k];
  ans %= mod;
  ans *= ifact[m - k];
  ans %= mod;
  return ans;
}

ll solve(vc<vi> &g, vll &sz, int i = 0, int p = -1) {
  ll ans = 0, s = 0;
  for (int j : g[i]) {
    s += choose(sz[j]);
    s %= mod;
  }
  ans += n * ((choose(n) - s + mod) % mod) % mod;
  for (int j : g[i]) {
    ans += sz[j] * (n - sz[j]) % mod * (((choose(n - sz[j]) - s + mod) % mod + choose(sz[j])) % mod) % mod;
    ans %= mod;
  }
  for (int j : g[i]) {
    if (j == p) continue;
    sz[i] -= sz[j];
    sz[j] += sz[i];
    ans += solve(g, sz, j, i);
    ans %= mod;
    sz[j] -= sz[i];
    sz[i] += sz[j];
  }
  return ans;
}

int main() {
  fact[0] = fact[1] = ifact[0] = ifact[1] = 1;
  for (int i = 2; i < maxn; ++i) {
    fact[i] = i * fact[i - 1];
    fact[i] %= mod;
    ifact[i] = inv(fact[i]);
  }
  cin >> n >> k;
  vc<vi> g(n);
  for (int i = 1; i < n; ++i) {
    int u, v; cin >> u >> v; --u; --v;
    g[u].push_back(v);
    g[v].push_back(u);
  }
  vll sz(n);
  dfs(g, sz);
  cout << solve(g, sz) << endl;
}