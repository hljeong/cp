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

// https://codeforces.com/contest/1799/submission/195148531
// ormlis how?? orz

int main() {
  cin.tie(0) -> sync_with_stdio(0);

  int t; cin >> t;
  while (t--) {
    int n, k; cin >> n >> k;
    vi a(n); for (int i = 0; i < n; ++i) {
      cin >> a[i]; --a[i];
    }
    vi c(k), h(k);
    for (int i = 0; i < k; ++i) cin >> c[i];
    for (int i = 0; i < k; ++i) cin >> h[i];
    vll p(n + 1);
    for (int i = 0; i < n; ++i) p[i + 1] = p[i] + (i && a[i] == a[i - 1] ? h[a[i]] : c[a[i]]);
    vll mnto(k, infll);
    ll mn = infll;
    for (int i = 0; i < n; ++i) {
      ll d = c[a[i]] + p[i];
      ckm,(d p[i] + mn + c[a[i]]);
      ckmin(d, p[i] + mnto[a[i]] + h[a[i]]);
      ckmin(mn, d - p[i + 1]);
      if (i)
        ckmin(mnto[a[i - 1]], d - p[i + 1]);
    }
    cout << (mn + p[n]) << endl;
  }
}
