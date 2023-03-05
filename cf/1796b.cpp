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
    string a, b; cin >> a >> b;
    int n = a.length(), m = b.length();
    if (a[0] == b[0]) {
      cout << "YES" << endl;
      cout << a[0] << '*' << endl;
    } else if (a[n - 1] == b[m - 1]) {
      cout << "YES" << endl;
      cout << '*' << a[n - 1] << endl;
    } else {
      int ind = -1;
      for (int i = 0; i < n - 1; ++i) {
        for (int j = 0; j < m - 1; ++j) {
          if (a[i] == b[j] && a[i + 1] == b[j + 1]) {
            ind = i;
          }
        }
      }
      if (ind == -1) cout << "NO" << endl;
      else cout << "YES" << endl << '*' << a[ind] << a[ind + 1] << '*' << endl;
    }
  }
}
