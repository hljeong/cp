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

int main() {
  int n, q;
  cin >> n >> q;
  vi p(n);
  vll s(n + 1);
  for (int i = 0; i < n; ++i) cin >> p[i];
  sort(p.rbegin(), p.rend());
  for (int i = 0; i < n; ++i) {
    s[i + 1] = s[i] + p[i];
  }
  for (int i = 0; i < q; ++i) {
    int x, y;
    cin >> x >> y;
    cout << (s[x] - s[x - y]) << endl;
  }
}