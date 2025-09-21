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

int main() {
  cin.tie(0) -> sync_with_stdio(0);

  int t; cin >> t;
  while (t--) {
    int n, m, h; cin >> n >> m >> h;
    vc<vi> t(n, vi(m));
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < m; ++j) {
        cin >> t[i][j];
      }
      sort(t[i].begin(), t[i].end());
    }
    vc<pair<int, pll>> score(n);
    for (int i = 0; i < n; ++i) {
      ll cur = 0;
      for (int j = 0; j < m; ++j) {
        cur += t[i][j];
        if (cur > h) break;
        --score[i].A;
        score[i].B.A += cur;
      }
      score[i].B.B = i;
    }
    sort(score.begin(), score.end());
    for (int i = 0; i < n; ++i) {
      if (score[i].B.B == 0) {
        cout << i + 1 << endl;
        break;
      }
    }
  }
}
