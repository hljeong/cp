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

int main() {
  cin.tie(0) -> sync_with_stdio(0);

  int T; cin >> T;
  while (T--) {
    int n, k; cin >> n >> k;
    string s, t; cin >> s >> t;
    vc<multiset<char>> ss(n), ts(n);
    dsu d(n);
    for (int i = 0; i < n; ++i) {
      if (i + k < n) d.combine(i, i + k);
      if (i + k + 1 < n) d.combine(i, i + k + 1);
    }
    for (int i = 0; i < n; ++i) {
      ss[d.find(i)].insert(s[i]);
      ts[d.find(i)].insert(t[i]);
    }
    bool good = true;
    for (int i = 0; i < n; ++i) {
      if (ss[i] != ts[i]) good = false;
    }
    cout << (good ? "YES" : "NO") << endl;
  }
}
