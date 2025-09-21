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

constexpr int inf = 1e9 + 7;
constexpr int mod = inf;
constexpr ll infll = 0x3f3f3f3f3f3f3f3fll;

int main() {
  cin.tie(0) -> sync_with_stdio(0);

  int t; cin >> t; while (t--) {
    int n; cin >> n;
    vi a(n); for (int i = 0; i < n; ++i) cin >> a[i];
    ll ret = 0;
    mi f;
    for (int i = 0; i < n; ++i) ++f[a[i]];
    for (const auto [k, v] : f) {
      ret += (ll) v * (v - 1) / 2;
    }
    ret += (ll) f[1] * f[2];
    cout << ret << endl;
  }
}
