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
  map<string, int> mp; int sid = 0;
  vc<si> s(n);
  for (int i = 0; i < k; ++i) {
    int id; cin >> id;
    string item; cin >> item;
    if (!mp.count(item)) mp[item] = sid++;
    s[id].insert(mp[item]);
  }
  int m; cin >> m;
  vi order(m);
  for (int i = 0; i < m; ++i) {
    string item; cin >> item;
    order[i] = mp[item];
  }
  vi pre(n + 1), suf(n + 1);
  for (int i = 0; i < n; ++i) {
    pre[i + 1] = pre[i];
    while (pre[i + 1] < m && s[i].count(order[pre[i + 1]])) {
      ++pre[i + 1];
    }
  }
  if (pre[n] < m) {
    cout << "impossible" << endl;
    return 0;
  }
  suf[n] = m;
  for (int i = n - 1; i >= 0; --i) {
    suf[i] = suf[i + 1];
    while (suf[i] && s[i].count(order[suf[i] - 1])) {
      --suf[i];
    }
  }
  // for (int i = 0; i <= n; ++i) cout << pre[i] << " \n"[i == n];
  // for (int i = 0; i <= n; ++i) cout << suf[i] << " \n"[i == n];
  for (int i = 0; i <= n; ++i) {
    if (pre[i] > suf[i]) {
      cout << "ambiguous" << endl;
      return 0;
    }
  }
  cout << "unique" << endl;
}
