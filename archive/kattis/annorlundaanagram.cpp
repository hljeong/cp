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

// bad only if every char is the same
// choose char c with frequenct <= n / 2
// make the (n / 2 - 1)-st char c and use all of c in the first half
int main() {
  cin.tie(0) -> sync_with_stdio(0);

  string s; cin >> s;
  int n = s.length();
  bool bad = true;
  for (int i = 1; i < n; ++i) {
    if (s[i] != s[0]) {
      bad = false;
      break;
    }
  }
  if (bad) {
    cout << -1 << endl;
    return 0;
  }
  mi f;
  for (int i = 0; i < n; ++i) ++f[s[i]];
  char ch = 0;
  int chcnt = 0;
  for (const auto &[c, cnt] : f) {
    if (cnt <= n / 2) {
      chcnt = cnt;
      ch = c;
      break;
    }
  }
  string ret(n, 0);
  for (int i = 0; i < chcnt - 1; ++i) {
    ret[i] = ch;
  }
  ret[n / 2 - 1] = ch;
  int ind = 0;
  for (int i = chcnt - 1; i < n / 2 - 1; ++i) {
    while (s[ind] == ch) ++ind;
    ret[i] = s[ind];
    ++ind;
  }
  for (int i = n / 2; i < n; ++i) {
    while (s[ind] == ch) ++ind;
    ret[i] = s[ind];
    ++ind;
  }
  cout << ret << endl;
}
