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
    ll n; cin >> n;
    bool good = false;
    for (int k = 2; k <= 60; ++k) {
      function<bool(ll)> pred = [&](ll b) {
        ll cur = 1, term = 1;
        for (int j = 1; j <= k; ++j) {
          if (infll / b < term) return true;
          term *= b;
          if (cur + term > infll) return true;
          cur += term;
        }
        return cur >= n;
      };
      ll b = minst(pred, 2ll, (ll) inf);
      ll cur = 1, term = 1;
      for (int j = 1; j <= k; ++j) {
        if (infll / b < term) {
          cur = n + 1;
          break;
        }
        term *= b;
        if (cur + term > infll) {
          cur = n + 1;
          break;
        }
        cur += term;
      }
      if (cur == n) {
        good = true;
        break;
      }
    }
    cout << (good ? "YES" : "NO") << endl;
  }
}
