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

// start from max deg and try to connect w every vertex
int main() {
  cin.tie(0) -> sync_with_stdio(0);

  int v; cin >> v;
  vc<pi> d(v); for (int i = 0; i < v; ++i) {
    cin >> d[i].A;
    d[i].B = i;
  }
  sort(d.begin(), d.end());
  reverse(d.begin(), d.end());
  vc<pi> ret;
  int j = 1;
  for (int i = 0; i < v; ++i) {
    for (ckmax(j, i + 1); j < v && d[i].A; ++j) {
      if (!d[j].A) break;
      --d[i].A; --d[j].A;
      ret.pb({ d[i].B, d[j].B });
    }
    if (d[i].A) return !printf("IMPOSSIBLE\n");
  }
  cout << "POSSIBLE" << endl;
  for (const auto &[u, v] : ret) {
    cout << (u + 1) << ' ' << (v + 1) << endl;
  }
}
