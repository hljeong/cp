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

void solve_perm(int &odd, int &even, int bit, vi &odd_s, vi &even_s,
                const vi &a, int x_off) {
  int n = a.size();
  vi cur(n + 1), icur(n + 1), tgt(n + 1);
  vi s;
  cur[0] = n;
  icur[n] = 0;
  tgt[x_off] = n;
  // cur: X, a[0], a[1], ..., a[n - 1]
  // tgt: k, ..., n - 1, X, 0, ..., k - 1
  for (int i = 0; i < n; i++) {
    tgt[(x_off + i + 1) % (n + 1)] = i;
    cur[i + 1] = a[i];
    icur[a[i]] = i + 1;
  }
  // for (int i = 0; i <= n; i++) {
  //   cout << cur[i] << " \n"[i == n];
  // }
  // for (int i = 0; i <= n; i++) {
  //   cout << tgt[i] << " \n"[i == n];
  // }
  // cout << endl;
  // cout << flush;

  // first fix the cycle X is in
  while (tgt[icur[n]] != n) {
    int n_ind = icur[n];
    int swap_ind = icur[tgt[n_ind]];
    s.pb((n + swap_ind - icur[n]) % (n + 1));
    swap(icur[n], icur[cur[swap_ind]]);
    swap(cur[n_ind], cur[swap_ind]);
    // for (int i = 0; i <= n; i++) {
    //   cout << cur[i] << " \n"[i == n];
    // }
    // for (int i = 0; i <= n; i++) {
    //   cout << tgt[i] << " \n"[i == n];
    // }
    // cout << endl;
  }

  for (int i = 0; i <= n; i++) {
    // fix cycle for each unfixed index
    if (cur[i] != tgt[i]) {
      int n_ind = icur[n];
      int swap_ind = icur[tgt[i]];
      s.pb((n + swap_ind - icur[n]) % (n + 1));
      swap(icur[n], icur[cur[swap_ind]]);
      swap(cur[n_ind], cur[swap_ind]);

      while (tgt[icur[n]] != n) {
        int n_ind = icur[n];
        int swap_ind = icur[tgt[n_ind]];
        s.pb((n + swap_ind - icur[n]) % (n + 1));
        swap(icur[n], icur[cur[swap_ind]]);
        swap(cur[n_ind], cur[swap_ind]);
      }
    }
  }

  // ugly ahh logic
  if (s.size() & 1) {
    if (!(odd & bit) || s.size() < odd_s.size()) {
      odd_s = s;
      odd |= bit;
    }
  } else {
    if (!(even & bit) || s.size() < even_s.size()) {
      even_s = s;
      even |= bit;
    }
  }
}

void solve() {
  int n = ri(), m = ri();
  vi a(n), b(m);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    --a[i];
  }
  for (int i = 0; i < m; i++) {
    cin >> b[i];
    --b[i];
  }

  // bitmask for "solution for this parity exists", [0] for a and [1] for b
  int odd = 0, even = 0;
  vi a_odd_s, b_odd_s, a_even_s, b_even_s;

  // solve for each cyclic shift
  for (int i = 0; i <= n; i++) {
    solve_perm(odd, even, 1, a_odd_s, a_even_s, a, i);
  }

  for (int i = 0; i <= m; i++) {
    solve_perm(odd, even, 2, b_odd_s, b_even_s, b, i);
  }

  // ugly ahh code to find the shortest combined seq
  vi as, bs;
  if (odd != 3 && even != 3) {
    cout << "-1" << endl;
    return;
  }

  if (odd == 3) {
    as = a_odd_s;
    bs = b_odd_s;
    if (even == 3 && max(a_even_s.size(), b_even_s.size()) <
                         max(a_odd_s.size(), b_odd_s.size())) {
      as = a_even_s;
      bs = b_even_s;
    }
  } else if (even == 3) {
    as = a_even_s;
    bs = b_even_s;
  }

  cout << max(as.size(), bs.size()) << endl;
  int i = 0;
  while (i < min(as.size(), bs.size())) {
    cout << (as[i] + 1) << " " << (bs[i++] + 1) << endl;
  }
  while (i < as.size()) {
    cout << (as[i] + 1) << " " << ((i & 1) ? 1 : m) << endl;
    i++;
  }
  while (i < bs.size()) {
    cout << ((i & 1) ? 1 : n) << " " << (bs[i] + 1) << endl;
    i++;
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
