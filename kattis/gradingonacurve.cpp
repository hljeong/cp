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

const int inf = 1e9 + 7;
const int mod = inf;

template<class T> T minst(function<bool(T)> pred, T i, T j) {
  T ret = j + 1;
  for (T l = i, r = j, m; l <= r; ) {
    if (pred(m = l + (r - l) / 2)) r = (ret = m) - 1;
    else l = m + 1;
  }
  return ret;
}

int main() {
  int n, t; cin >> n >> t;
  vi g(n); for (int i = 0; i < n; ++i) cin >> g[i];
  function<bool(int)> pred = [&](int k) {
    int a = 0, b = 0, c = 0;
    for (int i = 0; i < n; ++i) {
      if (g[i] >= 0.9 * k) ++a;
      if (g[i] >= 0.8 * k) ++b;
      if (g[i] >= 0.7 * k) ++c;
    }
    return a < 0.25 * n || b < 0.5 * n || c < 0.75 * n;
  };
  int ret = minst(pred, 1, 2 * t) - 1;
  if (!ret) --ret;
  cout << ret << endl;
}
