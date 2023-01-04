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
  int t, s, n; cin >> t >> s >> n;
  vi a(n); for (int i = 0; i < n; ++i) cin >> a[i];
  int ct = 0, top = 0;
  for (int i = 0; i < n; ++i) {
    int nt = a[i];
    top = max(0, top - (nt - ct));
    top = s - top;
    ct = nt;
  }
  top = max(0, top - (t - ct));
  cout << top << endl;
}