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

// prefix sums
int main() {
  cin.tie(0) -> sync_with_stdio(0);

  int r, q; cin >> r >> q;
  vc<vll> row(5005, vll(5005)), col(5005, vll(5005)), s(5005, vll(5005));
  vc<vll> prow(5005, vll(5005)), pcol(5005, vll(5005));
  for (int i = 0; i < r; ++i) {
    int x, y, w, h, c; cin >> x >> y >> w >> h >> c;
    x += 2250; y += 2250;
    row[x][y] += c;
    row[x + w][y] -= c;
    row[x][y + h] += c;
    row[x + w][y + h] -= c;
    col[x][y] += c;
    col[x][y + h] -= c;
    col[x + w][y] += c;
    col[x + w][y + h] -= c;
  }
  for (int i = 0; i <= 4500; ++i) {
    for (int j = 1; j <= 4500; ++j) {
      row[j][i] += row[j - 1][i];
      col[i][j] += col[i][j - 1];
    }
  }
  for (int i = 0; i <= 4500; ++i) {
    for (int j = 0; j <= 4500; ++j) {
      prow[i + 1][j] = prow[i][j] + row[i][j];
      pcol[i][j + 1] = pcol[i][j] + col[i][j];
    }
  }
  for (int i = 1; i <= 4500; ++i) {
    s[i][0] = s[i - 1][0] + row[i - 1][0];
    s[0][i] = s[0][i - 1] + col[0][i - 1];
  }
  for (int i = 1; i <= 4500; ++i) {
    for (int j = 1; j <= 4500; ++j) {
      s[i][j] = s[i - 1][j] + s[i][j - 1] - s[i - 1][j - 1] + row[i - 1][j] + col[i][j - 1];
    }
  }
  /*
  for (int i = 2249; i <= 2256; ++i) {
    for (int j = 2249; j <= 2256; ++j) {
      cout << prow[i][j] << " \n"[j == 2256];
    }
  }
  */
  while (q--) {
    int x, y, w, h; cin >> x >> y >> w >> h;
    x += 2250; y += 2250;
    cout << (s[x + w][y + h] - s[x][y + h] - s[x + w][y] + s[x][y] + prow[x + w][y] - prow[x][y] + pcol[x][y + h] - pcol[x][y]) << endl;
  }
}
