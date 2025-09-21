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
  ll n; int k; cin >> n >> k;
  vc<pll> seg(k);
  for (int i = 0; i < k; ++i) {
    cin >> seg[i].A >> seg[i].B;
  }
  sort(seg.begin(), seg.end(), [&](pll a, pll b) {
    return a.B < b.B;
  });
  vll ends(1, 0);
  for (int i = 0; i < k; ++i) if (!i || seg[i].B != seg[i - 1].B) ends.pb(seg[i].B);
  int m = ends.size();
  map<ll, ll> dp;
  ll ret = 0;
  for (int i = 0; i < k; ++i) {
    int j = minst((function<bool(int)>) [&](int ind) { return seg[i].A <= ends[ind]; }, 1, m - 1) - 1;
    ll p = dp[ends[j]], l = seg[i].B - seg[i].A + 1;
    ckmax(ret, p + l);
    ckmax(dp[seg[i].B], ret);
    // for (auto &p : dp) cout << p.A << ", " << p.B << endl;
    // cout << endl;
  }
  cout << (n - ret) << endl;
}
