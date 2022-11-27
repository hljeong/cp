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
using gr = vc<vi>; using wgr = vc<vc<pii>>;

template<class T> bool ckmin(T &a, const T &b) { return b < a ? a = b, 1 : 0; }
template<class T> bool ckmax(T &a, const T &b) { return a < b ? a = b, 1 : 0; }

const int inf = 1e9 + 7;
const int mod = inf;
const ll infll = 0x3f3f3f3f3f3f3f3fll;

map<int, string> memo;

string solve(int n) {
  if (memo.count(n)) return memo[n];
  stringstream ret;
  ret << '{';
  for (int i = 0; i < n; ++i) {
    ret << solve(i);
    if (i != n - 1) ret << ',';
  }
  ret << '}';
  return memo[n] = ret.str();
}

int main() {
  memo[0] = "{}";
  int n; cin >> n;
  cout << solve(n) << endl;
}
