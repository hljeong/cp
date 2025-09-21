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
    int n, k; cin >> n >> k;
    string s; cin >> s;
    vi f(256);
    for (char c : s) {
      ++f[c];
    }
    int ret = 0;
    for (char c = 'a'; c <= 'z'; ++c) {
      char C = (char) (c + ('A' - 'a'));
      if (f[c] < f[C]) swap(f[c], f[C]);
      while (k && f[c] >= f[C] + 2) {
        --f[c];
        ++f[C];
        --k;
      }
      ret += f[C];
    }
    cout << ret << endl;
  }
}
