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

// greedily set highest bit, set all the rest to 1 whenever possible
int main() {
  cin.tie(0) -> sync_with_stdio(0);

  int c; cin >> c;
  while (c--) {
    int n; cin >> n;
    vll a(n);
    priority_queue<pair<ll, int>> q;
    for (int i = 0; i < n; ++i) {
      cin >> a[i];
      q.push({ a[i], i });
    }
    ll ret = 0;
    vll choose(n);
    for (int i = 61; i >= 0; --i) {
      ll b = 1ll << i;
      auto [v, j] = q.top(); q.pop();
      if (v >= (b << 1)) {
        ret |= (b << 1) - 1;
        choose[j] |= (b << 1) - 1;
        break;
      } else if (v & b) {
        ret |= b;
        choose[j] |= b;
        v ^= b;
      }
      q.push({ v, j });
    }
    cout << ret << endl;
    for (int i = 0; i < n; ++i) {
      cout << choose[i] << " \n"[i == n - 1];
    }
  }
}
