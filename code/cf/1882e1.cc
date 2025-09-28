#include <bits/stdc++.h>
#define A first
#define B second
#define pb push_back
#define endl '\n'
#define tT template <typename T
#define tTU tT, class U
using namespace std;
tT > using vc = vector<T>;
using ll = long long;
using ld = long double;
using vi = vc<int>;
using vll = vc<ll>;
using si = set<int>;
using sll = set<ll>;
using pi = pair<int, int>;
using pll = pair<ll, ll>;
using qi = queue<int>;
using mi = map<int, int>;

tTU > T max(T a, U b) { return a > b ? a : b; }
tTU > T min(T a, U b) { return a < b ? a : b; }
tTU > bool ckmin(T &a, U b) { return b < a ? a = b, 1 : 0; }
tTU > bool ckmax(T &a, U b) { return a < b ? a = b, 1 : 0; }

constexpr int inf = 1e9 + 7;
constexpr int mod = inf;
constexpr ll infll = 0x3f3f'3f3f'3f3f'3f3fll;

tT > T read() {
  T x;
  cin >> x;
  return x;
}

int ri() { return read<int>(); }
int rll() { return read<ll>(); }
vi ria(int n) {
  vi a(n);
  for (int i = 0; i < n; i++)
    cin >> a[i];
  return a;
}
vi riam1(int n) {
  vi a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    --a[i];
  }
  return a;
}

tT > T nth_bit(T x, int n) { return (x >> n) & 1; }

// observations
//
// i, n - i -> no-op
// potentially have to deal with parity between the 2 seqs?
//
// swap(x, y):
// [1] x [2] y [3]
//     ^
//  i     j-i-1 n-j-1
// [2] y [3] x [1]
//     ^
// [3] x [1] y [2]
//     ^
// [1] y [2] x [3]
//
// no way to change parity?
// hint 3: can cycle thru the entire array by spamming index 1 so odd arrays can
// change parity

void solve() {
  int n = ri(), m = ri();
  vi a = riam1(n), b = riam1(m);
  vi as, bs;

  for (int i = 0; i < n - 1; i++) {
    if (a[i] != i) {
      for (int j = i + 1; j < n; j++) {
        if (a[j] == i) {
          // swap a[i] with a[j] = i
          as.pb(i);
          as.pb(j - i - 1);
          as.pb(n - j - 1);
          swap(a[i], a[j]);
          break;
        }
      }
    }
  }

  for (int i = 0; i < m - 1; i++) {
    if (b[i] != i) {
      for (int j = i + 1; j < m; j++) {
        if (b[j] == i) {
          // swap b[i] with b[j] = i
          bs.pb(i);
          bs.pb(j - i - 1);
          bs.pb(m - j - 1);
          swap(b[i], b[j]);
          break;
        }
      }
    }
  }

  // for (int x : as)
  //   cout << x << ", ";
  // cout << endl;
  //
  // for (int y : bs)
  //   cout << y << ", ";
  // cout << endl;

  // parity mismatch
  if ((as.size() ^ bs.size()) & 1) {
    // spam index 1 if either is odd
    if (n & 1) {
      for (int i = 0; i < n; i++)
        as.pb(0);
    } else if (m & 1) {
      for (int i = 0; i < m; i++)
        bs.pb(0);
    } else {
      cout << "-1" << endl;
      return;
    }
  }

  int i = 0;
  vc<pi> ans;
  while (i < min(as.size(), bs.size())) {
    ans.pb({as[i], bs[i]});
    i++;
  }
  if (as.size() < bs.size()) {
    while (i < bs.size()) {
      // spam alternating 1 and n for a
      ans.pb({(i & 1) ? 0 : n - 1, bs[i++]});
    }
  } else {
    while (i < as.size()) {
      // spam alternating 1 and m for b
      ans.pb({as[i++], (i & 1) ? 0 : m - 1});
    }
  }
  cout << ans.size() << endl;
  for (auto &[i, j] : ans) {
    cout << (i + 1) << " " << (j + 1) << endl;
  }
}

int main() {
  cin.tie(0)->sync_with_stdio(0);

  int t = 1;
  // int t = ri();
  while (t--) {
    solve();
  }
}
