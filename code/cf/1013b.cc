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

tT > ostream &operator<<(ostream &os, const vc<T> &a) {
  for (int i = 0, n = a.size(); i < n; i++)
    os << a[i] << " \n"[i == n - 1];
  return os;
}

tT > T rd() {
  T x;
  cin >> x;
  return x;
}

tT > vc<T> rda(int n) {
  vc<T> v(n);
  for (int i = 0; i < n; i++) {
    cin >> v[i];
  }
  return v;
}

int ri() { return rd<int>(); }
ll rll() { return rd<ll>(); }
string rs() { return rd<string>(); }
vi ria(int n) { return rda<int>(n); }
vll rlla(int n) { return rda<ll>(n); }

tTU > T max(T a, U b) { return a > b ? a : b; }
tTU > T min(T a, U b) { return a < b ? a : b; }
tTU > bool ckmin(T &a, U b) { return b < a ? a = b, 1 : 0; }
tTU > bool ckmax(T &a, U b) { return a < b ? a = b, 1 : 0; }
tT > T nth_bit(T x, int n) { return (x >> n) & 1; }
tTU > T minst(T l, T r, U pred) {
  T ans = r + 1;
  while (l <= r) {
    T m = l + (r - l) / 2;
    if (pred(m))
      r = (ans = m) - 1;
    else
      l = m + 1;
  }
  return ans;
}
tTU > T maxst(T l, T r, U pred) {
  T ans = l - 1;
  while (l <= r) {
    T m = l + (r - l) / 2;
    if (pred(m))
      l = (ans = m) + 1;
    else
      r = m - 1;
  }
  return ans;
}

constexpr int inf = 1e9 + 7;
constexpr int mod = inf;
constexpr ll infll = 0x3f3f'3f3f'3f3f'3f3fll;

void solve() {
  int n = ri(), x = ri();
  vi a = ria(n);
  mi before, after;
  for (int ai : a) {
    if (before[ai]++) {
      cout << 0 << endl;
      return;
    }
    if ((ai & x) != ai)
      after[ai & x]++;
  }

  for (auto &[ai, _] : after) {
    if (before[ai]) {
      cout << 1 << endl;
      return;
    }
  }

  for (auto &[ai, freq] : after) {
    if (freq > 1) {
      cout << 2 << endl;
      return;
    }
  }

  cout << -1 << endl;
}

int main() {
  cin.tie(0)->sync_with_stdio(0);

  int t = 1;
  // int t = ri();
  while (t--) {
    solve();
  }
}
