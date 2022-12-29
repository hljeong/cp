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
using gr = vc<vi>; using wgr = vc<vc<pii>>;

template<class T> bool ckmin(T &a, const T &b) { return b < a ? a = b, 1 : 0; }
template<class T> bool ckmax(T &a, const T &b) { return a < b ? a = b, 1 : 0; }

const int inf = 1e9 + 7;
const int mod = inf;
const ll infll = 0x3f3f3f3f3f3f3f3fll;

int main() {
  int n, s, m; cin >> n >> s >> m; --s;
  vi a(n); for (int i = 0; i < n; ++i) cin >> a[i];
  si v;
  int ret = 0;
  bool magic = false;
  while (true) {
    if (s < 0) break;
    if (s >= n) break;
    if (a[s] == m) {
      magic = true;
      break;
    }
    if (v.count(s)) {
      break;
    }
    v.insert(s);
    s += a[s];
    ++ret;
  }
  if (magic) {
    cout << "magic" << endl;
  } else if (s < 0) {
    cout << "left" << endl;
  } else if (s >= n) {
    cout << "right" << endl;
  } else {
    cout << "cycle" << endl;
  }
  cout << ret << endl;
}
