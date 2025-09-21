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

int main() {
  int t; cin >> t;
  while (t--) {
    int n; cin >> n;
    int nd3 = n / 3;
    string s; cin >> s;
    int bal = 0;
    bool good = true;
    for (int i = 0; i < n; ++i) {
      if (s[i] == 'T') ++bal;
      else if (--bal < 0) good &= false;
    }
    reverse(s.begin(), s.end());
    int bal2 = 0;
    for (int i = 0; i < n; ++i) {
      if (s[i] == 'T') ++bal2;
      else if (--bal2 < 0) good &= false;
    }
    cout << (good && bal == nd3 && bal2 == nd3 ? "YES" : "NO") << endl;
  }
}
