#include <bits/stdc++.h>
#define A first
#define B second
#define vc vector
using namespace std;
using ll = long long;
using ld = long double;
using vi = vc<int>;
using vll = vc<ll>;
using pii = pair<int, int>;

template<class T> bool ckmin(T& a, const T& b) { return b < a ? a = b, 1 : 0; }
template<class T> bool ckmax(T& a, const T& b) { return a < b ? a = b, 1 : 0; }

int calc(vi &h, int s) {
  int ans = 0;
  vi f(9);
  for (int i : h) ++f[i];
  for (int p = 0; p < 9; ++p) {
    if (f[p] < 2) continue;
    vi tf = f;
    tf[p] -= 2;
    bool good = true;
    for (int i = 0; i < 9; ++i) if ((tf[i] %= 3) && (i > 6 || (tf[i + 1] -= tf[i]) < 0 || (tf[i + 2] -= tf[i]) < 0) && !(good = false)) continue;
    if (ans = good) break;
  }
  if (ans) for (int i : h) ans += i == s;
  return ans;
}

int main() {
  int x;
  cin >> x, --x;
  vi h(14), f(9, 4);
  for (int i = 0; i < 14; ++i) cin >> h[i], --h[i], --f[h[i]]; 
  ld ans = 0;
  for (int i = 0; i < 14; ++i) {
    int tmp = h[i];
    ld s = 0;
    for (int j = 0; j < 9; ++j) {
      h[i] = j;
      s += calc(h, x) * f[j];
    }
    ckmax(ans, s / 22.0);
    h[i] = tmp;
  }
  cout << setprecision(12) << ans << endl;
}