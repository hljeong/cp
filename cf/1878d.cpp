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

template<class T> T minst(function<bool(T)> pred, T i, T j) {
  T ret = j + 1;
  for (T l = i, r = j, m; l <= r; ) {
    if (pred(m = l + (r - l) / 2)) r = (ret = m) - 1;
    else l = m + 1;
  }
  return ret;
}

template<class T> T maxst(function<bool(T)> pred, T i, T j) {
  T ret = i - 1;
  for (T l = i, r = j, m; l <= r; ) {
    if (pred(m = l + (r - l) / 2)) l = (ret = m) + 1;
    else r = m - 1;
  }
  return ret;
}

int main() {
  cin.tie(0) -> sync_with_stdio(0);

  int t; cin >> t;
  while (t--) {
    int n, k; cin >> n >> k;
    string s; cin >> s;
    vi l(k), r(k);
    for (int i = 0; i < k; ++i) cin >> l[i];
    for (int i = 0; i < k; ++i) cin >> r[i];
    vi rev(n), other(n), vis(n);
    int q; cin >> q;
    while (q--) {
      int x; cin >> x;
      function<bool(int)> pred = [&](int j) {
        return x <= r[j];
      };
      int i = minst(pred, 0, k - 1);
      int a = min(x, l[i] + r[i] - x) - 1;
      int b = max(x, l[i] + r[i] - x) - 1;
      if (a != b) rev[a] = rev[b] = !rev[a];
      other[a] = b;
      other[b] = a;
    }
    int i = 0, inc = 1;
    for (int j = 0; j < n; ++j) {
      // cout << i << ' ' << other[i] << ' ' << rev[i] << flush << endl;
      if (rev[i]) {
        if (vis[other[i]]) {
          cout << s[i];
          vis[i] = 1;
          i = other[i];
          inc = -inc;
        } else {
          i = other[i];
          cout << s[i];
          vis[i] = 1;
          inc = -inc;
        }
      } else {
        cout << s[i];
      }
      i += inc;
      // cout << flush;
    }
    cout << endl;
  }
}
