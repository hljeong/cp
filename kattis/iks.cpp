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

const int maxn = 105, maxx = 1e6 + 5;
int divi[maxx];
map<int, int> f[maxn];

int main() {
  for (int i = 2; i <= 1000000; ++i) {
    if (!divi[i]) {
      int j = i;
      while (j <= 1000000) {
        divi[j] = i;
        j += i;
      }
    }
  }
  
  int n;
  cin >> n;
  map<int, int> pf;
  for (int i = 0; i < n; ++i) {
    int x;
    cin >> x;
    while (divi[x]) {
      ++pf[divi[x]];
      ++f[i][divi[x]];
      x /= divi[x];
    }
  }
  int ans = 1, need = 0;
  for (auto e : pf) {
    for (int i = 0; i < e.B / n; ++i) ans *= e.A;
    for (int i = 0; i < n; ++i) need += max(0, e.B / n - f[i][e.A]);
  }
  cout << ans << ' ' << need << endl;
}