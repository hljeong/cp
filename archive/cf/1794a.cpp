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

int main() {
  cin.tie(0) -> sync_with_stdio(0);

  int t; cin >> t;
  while (t--) {
    int n; cin >> n;
    string a, b;
    for (int i = 0; i < 2 * n - 2; ++i) {
      string s; cin >> s;
      if (s.length() == n - 1) {
        if (a == "") a = s;
        else b = s;
      }
    }
    if (a.substr(1) != b.substr(0, n - 2)) swap(a, b);
    string m = a.substr(1); int l = m.length();
    bool good = true;
    for (int i = 0; i < l / 2; ++i) {
      if (m[i] != m[l - i - 1]) good = false;
    }
    cout << (a[0] == b[n - 2] && good ? "YES" : "NO") << endl;
  }
}
