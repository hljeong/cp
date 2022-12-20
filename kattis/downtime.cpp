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

int main() {
  int n, k; cin >> n >> k;
  vi t(n);
  for (int i = 0; i < n; ++i) {
    int ti; cin >> ti;
    t[i] = ti;
  }
  sort(t.begin(), t.end());
  queue<int> q;
  int ans = 0;
  for (int i = 0; i < n; ++i) {
    while (!q.empty() && q.front() + 1000 <= t[i]) q.pop();
    q.push(t[i]);
    ckmax(ans, (int) q.size());
  }
  cout << (ans + k - 1) / k << endl;
}
