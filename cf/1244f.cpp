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

constexpr int inf = 1e9 + 7;
constexpr int mod = inf;
constexpr ll infll = 0x3f3f3f3f3f3f3f3fll;

// only interesting part is alternating (shrinks by 2 every iteration)
int main() {
  cin.tie(0) -> sync_with_stdio(0);

  int n, k; cin >> n >> k;
  string s; cin >> s;
  vi a(n); for (int i = 0; i < n; ++i) a[i] = s[i] == 'B';
  // find offset to shift so that a[0] == a[-1]
  int off = -1;
  if (a[0] == a[n - 1]) off = 0;
  for (int i = 1; i < n; ++i) {
    if (a[i] == a[i - 1]) {
      off = i;
      break;
    }
  }
  if (off == -1) {
    // no breakpoint: fully alternating, output depends on parity of k
    if (k & 1) {
      for (int i = 0; i < n; ++i) cout << (a[i] ? 'W' : 'B');
      cout << endl;
    } else cout << s << endl;
  } else {
    // shift by offset
    vi tmp(n);
    for (int i = 0; i < n; ++i) {
      tmp[i] = a[(i + off) % n];
    }
    swap(a, tmp);
    // find all alternating sequences
    vc<pi> b;
    int st = -1;
    for (int i = 1; i < n; ++i) {
      if (a[i] != a[i - 1]) {
        if (st == -1) {
          st = i;
        }
      } else if (st != -1) {
        // ignore BBWW or WWBB -- they are stable
        if (st <= i - 2) b.pb({ st, i - 2 });
        st = -1;
      }
    }
    if (st != -1 && st <= n - 2) b.pb({ st, n - 2 });
    /*
    for (auto [u, v] : b) {
      cout << ((u + off) % n) << " " << ((v + off) % n) << endl;
    }
    */
    for (auto [u, v] : b) {
      int lf = a[(u + n - 1) % n], rg = a[(v + 1) % n];
      int i = 0;
      // shrink naively
      for (; i < k; ++i) {
        if (u + i > v - i) break;
        a[u + i] = lf;
        a[v - i] = rg;
      }
      // alternating in the middle
      lf ^= 1;
      for (int j = u + i; j <= v - i; ++j) {
        a[j] = lf;
        lf ^= 1;
      }
    }
    for (int i = 0; i < n; ++i) {
      cout << (a[(i + n - off) % n] ? 'B' : 'W');
    }
    cout << endl;
  }
}
