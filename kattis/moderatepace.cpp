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

// impl
int main() {
  cin.tie(0) -> sync_with_stdio(0);

  int n; cin >> n;
  vi k(n), a(n), b(n);
  for (int i = 0; i < n; ++i) {
    cin >> k[i];
  }
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }
  for (int i = 0; i < n; ++i) {
    cin >> b[i];
  }
  vi ret(n);
  for (int i = 0; i < n; ++i) {
    vi x;
    x.pb(k[i]);
    x.pb(a[i]);
    x.pb(b[i]);
    sort(x.begin(), x.end());
    ret[i] = x[1];
  }
  for (int i = 0; i < n; ++i) {
    cout << ret[i] << " \n"[i == n - 1];
  }
}
