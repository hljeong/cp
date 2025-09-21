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
const ld err = 1e-8;

/*
int main() {
  cin.tie(0) -> sync_with_stdio(0);

  int n; cin >> n;
  vc<pair<int, ld>> f(n);
  for (int i = 0; i < n; ++i) cin >> f[i].A >> f[i].B;
  sort(f.begin(), f.end());
  ld ret = 2e9;
  ld l = 0, r = 4e9;
  for (int _ = 0; _ < 50; ++_) {
    ld L = l + (r - l) / 2;
    vc<ld> gx(n), hx(n);
    for (int i = 0; i < n; ++i) {
      gx[i] = f[i].B - L * f[i].A;
      hx[i] = f[i].B + L * f[i].A;
    }
    // cout << L << endl;
    // for (int i = 0; i < n; ++i) cout << gx[i] << " \n"[i == n - 1];
    // for (int i = 0; i < n; ++i) cout << hx[i] << " \n"[i == n - 1];
    // cout << endl;
    bool good = true;
    for (int i = 1; i < n; ++i) {
      if (gx[i - 1] < gx[i] || hx[i - 1] > hx[i]) {
        good = false;
        break;
      }
    }
    if (good) ret = r = L;
    else l = L;
  }
  cout << fixed << setprecision(8) << ret << endl;
}
*/

// sort and find max lipschitz constant between consecutive terms
int main() {
  cin.tie(0) -> sync_with_stdio(0);

  int n; cin >> n;
  vc<pair<int, ld>> f(n);
  for (int i = 0; i < n; ++i) cin >> f[i].A >> f[i].B;
  sort(f.begin(), f.end());
  ld ret = 0;
  for (int i = 1; i < n; ++i) {
    ckmax(ret, fabs(f[i].B - f[i - 1].B) / fabs(f[i].A - f[i - 1].A));
  }
  cout << fixed << setprecision(8) << ret << endl;
}
