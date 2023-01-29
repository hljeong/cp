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
  string s; cin >> s;
  int n = s.length();
  int ret = n;
  for (int i = n - 1; i >= 1; --i) {
    if (n % i) continue;
    vc<string> ss;
    for (int j = 0; j < n / i; ++j) {
      ss.pb(s.substr(j * i, i));
    }
    bool good = true;
    for (int j = 0; j < n / i - 1; ++j) {
      string a = ss[j], b = ss[j + 1];
      if (a[i - 1] != b[0]) good = false;
      if (a.substr(0, i - 1) != b.substr(1, i - 1)) good = false;
    }
    if (good) ret = i;
  }
  cout << ret << endl;
}
