#include <bits/stdc++.h>
#define A first
#define B second
#define X first
#define Y second
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

tTU > ostream &operator<<(ostream &os, const pair<T, U> &p) {
  os << "(" << p.A << ", " << p.B << ")";
  return os;
}

tT > ostream &operator<<(ostream &os, const vc<T> &a) {
  for (int i = 0, n = a.size(); i < n; i++) {
    if (i)
      os << " ";
    os << a[i];
  }
  return os;
}

tT > T read() {
  T x;
  cin >> x;
  return x;
}

tT > vc<T> reada(int n) {
  vc<T> v(n);
  for (int i = 0; i < n; i++) {
    cin >> v[i];
  }
  return v;
}

int ri() { return read<int>(); }
ll rll() { return read<ll>(); }
string rs() { return read<string>(); }
vi ria(int n) { return reada<int>(n); }
vll rlla(int n) { return reada<ll>(n); }

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
  int n, k;
  cin >> n >> k;
  vll a = rlla(n);

  ll sum = 0;
  int cnt0 = 0;
  for (auto ai : a) {
    sum += ai;
    cnt0 += !!!ai;
  }
  if (abs(sum) > (ll)k * cnt0) {
    // cant get back even if we spend all the 0s crawling back
    cout << -1 << endl;
    return;
  }

  // editorial: assume each cyclic shift starts from the minimum
  // simply greedy our way to the top
  ll ans = 1;
  for (int off = 0; off < n; off++) {
    auto get = [&](int i) { return a[(i + off) % n]; };
    vll sum(n + 1), cnt0(n + 1);
    for (int i = n - 1; i >= 0; i--) {
      sum[i] = sum[i + 1] + get(i);
      cnt0[i] = cnt0[i + 1] + !!!get(i);
    }
    ll cur = 0;
    int i = 0;
    while (i < n) {
      if (get(i)) {
        cur += get(i);
        goto next;
      }

      // fixed suffix delta: sum[i + 1]
      // we can go back cnt0[i + 1] * k at most
      // advance as much as possible
      cur += min(k, -(sum[i + 1] - cnt0[i + 1] * k) - cur);

    next:
      // cout << cur << " ";
      ckmax(ans, cur + 1);
      i++;
    }
    // cout << endl;
  }
  cout << ans << endl;
}

int main() {
  cin.tie(0)->sync_with_stdio(0);

  int t = 1;
  // int t = ri();
  while (t--) {
    solve();
  }
}
