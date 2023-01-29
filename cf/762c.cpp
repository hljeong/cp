#include <bits/stdc++.h>
#define A first
#define B second
#define vc vector
#define pb push_back
using namespace std;
using ll = long long; using ld = long double;
using vi = vc<int>; using vll = vc<ll>;
using si = set<int>; using sll = set<ll>;
using pii = pair<int, int>; using pll = pair<ll, ll>;
using mii = map<int, int>;

template<class T> bool ckmin(T &a, const T &b) { return b < a ? a = b, 1 : 0; }
template<class T> bool ckmax(T &a, const T &b) { return a < b ? a = b, 1 : 0; }

const int inf = 1e9 + 7;
const int mod = inf;
const ll infll = 0x3f3f3f3f3f3f3f3fll;

template<class T> T minst(function<bool(T)> pred, T i, T j) {
  T ret = j + 1;
  for (T l = i, r = j, m; l <= r; ) {
    if (pred(m = l + (r - l) / 2)) r = (ret = m) - 1;
    else l = m + 1;
  }
  return ret;
}

int main() {
  string a, b; cin >> a >> b;
  int n = a.length(), m = b.length();
  vi p(m, n), s(m, -1);
  for (int ai = 0, bi = 0; ai < n; ++ai) {
    if (bi < m && a[ai] == b[bi]) p[bi++] = ai;
  }
  for (int ai = n - 1, bi = m - 1; ai >= 0; --ai) {
    if (bi >= 0 && a[ai] == b[bi]) s[bi--] = ai;
  }
  function<bool(int)> ppred = [&](int k) {
    return s[k] >= 0;
  };
  int l = -1, r = minst(ppred, 0, m - 1);
  int del = r - l - 1;
  for (int i = 0; i < m && p[i] < n; ++i) {
    function<bool(int)> pred = [&](int k) {
      return s[k] > p[i];
    };
    int j = minst(pred, i + 1, m - 1);
    if (ckmin(del, j - i - 1)) {
      l = i; r = j;
    }
  }
  // for (int i = 0; i < m; ++i) cout << p[i] << " \n"[i == m - 1];
  // for (int i = 0; i < m; ++i) cout << s[i] << " \n"[i == m - 1];
  for (int ai = 0, bi = (l == -1 ? r : 0); ai < n; ++ai) {
    if (a[ai] == b[bi]) {
      cout << a[ai];
      if (bi == l) bi = r;
      else ++bi;
    }
  }
  if (del == m) cout << '-';
  cout << endl;
}
