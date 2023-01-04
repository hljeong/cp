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
template<class T> bool ckmax(T &a, const T &b) { return a < b ? a = b, 1 : 0; }

const int inf = 1e9 + 7;
const int mod = inf;
const ll infll = 0x3f3f3f3f3f3f3f3fll;

int main() {
  int n, l; cin >> n >> l;
  vc<string> st(n);
  for (int i = 0; i < n; ++i) {
    cin >> st[i];
  }
  vc<vi> d(n - 1, vi(l)), nxt1(n - 1, vi(l, 2 * l)), nxtm1(n - 1, vi(l, 2 * l));
  for (int i = 0; i < n - 1; ++i) {
    for (int j = 0; j < l; ++j) {
      d[i][j] = st[i][j] == st[i + 1][j] ? 0 : (st[i][j] > st[i + 1][j] ? -1 : 1);
    }
    int cnxt1 = 2 * l, cnxtm1 = 2 * l;
    for (int j = l - 1; j >= 0; --j) {
      if (d[i][j] == 1) cnxt1 = j;
      else if (d[i][j] == -1) cnxtm1 = j;
      nxt1[i][j] = cnxt1;
      nxtm1[i][j] = cnxtm1;
    }
  }
  int ret = l, ind = 1;
  for (int i = 0; i < l; ++i) {
    int cret = i;
    bool good = true;
    for (int j = 0; j < n - 1; ++j) {
      if (nxtm1[j][i] < nxt1[j][i]) {
        good = false;
        break;
      }
      ckmax(cret, nxt1[j][i]);
    }
    if (good && ckmin(ret, cret - i + 1)) ind = i + 1;
  }
  cout << ind << ' ' << (ind + ret - 1) << endl;
}
