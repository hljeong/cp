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

// math + prefix sums
int main() {
  cin.tie(0) -> sync_with_stdio(0);

  int n; cin >> n;
  vll a(n), b(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i] >> b[i];
  }
  vll suffixa(n + 1), suffixab(n + 1);
  ll suma = 0;
  ll sumsuma = 0;
  ll sumb = 0;
  ll sumab = 0;
  ll suma2b = 0;
  ll aaa = 0, bbb = 0;
  for (int i = 0; i < n; ++i) {
    suma += a[i];
    sumb += b[i];
    sumab += a[i] * b[i];
    suma2b += a[i] * a[i] * b[i];
  }
  for (int i = n - 1; i >= 0; --i) {
    suffixa[i] = suffixa[i + 1] + a[i];
    suffixab[i] = suffixab[i + 1] + a[i] * b[i];
  }
  for (int i = 0; i < n; ++i) {
    aaa += a[i] * b[i] * suffixa[i + 1];
    bbb += a[i] * suffixab[i + 1];
  }
  sumsuma = suma * suma;
  for (int i = 0; i < n; ++i) {
    sumsuma -= a[i] * a[i];
  }
  sumsuma /= 2;

  ll ret = sumb * sumsuma - aaa - bbb;
  cout << ret << endl;
}
