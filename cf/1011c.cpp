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

bool check(ld f, vi &a, vi &b, int n, int m) {
  ld cur = f;
  cur -= (m + cur) / a[0];
  if (cur < 0) return false;
  for (int i = 1; i < n; ++i) {
    cur -= (m + cur) / a[i];
    if (cur < 0) return false;
    cur -= (m + cur) / b[i];
    if (cur < 0) return false;
  }
  cur -= (m + cur) / b[0];
  return cur >= 0;
}

int main() {
  int n, m; cin >> n >> m;
  vi a(n), b(n);
  for (int i = 0; i < n; ++i) cin >> a[i];
  for (int i = 0; i < n; ++i) cin >> b[i];
  ld ret = -1;
  for (ld l = 0, r = 1e9; r - l > 1e-10; ) {
    ld mid = l + (r - l) / 2;
    if (check(mid, a, b, n, m)) {
      r = ret = mid;
    } else l = mid;
  }
  cout << setprecision(12) << fixed << ret << endl;
}
