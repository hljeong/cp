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

vi sieve(int n) {
  vi ret(n + 1);
  for (int i = 2, j = i; i <= n; j = ++i) {
    if (ret[i]) continue;
    while (j <= n) {
      ret[j] = i;
      j += i;
    }
  }
  return ret;
}

int main() {
  cin.tie(0) -> sync_with_stdio(0);

  vi d = sieve(1000005);
  int t; cin >> t;
  while (t--) {
    int n, q; cin >> n >> q;
    mi opf, pf;
    int tn = n;
    while (tn != 1) {
      ++pf[d[tn]];
      tn /= d[tn];
    }
    opf = pf;
    while (q--) {
      int k; cin >> k;
      if (k == 1) {
        int x; cin >> x;
        while (x != 1) {
          ++pf[d[x]];
          x /= d[x];
        }
        mi ndpf;
        bool good = true;
        for (const auto &[p, e] : pf) {
          int exp = e + 1;
          while (exp != 1) {
            ++ndpf[d[exp]];
            exp /= d[exp];
          }
        }
        for (const auto &[p, e] : ndpf) {
          if (e > pf[p]) {
            good = false;
            break;
          }
        }
        cout << (good ? "YES" : "NO") << endl;
      } else {
        pf = opf;
      }
    }
    cout << endl;
  }
}
