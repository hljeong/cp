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

const int dx[] = {0, 1, 0, -1}, dy[] = {-1, 0, 1, 0};

bool ib(int i, int j, int n, int m) {
  return 0 <= i && i < n && 0 <= j && j < m;
}

pii dfs(int i, int j, vc<string> &mat, vc<vc<bool>> &vis, int n, int m) {
  pii ret;
  if (mat[i][j] == '.') ++ret.B;
  vis[i][j] = true;
  for (int d = 0; d < 4; ++d) {
    int ni = i + dx[d], nj = j + dy[d];
    if (ib(ni, nj, n, m) && !vis[ni][nj] && mat[ni][nj] != 'X') {
      if ('A' <= mat[ni][nj] && mat[ni][nj] <= 'W') {
        ++ret.A;
        continue;
      }
      pii cret = dfs(ni, nj, mat, vis, n, m);
      ret.A += cret.A;
      ret.B += cret.B;
    }
  }
  return ret;
}

int main() {
  int n, m; cin >> n >> m;
  vc<string> mat(n);
  getline(cin, mat[0]);
  for (int i = 0; i < n; ++i) {
    getline(cin, mat[i]);
  }
  vc<vc<bool>> vis(n, vc<bool>(m));
  int num = 0, bad = 0;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      if (!vis[i][j] && (mat[i][j] == '.' || mat[i][j] == ' ')) {
        pii ret = dfs(i, j, mat, vis, n, m);
        if (ret.B) {
          if (ret.A) ++num;
          else bad += ret.B;
        }
      }
    }
  }
  cout << num << ' ' << bad << endl;
}