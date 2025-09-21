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

int phi(int n) {
  int ret = n;
  for (int i = 2; i * i <= n; i++)
    if (!(n % i)) {
      ret = ret / i * (i - 1);
      while (!(n % i)) n /= i;
    }
  if (n > 1) ret = ret / n * (n - 1);
  return ret;
}

ll gcd(ll a, ll b) {
  return b ? gcd(b, a % b) : a;
}

ll mpow(ll b, ll e, int m) {
  ll ret = 1;
  // cout << "(" << b << " ^ " << e << ") % " << m << " = ";
  while (e) {
    if (e & 1) ret = ret * b % m;
    b = b * b % m;
    e >>= 1;
  }
  // cout << ret << endl;
  return ret;
}

ll exponial(int n, int m) {
  if (m == 1) return 0;
  if (n == 1) return 1;
  if (n == 2) return 2 % m;
  if (n == 3) return 9 % m;
  if (n == 4) return 262144 % m;
  ll g = gcd(n, m);
  ll phim = phi(m);
  ll recur = exponial(n - 1, phim);
  ll ret = g > 1 ? mpow(n, recur + phim, m) : mpow(n, recur, m);
  // cout << "exponial(" << n << ", " << m << ") = " << ret << endl;
  return ret;
}

int main() {
  /*
  for (int i = 1; i <= 1000; ++i) {
    int j = i, cnt = 1;
    while (phi(j) != j) {
      j = phi(j);
      ++cnt;
    }
    cout << i << ": " << cnt << ", " << j << endl;
  }
  */
  int n, m; cin >> n >> m;
  cout << exponial(n, m) << endl;
}