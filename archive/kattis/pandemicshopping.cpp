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
  string a = "", b = "";
  vc<string> d(n);
  for (int i = 0; i < k; ++i) {
    string aisle, dir; cin >> aisle >> dir;
    if (aisle == "A") a = dir;
    else if (aisle == "B") b = dir;
    else d[atoi(aisle.c_str()) - 1] = dir;
  }
  ll ans = 0;
  if (a == "" && b == "") {
    if (n & 1) {
      int good = 1;
      for (int i = 0; i < n; ++i) {
        if (d[i] == "") continue;
        if ((i & 1) && d[i] == "W2E") good = 0;
        if (!(i & 1) && d[i] == "E2W") good = 0;
      }
      ans += good;
    }
    if (d[0] != "W2E" && d[n - 1] != "E2W") {
      int cnt = 0;
      for (int i = 1; i < n - 1; ++i) {
        if (d[i] == "") ++cnt;
      }
      ans += 1LL << cnt;
    }
    if (d[0] != "E2W" && d[n - 1] != "W2E") {
      int cnt = 0;
      for (int i = 1; i < n - 1; ++i) {
        if (d[i] == "") ++cnt;
      }
      ans += 1LL << cnt;
    }
    if (n & 1) {
      int good = 1;
      for (int i = 0; i < n; ++i) {
        if (d[i] == "") continue;
        if ((i & 1) && d[i] == "E2W") good = 0;
        if (!(i & 1) && d[i] == "W2E") good = 0;
      }
      ans += good;
    }
  } else if (a == "" && b == "S2N") {
    if (n & 1) {
      int good = 1;
      for (int i = 0; i < n; ++i) {
        if (d[i] == "") continue;
        if ((i & 1) && d[i] == "W2E") good = 0;
        if (!(i & 1) && d[i] == "E2W") good = 0;
      }
      ans += good;
    }
    if (d[0] != "E2W" && d[n - 1] != "W2E") {
      int cnt = 0;
      for (int i = 1; i < n - 1; ++i) {
        if (d[i] == "") ++cnt;
      }
      ans += 1LL << cnt;
    }
  } else if (a == "" && b == "N2S") {
    if (d[0] != "W2E" && d[n - 1] != "E2W") {
      int cnt = 0;
      for (int i = 1; i < n - 1; ++i) {
        if (d[i] == "") ++cnt;
      }
      ans += 1LL << cnt;
    }
    if (n & 1) {
      int good = 1;
      for (int i = 0; i < n; ++i) {
        if (d[i] == "") continue;
        if ((i & 1) && d[i] == "E2W") good = 0;
        if (!(i & 1) && d[i] == "W2E") good = 0;
      }
      ans += good;
    }
  } else if (a == "S2N" && b == "") {
    if (n & 1) {
      int good = 1;
      for (int i = 0; i < n; ++i) {
        if (d[i] == "") continue;
        if ((i & 1) && d[i] == "W2E") good = 0;
        if (!(i & 1) && d[i] == "E2W") good = 0;
      }
      ans += good;
    }
    if (d[0] != "W2E" && d[n - 1] != "E2W") {
      int cnt = 0;
      for (int i = 1; i < n - 1; ++i) {
        if (d[i] == "") ++cnt;
      }
      ans += 1LL << cnt;
    }
  } else if (a == "S2N" && b == "S2N") {
    if (n & 1) {
      int good = 1;
      for (int i = 0; i < n; ++i) {
        if (d[i] == "") continue;
        if ((i & 1) && d[i] == "W2E") good = 0;
        if (!(i & 1) && d[i] == "E2W") good = 0;
      }
      ans += good;
    }
  } else if (a == "S2N" && b == "N2S") {
    if (d[0] != "W2E" && d[n - 1] != "E2W") {
      int cnt = 0;
      for (int i = 1; i < n - 1; ++i) {
        if (d[i] == "") ++cnt;
      }
      ans += 1LL << cnt;
    }
  } else if (a == "N2S" && b == "") {
    if (d[0] != "E2W" && d[n - 1] != "W2E") {
      int cnt = 0;
      for (int i = 1; i < n - 1; ++i) {
        if (d[i] == "") ++cnt;
      }
      ans += 1LL << cnt;
    }
    if (n & 1) {
      int good = 1;
      for (int i = 0; i < n; ++i) {
        if (d[i] == "") continue;
        if ((i & 1) && d[i] == "E2W") good = 0;
        if (!(i & 1) && d[i] == "W2E") good = 0;
      }
      ans += good;
    }
  } else if (a == "N2S" && b == "S2N") {
    if (d[0] != "E2W" && d[n - 1] != "W2E") {
      int cnt = 0;
      for (int i = 1; i < n - 1; ++i) {
        if (d[i] == "") ++cnt;
      }
      ans += 1LL << cnt;
    }
  } else if (a == "N2S" && b == "N2S") {
    if (n & 1) {
      int good = 1;
      for (int i = 0; i < n; ++i) {
        if (d[i] == "") continue;
        if ((i & 1) && d[i] == "E2W") good = 0;
        if (!(i & 1) && d[i] == "W2E") good = 0;
      }
      ans += good;
    }
  }
  cout << ans << endl;
}
