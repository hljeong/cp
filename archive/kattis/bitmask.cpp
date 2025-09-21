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

template<class T> bool ckmin(T &a, const T &b) { return b < a ? a = b, 1 : 0; }
template<class T> bool ckmax(T &a, const T &b) { return a < b ? a = b, 1 : 0; }

int main() {
  string s; cin >> s;
  int n = s.length();
  vi c(n); for (int i = 0; i < n; ++i) cin >> c[i];
  int ans = c[0] * 2;
  for (int m = 0; m < (1 << (n - 1)); ++m) {
    set<string> st;
    stringstream cur;
    int cost = 0;
    for (int i = 0; i < n - 1; ++i) {
      cur << s[i];
      if ((m >> i) & 1) {
        string pt; cur >> pt;
        cur.clear();
        if (st.find(pt) == st.end()) cost += c[pt.length() - 1];
        st.insert(pt);
      }
    }
    cur << s[n - 1];
    string pt; cur >> pt;
    if (st.find(pt) == st.end()) cost += c[pt.length() - 1];
    ckmin(ans, cost);
  }
  cout << ans << endl;
}
