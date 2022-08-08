#include <bits/stdc++.h>
#define A first
#define B second
#define vc vector
using namespace std;
using ll = long long;
using ld = long double;
using vi = vc<int>;
using vll = vc<ll>;
using pii = pair<int, int>;

template<class T> bool ckmin(T& a, const T& b) { return b < a ? a = b, 1 : 0; }
template<class T> bool ckmax(T& a, const T& b) { return a < b ? a = b, 1 : 0; }

const int maxn = 305;
char mp[maxn][maxn];

void upd(int &i, int &j, int dir) {
  if (dir == 0) --i;
  else if (dir == 1) ++j;
  else if (dir == 2) ++i;
  else --j;
}

bool ib(int i, int j, int m, int n) {
  return 0 <= i && i < m && 0 <= j && j < n;
}

int main() {
  int m, n, si = -1, sj = -1;
  cin >> m >> n;
  for (int i = 0; i < m; ++i) {
    string s;
    cin >> s;
    for (int j = 0; j < n; ++j) {
      mp[i][j] = s[j];
      if (mp[i][j] == 'O') {
        si = i;
        sj = j;
      }
    }
  }
  int dir = -1;
  if (si == m - 1) {
    dir = 0;
  } else if (si == 0) {
    dir = 2;
  } else if (sj == n - 1) {
    dir = 3;
  } else {
    dir = 1;
  }
  upd(si, sj, dir);
  while (ib(si, sj, m, n) && mp[si][sj] != '#') {
    if (mp[si][sj] == '.' || mp[si][sj] == '@') {
      mp[si][sj] = '@';
      upd(si, sj, dir);
    } else if (mp[si][sj] == '/') {
      if (dir == 0) dir = 1;
      else if (dir == 1) dir = 0;
      else if (dir == 2) dir = 3;
      else dir = 2;
      upd(si, sj, dir);
    } else {
      if (dir == 0) dir = 3;
      else if (dir == 3) dir = 0;
      else if (dir == 2) dir = 1;
      else dir = 2;
      upd(si, sj, dir);
    }
  }
  for (int i = 0; i < m; ++i) {
    for (int j = 0; j < n; ++j) {
      cout << mp[i][j];
    }
    cout << endl;
  }
}