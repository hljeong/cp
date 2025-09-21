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

const int maxn = 2e5 + 5;

int dv[maxn];

int main() {
  for (int i = 2; i <= 2e5; ++i) if (!dv[i]) for (int j = i; j <= 2e5; j += i) dv[j] = i;
  int n;
  cin >> n;
  ll ans = 0;
  map<int, int> cnt;
  for (int i = n; i; --i) {
    int j = i, k = 1;
    while (dv[j]) {
      int d = dv[j], e = 0;
      while (!(j % d)) {
        j /= d;
        e ^= 1;
      }
      if (e) k *= d;
    }
    ++cnt[k];
    ans += cnt[i] * cnt[i];
  }
  cout << ans << endl;
}