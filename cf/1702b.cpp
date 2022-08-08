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
  int t; cin >> t;
  while (t--) {
    string s; cin >> s;
    int ans = 1;
    set<char> st;
    for (char c : s) {
      st.insert(c);
      if (st.size() > 3) {
        st.clear();
        st.insert(c);
        ++ans;
      }
    }
    cout << ans << endl;
  }
}