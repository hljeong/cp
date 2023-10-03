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

int get_min(vi &f, int m) {
  int cnt1 = 0, cnt2 = 0;
  for (int i = 0; i < m; ++i) {
    if (f[i]) {
      if (i && f[i - 1] && cnt2 < m / 4) {
        --cnt1;
        ++cnt2;
        f[i] = 0;
      } else ++cnt1;
    }
  }
  return cnt1 + cnt2;
}
int get_max(vi &f, int m) {
  int ret = 0, run = 0, bad = 0;
  for (int i = 0; i < m; ++i) {
    ret += f[i];
    if (i && f[i] && f[i - 1]) {
      bad += run / 2;
      run = 0;
    }
    ++run;
  }
  bad += run / 2;
  bad = max(0, m / 4 - bad);
  return ret - bad;
}

int main() {
  cin.tie(0) -> sync_with_stdio(0);

  int n, m; cin >> n >> m;
  vc<vi> b(n, vi(m)), bf(n, vi(m));
  for (int i = 0; i < n; ++i) {
    string s; cin >> s;
    for (int j = 0; j < m; ++j) bf[i][j] = b[i][j] = s[j] - '0';
  }
  int ret1 = 0, ret2 = 0;
  for (int i = 0; i < n; ++i) {
    ret1 += get_min(b[i], m);
    ret2 += get_max(bf[i], m);
  }
  cout << ret1 << ' ' << ret2 << endl;
}
