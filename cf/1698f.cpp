#include <bits/stdc++.h>
#define A first
#define B second
#define vc vector
using namespace std;
using ll = long long;
using ld = long double;
using vi = vc<int>;
using vll = vc<ll>;
using pii = pair<int, int>;

template<class T> bool ckmin(T& a, const T& b) { return b < a ? a = b, 1 : 0; }
template<class T> bool ckmax(T& a, const T& b) { return a < b ? a = b, 1 : 0; }

// editorial sol

void rev(vi &a, int l, int r) {
  for (int i = 0, m = (r - l + 1) / 2; i < m; ++i) swap(a[l + i], a[r - i]);
}

int main() {
  int t; cin >> t;
  while (t--) {
    int n; cin >> n;
    vi a(n), b(n);
    for (int i = 0; i < n; ++i) cin >> a[i];
    for (int i = 0; i < n; ++i) cin >> b[i];
    bool bad = false;
    vc<pii> ans;
    if (a[0] != b[0] || a[n - 1] != b[n - 1]) {
      bad = true;
    } else {
      for (int i = 1; i < n - 1; ++i) {
        if (a[i] == b[i]) continue;
        map<int, int> before;
        before[a[i - 1]] = i - 1;
        before[a[i]] = i;
        // flg: 0 = not found, 1 = good order, 2 = need swap
        int flg = 0, fl = -1, fr = -1, gr = -1;
        for (int j = i + 1; j < n; ++j) {
          if (a[j - 1] == b[i] && a[j] == a[i - 1]) {
            flg = 1;
            gr = j;
            break;
          }
        }
        if (flg == 1) {
          rev(a, i - 1, gr);
          ans.push_back({i - 1, gr});
          continue;
        }
        for (int j = i + 1; j < n; ++j) {
          if (!flg) {
            if (a[j - 1] == a[i - 1] && a[j] == b[i]) {
              flg = 2;
              gr = j - 1;
            } else {
              before[a[j]] = j;
            }
          }
          if (flg == 2 && before.find(a[j]) != before.end()) {
            fl = before[a[j]];
            fr = j;
            gr = fl + (fr - gr);
            break;
          }
        }
        if (fl == -1) {
          bad = true;
          break;
        }
        rev(a, fl, fr);
        ans.push_back({fl, fr});
        rev(a, i - 1, gr);
        ans.push_back({i - 1, gr});
      }
    }
    cout << (bad ? "NO" : "YES") << endl;
    if (!bad) {
      cout << ans.size() << endl;
      for (pii p : ans) {
        cout << (p.A + 1) << ' ' << (p.B + 1) << endl;
      }
    }
  }
}