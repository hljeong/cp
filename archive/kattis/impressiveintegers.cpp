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
  int n; cin >> n;
  if (n == 2 || n == 3 || n == 5) return !printf("impossible");
  if (n == 1) {
    cout << "1 1 1" << endl;
    cout << "A 0 0 U" << endl;
  } else if (n & 1) {
    cout << 4 << ' ' << (n - 5) << ' ' << (2 * n - 6) << endl;
    for (int i = 0; i < n - 4; ++i) {
      cout << 'A' << ' ' << ((i >> 1) * 4) << ' ' << ((i & 1) * 4) << ' ' << (i & 1 ? 'D' : 'U') << endl;
    }
    cout << "B 0 4 U" << endl;
    cout << 'B' << ' ' << (n - 5) << ' ' << 4 << ' ' << 'U' << endl;
    cout << 'B' << ' ' << 0 << ' ' << (n - 1) << ' ' << 'D' << endl;
    cout << 'B' << ' ' << 0 << ' ' << (n - 1) << ' ' << 'U' << endl;
  } else {
    cout << 1 << ' ' << (n / 2 - 1) << ' ' << (n / 2) << endl;
    for (int i = 0; i < n - 1; ++i) {
      cout << 'A' << ' ' << (i >> 1) << ' ' << (i & 1) << ' ' << (i & 1 ? 'D' : 'U') << endl;
    }
    cout << 'B' << ' ' << 0 << ' ' << 1 << ' ' << 'U' << endl;
  }
}