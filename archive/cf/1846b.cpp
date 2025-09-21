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
    vc<string> b(3);
    for (int i = 0; i < 3; ++i) cin >> b[i];
    bool won = false;
    for (int i = 0; i < 3; ++i) {
      if (b[i][0] != '.' && b[i][0] == b[i][1] && b[i][1] == b[i][2]) {
        won = true;
        cout << b[i][0] << endl;
        break;
      }
      if (b[0][i] != '.' && b[0][i] == b[1][i] && b[1][i] == b[2][i]) {
        won = true;
        cout << b[0][i] << endl;
        break;
      }
    }
    if (won) continue;
    if (b[0][0] != '.' && b[0][0] == b[1][1] && b[1][1] == b[2][2]) {
      cout << b[0][0] << endl;
    } else if (b[0][2] != '.' && b[0][2] == b[1][1] && b[1][1] == b[2][0]) {
      cout << b[0][2] << endl;
    } else {
      cout << "DRAW" << endl;
    }
  }
}
