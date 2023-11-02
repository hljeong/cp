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
char tmp[1000005];

struct dsu {
  vi par, sz, lst;

  dsu(int n) : par(vi(n)), sz(vi(n)), lst(vi(n)) {
    for (int i = 0; i < n; ++i) { par[i] = i; sz[i] = 1; lst[i] = i; }
  }

  int find(int i) {
    return par[i] == i ? i : (par[i] = find(par[i]));
  }

  bool combine(int i, int j) {
    i = find(i); j = find(j);
    if (i != j) {
      par[j] = i; sz[i] += sz[j];
      lst[i] = lst[j];
    }
    return i != j;
  }
};

// use dsu to keep track of representative of each chunk and the last string of each chunk
int main() {
  // cin.tie(0) -> sync_with_stdio(0);

  int n; scanf("%d", &n);
  vc<string> m(n);
  for (int i = 0; i < n; ++i) {
    scanf("%s", tmp);
    m[i] = tmp;
  }
  dsu d(n);
  vi nxt(n, -1);
  vi vis(n);
  for (int i = 0; i < n - 1; ++i) {
    int a, b; scanf("%d %d", &a, &b); --a; --b;
    nxt[d.lst[d.find(a)]] = b;
    d.combine(a, b);
    vis[b] = 1;
  }
  int start = -1;
  for (int i = 0; i < n; ++i) {
    if (!vis[i]) {
      start = i;
      break;
    }
  }
  while (start != -1) {
    printf("%s", m[start].c_str());
    start = nxt[start];
  }
  printf("\n");
}
