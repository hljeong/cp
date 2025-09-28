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

tT > T nth_bit(T x, int n) { return (x >> n) & 1; }

void solve() {
  int l1 = ri(), r1 = ri(), l2 = ri(), r2 = ri();
  if (!(r1 < l2 || r2 < l1)) {
    // if overlap, take overlap min
    cout << max(l1, l2) << endl;
  } else {
    // else take min for each
    cout << l1 + l2 << endl;
  }
}

int main() {
  cin.tie(0)->sync_with_stdio(0);

  // int t = 1;
  int t = ri();
  while (t--) {
    solve();
  }
}
