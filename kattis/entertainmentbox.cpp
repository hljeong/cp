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
  int n, k; cin >> n >> k;
  vc<pii> s(n);
  for (int i = 0; i < n; ++i) {
    cin >> s[i].A >> s[i].B;
  }
  sort(s.begin(), s.end(), [&](const pii &a, const pii &b) {
    if (a.B == b.B) return b.A < a.A;
    return a.B < b.B;
  });
  multiset<int> c;
  for (int i = 0; i < k; ++i) c.insert(0);
  int ans = 0;
  for (pii p : s) {
    auto it = c.upper_bound(p.A);
    if (it == c.begin()) continue;
    --it;
    c.erase(it);
    c.insert(p.B);
    ++ans;
  }
  cout << ans << endl;
}
