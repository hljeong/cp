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

const int maxx = 32005;
int divi[maxx];

int main() {
  for (int i = 2; i <= 32000; ++i) {
    if (!divi[i]) {
      int j = i;
      while (j <= 32000) {
        divi[j] = i;
        j += i;
      }
    }
  }
  
  int n;
  cin >> n;
  while (n--) {
    int x;
    cin >> x;
    vc<pii> ans;
    for (int i = 2; i <= x / 2; ++i) {
      if (divi[i] == i && divi[x - i] == x - i) ans.push_back({i, x - i});
    }
    cout << x << " has " << ans.size() << " representation(s)" << endl;
    for (pii p : ans) cout << p.A << '+' << p.B << endl;
    cout << endl;
  }
}