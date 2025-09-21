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
const bool interactive = false;

int n, m, lgm;

inline int get(ll grid, int i) {
  return (grid >> (i * lgm)) & ((1 << lgm) - 1);
}

inline void st(ll &grid, int i, ll x) {
  grid &= (~0) - (((1L << lgm) - 1) << (i * lgm));
  grid |= x << (i * lgm);
}

void gen(int cur, int l, ll grid, map<ll, bool> &nim, set<pii> &ret) {
  if (cur == n) {
    int g0 = get(grid, 0);
    if (!g0 || g0 == 1 && (n == 1 || !get(grid, 1))) return;
    bool fin = get(grid, n - 1) == m;
    bool exit = false;
    ll backtrack = 0;
    ll curgrid = grid;
    // for (int i = 0; i < n; ++i) cout << get(grid, i) << " \n"[i == n - 1];
    for (int i = 0; i < n; ++i) {
      int gridi = get(grid, i);
      for (int j = !i; j < gridi; ++j) {
        for (int k = i; k < n; ++k) {
          st(backtrack, k, max(0, get(grid, k) - j));
        }
        grid -= backtrack;
        // cout << "  ";
        // for (int i = 0; i < n; ++i) cout << get(grid, i) << " \n"[i == n - 1];
        if (!nim[grid]) {
          nim[curgrid] = true;
          if (fin) ret.insert({ i + 1, j + 1 });
          exit = true;
        }
        grid += backtrack;
        backtrack = 0;
        if (exit) return;
      }
    }
    return;
  }
  for (int j = l; j >= 0; --j) {
    for (int k = cur; k < n; ++k) {
      st(grid, k, l - j);
    }
    gen(cur + 1, l - j, grid, nim, ret);
  }
}

int main() {
  if (interactive) {
    cin >> n >> m;
    int cm = m;
    lgm = 0;
    while (cm) {
      ++lgm;
      cm >>= 1;
    }
    ll grid = 0;
    for (int k = 0; k < n; ++k) st(grid, k, m);
    map<ll, bool> nim;
    set<pii> ret;
    gen(0, m, grid, nim, ret);
    for (const auto &e : ret) cout << "(" << e.A << ", " << e.B << ") ";
    cout << endl;
  } else {
    for (int i = 1; i <= 12 ; ++i) {
      for (int j = 1; j <= 12; ++j) {
        n = i;
        m = j;
        int cm = m;
        lgm = 0;
        while (cm) {
          ++lgm;
          cm >>= 1;
        }
        ll grid = 0;
        for (int k = 0; k < n; ++k) st(grid, k, m);
        map<ll, bool> nim;
        set<pii> ret;
        gen(0, m, grid, nim, ret);
        cout << i << " x " << j << ": ";
        for (const auto &e : ret) cout << "(" << e.A << ", " << e.B << ") ";
        cout << endl;
      }
    }
  }
}
