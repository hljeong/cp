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

int main() {
  int n, m; cin >> n >> m;
  vi ord(n), ii(n);
  for (int i = 0; i < n; ++i) ord[i] = ii[i] = i;
  for (int i = 0; i < m; ++i) {
    string ti, tj; cin >> ti >> tj;
    ti = ti.substr(1, ti.length() - 1);
    tj = tj.substr(1, tj.length() - 1);
    int u = stoi(ti) - 1, v = stoi(tj) - 1;
    // cout << u << ", " << v << endl;
    // cout << ii[u] << ", " << ii[v] << endl;
    if (ii[v] < ii[u]) {
      vi nord;
      for (int j = 0; j <= ii[u]; ++j) if (j != ii[v]) nord.pb(ord[j]);
      nord.pb(v);
      for (int j = ii[u] + 1; j < n; ++j) nord.pb(ord[j]);
      ord = nord;
      for (int j = 0; j < n; ++j) ii[ord[j]] = j;
    }
    // for (int i = 0; i < n; ++i) cout << 'T' << (ord[i] + 1) << " \n"[i == n - 1];
  }
  for (int i = 0; i < n; ++i) cout << 'T' << (ord[i] + 1) << " \n"[i == n - 1];
}