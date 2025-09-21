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

// stupid casework
int main() {
  cin.tie(0) -> sync_with_stdio(0);

  string sn; cin >> sn;
  int m = sn.length();
  vi n(m); for (int i = 0; i < m; ++i) n[i] = sn[i] - '0';
  vi cnt(3);
  for (int i = 0; i < m; ++i) ++cnt[n[i] % 3];
  int m3 = (cnt[1] + 2 * cnt[2]) % 3;
  if (m3 == 0) {
  } else if (m3 == 1) {
    if (!cnt[1] || cnt[1] == 1 && cnt[2] >= 2 && n[0] % 3 == 1 && !n[1]) {
      int cc = 0;
      for (int i = m - 1; i >= 0; --i) {
        if (n[i] % 3 == 2) {
          n[i] = -1;
          if (++cc == 2) break;
        }
      }
    } else {
      for (int i = m - 1; i >= 0; --i) {
        if (n[i] % 3 == 1) {
          n[i] = -1;
          break;
        }
      }
    }
  } else if (!cnt[2] || cnt[2] == 1 && cnt[1] >= 2 && n[0] % 3 == 2 && !n[1]) {
    int cc = 0;
    for (int i = m - 1; i >= 0; --i) {
      if (n[i] % 3 == 1) {
        n[i] = -1;
        if (++cc == 2) break;
      }
    }
  } else {
    for (int i = m - 1; i >= 0; --i) {
      if (n[i] % 3 == 2) {
        n[i] = -1;
        break;
      }
    }
  }
  bool leading = true;
  int p = 0, zc = 0;
  for (int i = 0; i < m; ++i) {
    if (n[i] == -1) continue;
    if (!n[i]) ++zc;
    if (leading && !n[i] && i != m - 1) continue;
    if (n[i]) leading = false;
    cout << n[i];
    ++p;
  }
  if (p) cout << endl;
  else if (zc) cout << 0 << endl;
  else cout << -1 << endl;
}
