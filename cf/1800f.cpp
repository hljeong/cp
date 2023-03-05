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

char sr[5000005];

int main() {
  // cin.tie(0) -> sync_with_stdio(0);

  int n; cin >> n;
  ll ret = 0;
  vi p(n);
  vc<unordered_map<int, int>> cnt(26);
  for (int i = 0; i < n; ++i) {
    scanf("%s", sr);
    string s = sr;
    vi f(26);
    int p = 0;
    for (char c : s) {
      p ^= 1 << (c - 'a');
      ++f[c - 'a'];
    }
    for (int i = 0; i < 26; ++i) {
      if (!f[i]) {
        ret += cnt[i][((1 << 26) - 1) ^ (1 << i) ^ p];
        ++cnt[i][p];
      }
    }
  }
  cout << ret << endl;
}
