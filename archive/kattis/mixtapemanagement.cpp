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
  vc<pii> p(n); for (int i = 0; i < n; ++i) {
    cin >> p[i].A;
    p[i].B = i;
  }
  vc<string> ret(n);
  sort(p.begin(), p.end());
  for (int ind = 0; ind < n; ++ind) {
    int i = p[ind].B, j = i - 1;
    while (j != -1 && ret[j] == "") --j;
    if (j != -1) ret[i] = ret[j];
    int m = ret[i].length();
    while (m < ind) {
      ret[i] += '1';
      ++m;
    }
    ret[i] += '2';
  }
  for (int i = 0; i < n; ++i) cout << ret[i] << " \n"[i == n - 1];
}