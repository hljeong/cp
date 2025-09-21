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

const int inf = 1e9 + 7, inf2 = inf / 2;
const int mod = inf;
const ll infll = 0x3f3f3f3f3f3f3f3fll;

vi f(100001, inf2), len(100001), powt(6);

int fn(int m) {
  for (int n = 2; n <= m; ++n) {
    ld s = ceil(sqrt(n));
    for (int i = 1; i < n; ++i) ckmin(f[n], f[i] + f[n - i]);
    for (int i = 2; i <= s; ++i) ckmin(f[n], f[i] + f[n / i] + f[n % i]);
    for (int i = 1; i < len[n]; ++i) if (len[n % powt[i]] == i) ckmin(f[n], f[n / powt[i]] + f[n % powt[i]]);
  }
  return f[m];
}

int main() {
  for (int i = 1; i < 10; ++i) len[i] = 1;
  for (int i = 10; i < 100; ++i) len[i] = 2;
  for (int i = 100; i < 1000; ++i) len[i] = 3;
  for (int i = 1000; i < 10000; ++i) len[i] = 4;
  for (int i = 10000; i < 100000; ++i) len[i] = 5;
  len[100000] = 6;
  powt[0] = 1;
  powt[1] = 10;
  powt[2] = 100;
  powt[3] = 1000;
  powt[4] = 10000;
  powt[5] = 100000;
  f[0] = 0;
  f[1] = 1;
  int n; cin >> n;
  cout << fn(n) << endl;
}