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

static void mu(vi &f, int n) {
  for (int i = 0; i < n; ++i) {
    for (int mask = 0; mask < (1 << n); ++mask) {
      if ((mask >> i) & 1) {
        int smask = mask ^ (1 << i);
        f[smask] += mod - f[mask];
        if (f[smask] >= mod) f[smask] -= mod;
      }
    }
  }
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
  vi f(1 << m);
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
    f[mask] = qpow(k, id);
  }
  mu(f, m);
  for (int mask = 0; mask < (1 << m); ++mask) {
    int pcnt = __builtin_popcount(mask);
    ans[pcnt] += f[mask];
    if (ans[pcnt] >= mod) ans[pcnt] -= mod;
  }
  for (int i = 0; i <= m; ++i) cout << ans[i] << " \n"[i == m];
}
