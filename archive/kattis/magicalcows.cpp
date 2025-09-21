#include <bits/stdc++.h>
#define A first
#define B second
#define vc vector
#define pb push_back
using namespace std;
using ll = long long; using ld = long double;
using vi = vc<int>; using vll = vc<ll>;
using si = set<int>; using sll = set<ll>;
using pii = pair<int, int>; using mii = map<int, int>;

template<class T> bool ckmin(T &a, const T &b) { return b < a ? a = b, 1 : 0; }
template<class T> bool ckmax(T &a, const T &b) { return b > a ? a = b, 1 : 0; }

const int inf = 1e9 + 7;
const int mod = inf;
const ll infll = 0x3f3f3f3f3f3f3f3fll;

int main() {
  int c, n, m; cin >> c >> n >> m;
  vll cows(n);
  for (int i = 0; i < n; ++i) cin >> cows[i];
  vi diff(50);
  for (int i = 0; i < 50; ++i) {
    for (int j = 0; j < n; ++j) {
      if (cows[j] <= c && (cows[j] *= 2) > c) ++diff[i];
    }
  }
  // for (int i = 0; i < 10; ++i) cout << diff[i] << " \n"[i == 9];
  vll ans(51);
  ans[0] = n;
  ll cur = n, doublers = 0;
  for (int i = 0; i <= 50; ++i) {
    doublers *= 2;
    ans[i] = cur + doublers;
    cur -= diff[i];
    doublers += diff[i];
  }
  // for (int i = 0; i <= 10; ++i) cout << ans[i] << " \n"[i == 10];
  while (m --> 0) {
    int d; cin >> d;
    cout << ans[d] << endl;
  }
}
