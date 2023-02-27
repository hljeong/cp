#include <bits/stdc++.h>
#define A first
#define B second
#define vc vector
#define pb push_back
using namespace std;
using ll = long long; using ld = long double;
using vi = vc<int>; using vll = vc<ll>;
using si = set<int>; using sll = set<ll>;
using pii = pair<int, int>; using pll = pair<ll, ll>;
using mii = map<int, int>;

template<class T> bool ckmin(T &a, const T &b) { return b < a ? a = b, 1 : 0; }
template<class T> bool ckmax(T &a, const T &b) { return a < b ? a = b, 1 : 0; }

const int inf = 1e9 + 7;
const int mod = inf;
const ll infll = 0x3f3f3f3f3f3f3f3fll;

int main() {
  int n; cin >> n;
  vc<vi> c(n, vi(n));
  vll cs(n);
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      cin >> c[i][j];
      cs[i] += c[i][j];
    }
  }
  sort(cs.begin(), cs.end());
  ll diff = 0;
  for (int i = 0; i < n / 2; ++i) diff -= cs[i];
  for (int i = n / 2; i < n; ++i) diff += cs[i];
  cout << diff / 2 << endl;
}
