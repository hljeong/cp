#include <bits/stdc++.h>
#define A first
#define B second
#define vc vector
#define pb push_back
#define endl '\n'
using namespace std;
using ll = long long; using ld = long double;
using vi = vc<int>; using vll = vc<ll>;
using si = set<int>; using sll = set<ll>;
using pi = pair<int, int>; using pll = pair<ll, ll>;
using qi = queue<int>; using mi = map<int, int>;

template<class T> bool ckmin(T &a, const T &b) { return b < a ? a = b, 1 : 0; }
template<class T> bool ckmax(T &a, const T &b) { return a < b ? a = b, 1 : 0; }

const int inf = 1e9 + 7;
const int mod = inf;
const ll infll = 0x3f3f3f3f3f3f3f3fll;

struct dsu {
  vi par, sz;

  dsu(int n) : par(vi(n)), sz(vi(n)) {
    for (int i = 0; i < n; ++i) { par[i] = i; sz[i] = 1; }
  }

  int find(int i) {
    return par[i] == i ? i : (par[i] = find(par[i]));
  }

  bool combine(int i, int j) {
    i = find(i); j = find(j);
    if (i != j) {
      if (sz[i] < sz[j]) swap(i, j);
      par[j] = i; sz[i] += sz[j];
    }
    return i != j;
  }
};

// dsu
int main() {
  cin.tie(0) -> sync_with_stdio(0);

  int cs = 1;
  int m, n;
  while (cin >> m) {
    cin >> n;
    vc<string> mp(m);
    dsu d(m * n + 1);
    for (int i = 0; i < m; ++i) {
      cin >> mp[i];
      for (int j = 0; j < n; ++j) {
        if (mp[i][j] == '#') {
          d.combine(i * n + j, m * n);
        } else {
          if (i && mp[i - 1][j] == '-') d.combine(i * n + j, (i - 1) * n + j);
          if (j && mp[i][j - 1] == '-') d.combine(i * n + j, i * n + (j - 1));
        }
      }
    }
    int ret = -1;
    for (int i = 0; i <= m * n; ++i) {
      if (d.find(i) == i) ++ret;
    }
    cout << "Case " << (cs++) << ": " << ret << endl;
  }
}
