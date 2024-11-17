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

bool p(vi& a) {
  int n = a.size();
  for (int i = 0; i < n / 2; ++i) {
    if (a[i] != a[n - i - 1]) return false;
  }
  return true;
}

// just do it: there are like 3 of them or smth
int main() {
  cin.tie(0) -> sync_with_stdio(0);

  int a, b, k; cin >> a >> b >> k;
  int ret = 0;

  for (int x = a; x <= b; ++x) {
    int good = 1;
    for (int i = 2; i <= k; ++i) {
      int xx = x;
      vi bi;
      while (xx) {
        bi.pb(xx % i);
        xx /= i;
      }
      if (!p(bi)) {
        good = 0;
        break;
      }
    }
    ret += good;
  }
  cout << ret << endl;
}