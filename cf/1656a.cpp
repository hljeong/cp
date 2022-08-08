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

const int maxn = 1e5 + 5;
int a[maxn];

int main() {
  int t;
  cin >> t;
  while (t --> 0) {
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) cin >> a[i];
    int x = 0, y = 0;
    for (int i = 1; i < n; ++i) {
      if (a[i] < a[x]) x = i;
      if (a[i] > a[y]) y = i;
    }
    cout << (x + 1) << ' ' << (y + 1) << endl;
  }
}