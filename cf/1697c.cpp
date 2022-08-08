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
  int q;
  cin >> q;
  while (q--) {
    int n;
    cin >> n;
    string s, t;
    cin >> s >> t;
    vi f(3);
    for (int i = 0; i < n; ++i) {
      ++f[s[i] - 'a'];
      --f[t[i] - 'a']; 
    }
    if (f[0] | f[1] | f[2]) {
      cout << "NO" << endl;
      continue;
    }
    vi snb, tnb;
    int si = 0, ti = 0, sa = 0, ta = 0, sc = 0, tc = 0;
    bool bad = false;
    while (si < n || ti < n) {
      while (si < n && s[si] != 'b') {
        if (s[si] == 'a') ++sa;
        else ++sc;
        snb.push_back(s[si]);
        ++si;
      }
      while (ti < n && t[ti] != 'b') {
        if (t[ti] == 'a') ++ta;
        else ++tc;
        tnb.push_back(t[ti]);
        ++ti;
      }
      if (sa < ta || sc > tc) {
        bad = true;
        break;
      }
      ++si;
      ++ti;
    }
    bad |= snb != tnb;
    if (bad) cout << "NO" << endl;
    else cout << "YES" << endl;
  }
}