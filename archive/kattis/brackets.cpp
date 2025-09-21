#include <bits/stdc++.h>
#define A first
#define B second
#define vc vector
using namespace std;
using ll = long long; using ld = long double;
using vi = vc<int>; using vll = vc<ll>;
using si = set<int>; using sll = set<ll>;
using pii = pair<int, int>; using mii = map<int, int>;
using gr = vc<vi>;

template<class T> bool ckmin(T &a, const T &b) { return b < a ? a = b, 1 : 0; }
template<class T> bool ckmax(T &a, const T &b) { return a < b ? a = b, 1 : 0; }

int main() {
  string s; cin >> s;
  int n = s.length();
  vi p(n), b(n + 1);
  vc<pii> tmp(n);
  vc<vi> mns(n + 2, vi(n + 2, 8000)), mxs(n + 2, vi(n + 2, -8000));
  for (int i = 0; i < n; ++i) {
    p[i] = s[i] == '(' ? 1 : -1;
    b[i + 1] = b[i] + p[i];
  }
  for (int i = 0; i < n; ++i) {
    for (int j = i; j < n; ++j) {
      mns[i + 1][j + 1] = min(mns[i + 1][j - 1 + 1], b[j + 1]);
      mxs[i + 1][j + 1] = max(mxs[i + 1][j - 1 + 1], b[j + 1]);
    }
  }
  bool good = (b[n] == 0) && (mns[0 + 1][n - 1 + 1] >= 0);
  for (int i = 0; i < n; ++i) {
    for (int j = i; j < n; ++j) {
      int d = b[j + 1] - b[i];
      bool good_before = mns[0 + 1][i - 1 + 1] >= 0;
      bool good_during = b[i] >= mxs[i + 1][j + 1] - b[i];
      bool good_after = mns[j + 1 + 1][n - 1 + 1] >= 2 * d;
      bool good_bal = b[n] == 2 * d;
      // cout << i << ' ' << j << ' ' << good_before << ' ' << good_during << ' ' << good_after << ' ' << good_bal << endl;
      if (good |= good_before && good_during && good_after && good_bal) break;
    }
    if (good) break;
  }
  cout << (good ? "possible" : "impossible") << endl;
}
