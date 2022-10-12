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

template<class T> bool ckmin(T &a, const T &b) { return b < a ? a = b, 1 : 0; }
template<class T> bool ckmax(T &a, const T &b) { return a < b ? a = b, 1 : 0; }

int main() {
  int n; cin >> n;
  vc<ld> p(n); for (int i = 0; i < n; ++i) cin >> p[i];
  vi s(n); for (int i = 0; i < n; ++i) cin >> s;
  vc<vc<vc<ld>>> P(n, vc<vc<ld>>(201, vc<ld>(201)));
}
