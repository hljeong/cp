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

tT > ostream &operator<<(ostream &os, const vc<T> &a) {
  for (int i = 0, n = a.size(); i < n; i++)
    os << a[i] << " \n"[i == n - 1];
  return os;
}

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
string rs() { return read<string>(); }

tT > T nth_bit(T x, int n) { return (x >> n) & 1; }

tTU > T minst(T l, T r, U f) {
  T ans = r + 1;
  while (l <= r) {
    int m = l + (r - l) / 2;
    if (f(m))
      r = (ans = m) - 1;
    else
      l = m + 1;
  }
  return ans;
}

// split into cost of zeros and cost of ones
// suppose we only cut the right side. the cost
// of zeros is the prefix count of zeros and the
// suffix count of ones where we cut. the former
// is nondec and the latter is noninc
// binary search for where they cross for each
// starting index

void solve() {
  auto s = rs();
  int n = s.size();
  vi a(n);
  for (int i = 0; i < n; i++)
    a[i] = s[i] == '1';
  vi cost0(n + 1), cost1(n + 1);
  for (int i = 0; i < n; i++) {
    cost0[i + 1] = cost0[i] + !a[i];
    cost1[n - i - 1] = cost1[n - i] + a[n - i - 1];
  }
  // cout << cost0;
  // cout << cost1;
  int ans = n, zeros = 0, ones = 0;
  for (int i = 0; i < n; i++) {
    int j =
        minst(i, n, [&](int j) { return cost0[j] - zeros >= cost1[j] + ones; });
    ckmin(j, n);
    // cout << i << ", " << ones + max(cost0[j] - zeros, cost1[j] + ones) <<
    // endl;
    ckmin(ans, max(cost0[j] - zeros, cost1[j] + ones));
    zeros += !a[i];
    ones += a[i];
  }
  cout << ans << endl;
}

int main() {
  cin.tie(0)->sync_with_stdio(0);

  // int t = 1;
  int t = ri();
  while (t--) {
    solve();
  }
}
