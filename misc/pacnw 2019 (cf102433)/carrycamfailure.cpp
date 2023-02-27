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

bool check(vi &ret, vi &tgt) {
  reverse(ret.begin(), ret.end());
  reverse(tgt.begin(), tgt.end());
  for (int i = 0; i < ret.size(); ++i) {
    int p = 0;
    for (int j = 0; j <= i; ++j) {
      p += ret[j] * ret[i - j];
    }
    if (p % 10 != tgt[i]) {
      reverse(tgt.begin(), tgt.end());
      reverse(ret.begin(), ret.end());
      return false;
    }
  }
  reverse(tgt.begin(), tgt.end());
  reverse(ret.begin(), ret.end());
  return true;
}

bool solve(int i, vi &ret, vi &tgt) {
  if (i == ret.size()) return check(ret, tgt);
  for (int j = 0; j < 10; ++j) {
    ret[i] = j;
    int p = 0;
    for (int k = 0; k <= i; ++k) {
      p += ret[k] * ret[i - k];
    }
    if (p % 10 == tgt[i] && solve(i + 1, ret, tgt)) return true;
  }
  return false;
}

int main() {
  string ns; cin >> ns;
  int l = ns.length();
  vi n(l);
  for (int i = 0; i < l; ++i) n[i] = ns[i] - '0';
  if (!(l & 1)) return !printf("-1\n");
  vi ret((l + 1) / 2);
  for (int i = 0; i < 10; ++i) {
    if (i * i % 10 == n[0]) {
      ret[0] = i;
      if (solve(1, ret, n)) {
        for (int i = 0; i < ret.size(); ++i) cout << ret[i] << (i == ret.size() - 1 ? "\n" : "");
        return 0;
      }
    }
  }
  cout << -1 << endl;
}
