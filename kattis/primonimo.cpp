#include <bits/stdc++.h>
#define A first
#define B second
#define vc vector
#define pb push_back
using namespace std;
using ll = long long; using ld = long double;
using vi = vc<int>; using vll = vc<ll>;
using si = set<int>; using sll = set<ll>;
using pii = pair<int, int>; using mii = map<int, int>;

template<class T> bool ckmin(T &a, const T &b) { return b < a ? a = b, 1 : 0; }
template<class T> bool ckmax(T &a, const T &b) { return b > a ? a = b, 1 : 0; }

const int inf = 1e9 + 7;
const int mod = inf;
const ll infll = 0x3f3f3f3f3f3f3f3fll;

bool gauss(vc<vi> &c, int p, vi &inv) {
  int n = c.size();
  for (int i = 0; i < n - 1; ++i) {
    if (!c[i][i]) {
      for (int j = i + 1; j < n; ++j) {
        if (c[j][i]) {
          swap(c[i], c[j]);
          break;
        }
      }
    }
    for (int j = i + 1; j < n; ++j) {
      int mul = c[j][i] * inv[c[i][i]] % p;
      c[j][i] = 0;
      for (int k = i + 1; k <= n; ++k) {
        c[j][k] = (c[j][k] - c[i][k] * mul % p + p) % p;
      }
    }
  }
  for (int i = 0; i < n; ++i) {
    bool nonzero = false;
    for (int j = 0; j < n; ++j) nonzero |= c[i][j];
    if (!nonzero && c[i][n]) return false;
  }

  // cout << endl;
  // for (int i = 0; i < n; ++i) for (int j = 0; j <= n; ++j) cout << c[i][j] << " \n"[j == n];
  for (int i = n - 1; i > 0; --i) {
    for (int j = i - 1; j >= 0; --j) {
      int mul = c[j][i] * inv[c[i][i]] % p;
      for (int k = 0; k <= n; ++k) {
        c[j][k] = (c[j][k] - c[i][k] * mul % p + p) % p;
      }
    }
  }
  for (int i = 0; i < n; ++i) c[i][n] = (c[i][n] * inv[c[i][i]]) % p;
  return true;
}

int toi(int i, int j, int n, int m) {
  return i * m + j;
}

int main() {
  int n, m, p; cin >> n >> m >> p;
  vc<vi> a(n, vi(m));
  for (int i = 0; i < n; ++i) for (int j = 0; j < m; ++j) cin >> a[i][j];
  vi inv(p);
  for (int i = 1; i < p; ++i) {
    for (int j = 1; j < p; ++j) if (i * j % p == 1) inv[i] = j;
  }
  // for (int i = 0; i < p; ++i) cout << inv[i] << " \n"[i == p - 1];
  vc<vi> c(n * m, vi(n * m + 1));
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      for (int k = 0; k < n; ++k) {
        c[toi(i, j, n, m)][toi(k, j, n, m)] = 1;
      }
      for (int k = 0; k < m; ++k) {
        c[toi(i, j ,n, m)][toi(i, k, n, m)] = 1;
      }
      c[toi(i, j, n, m)][n * m] = p - a[i][j];
    }
  }
  // for (int i = 0; i < n * m; ++i) for (int j = 0; j <= n * m; ++j) cout << c[i][j] << " \n"[j == n * m];
  if (!gauss(c, p, inv)) {
    cout << -1 << endl;
  } else {
    vi ret;
    // cout << endl;
    // for (int i = 0; i < n * m; ++i) for (int j = 0; j <= n * m; ++j) cout << c[i][j] << " \n"[j == n * m];
    for (int i = 0; i < n * m; ++i) for (int j = 0; j < c[i][n * m]; ++j) ret.pb(i + 1);
    cout << ret.size() << endl;
    for (int i = 0; i < ret.size(); ++i) cout << ret[i] << " \n"[i == ret.size() - 1];
  }
}