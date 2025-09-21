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
  set<string> bruh;
  stringstream bruhbruh;
  for (int i = 1; i < 100000; ++i) {
    if (!(i % 3)) bruhbruh << 'F';
    if (!(i % 5)) bruhbruh << 'B';
  }
  string bruhbruhbruh; bruhbruh >> bruhbruhbruh;
  for (int i = 1; i <= 10; ++i) {
    for (int j = 0; j < bruhbruhbruh.length() - i; ++j) {
      bruh.insert(bruhbruhbruh.substr(j, i));
    }
  }

  int t; cin >> t;
  while (t--) {
    int k; cin >> k;
    string s; cin >> s;
    if (bruh.count(s)) cout << "YES" << endl;
    else cout << "NO" << endl;
  }
}
