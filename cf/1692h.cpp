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

int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    vi x(n), nxt(n, n), sz(n);
    map<int, int> lst;
    for (int i = 0; i < n; ++i) cin >> x[i];
    for (int i = n - 1; i >= 0; --i) {
      if (lst.find(x[i]) != lst.end()) {
        nxt[i] = lst[x[i]];
        if (nxt[i] == i + 1) sz[i] = sz[i + 1] + 1;
        else sz[i] = 1;
      } else sz[i] = 1;
      lst[x[i]] = i;
    }
    int c = x[0], l = 1, r = 1, mx = 1;
    set<int> s; 
    for (int i = 0; i < n; ++i) {
      if (s.find(x[i]) == s.end()) {
        s.insert(x[i]);
        int cc = x[i], cl = i, cr = i + sz[i] - 1, cmx = sz[i];
        while (cr < n) {
          if (ckmax(mx, cmx)) {
            // cout << cmx << ' ' << cc << ' ' << cl << ' ' << cr << endl;
            c = cc;
            l = cl + 1;
            r = cr + 1;
          }
          if (nxt[cr] == n) break;
          if (cmx - (nxt[cr] - cr - 1) <= 0) {
            cmx = sz[nxt[cr]];
            cl = nxt[cr];
            cr = cl + sz[cl] - 1;
          } else {
            cmx += sz[nxt[cr]] - (nxt[cr] - cr - 1);
            cr = nxt[cr] + sz[nxt[cr]] - 1;
          }
        }
      }
    }
    cout << c << ' ' << l << ' ' << r << endl;
  }
}