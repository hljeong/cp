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

const int mod = 1e9 + 9;

int qpow(int b, int e) {
  int ans = 1;
  while (e) {
    if (e & 1) {
      ans = (int) ((ll) ans * b % mod);
    }
    b = (int) ((ll) b * b % mod);
    e >>= 1;
  }
  return ans;
}

using dsu = pair<vi, vi>;

int find(dsu &d, int i) {
  return d.A[i] == i ? i : (d.A[i] = find(d, d.A[i]));
}

bool combine(dsu &d, int i, int j) {
  i = find(d, i); j = find(d, j);
  if (i != j) {
    if (d.B[i] < d.B[j]) swap(i, j);
    d.A[j] = i; d.B[i] += d.B[j];
    return true;
  }
  return false;
}

int main() {
  int n, m, k; cin >> n >> m >> k;
  vc<vi> g(n, vi());
  vc<pii> e(m);
  for (int i = 0; i < m; ++i) {
    int u, v; cin >> u >> v; --u; --v;
    g[u].push_back(v);
    g[v].push_back(u);
    e[i].A = u;
    e[i].B = v;
  }
  vi ans(m + 1);
  for (int mask = 0; mask < (1 << m); ++mask) {
    vi par(n), sz(n);
    dsu d = {par, sz};
    for (int i = 0; i < n; ++i) {
      d.A[i] = i;
      d.B[i] = 1;
    }
    for (int i = 0; i < m; ++i) {
      if ((mask & (1 << i))) combine(d, e[i].A, e[i].B);
    }
    int id = 0;
    map<int, int> mp;
    for (int i = 0; i < n; ++i) {
      if (mp.find(find(d, i)) == mp.end()) {
        mp[find(d, i)] = id++;
      }
    }
    int pcnt = __builtin_popcount(mask);
    ans[pcnt] += qpow(k, id);
    if (ans[pcnt] >= mod) ans[pcnt] -= mod;
  }
  int fact[m + 1], ifact[m + 1];
  fact[0] = fact[1] = ifact[0] = ifact[1] = 1;
  for (int i = 2; i <= m; ++i) {
    fact[i] = (int) (((ll) i * fact[i - 1]) % mod);
    ifact[i] = qpow(fact[i], mod - 2);
  }
  for (int i = 0; i <= m; ++i) {
    for (int j = i + 1; j <= m; ++j) {
      if ((j - i) & 1) {
        ans[i] += mod;
        ans[i] -= (int) ((((ll) fact[j] * ifact[i] % mod) * ifact[j - i] % mod) * ans[j] % mod);
        if (ans[i] >= mod) ans[i] -= mod;
      } else {
        ans[i] += (int) ((((ll) fact[j] * ifact[i] % mod) * ifact[j - i] % mod) * ans[j] % mod);
        if (ans[i] >= mod) ans[i] -= mod;
      }
    }
  }
  for (int i = 0; i <= m; ++i) cout << ans[i] << " \n"[i == m];
}
