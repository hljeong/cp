#include <bits/stdc++.h>
#define A first
#define B second
#define vc vector
#define pb push_back
using namespace std;
using ll = long long; using ld = long double;
using vi = vc<int>; using vll = vc<ll>;
using si = set<int>; using sll = set<ll>;
using pii = pair<int, int>; using pll = pair<ll, ll>;
using mii = map<int, int>;

template<class T> bool ckmin(T &a, const T &b) { return b < a ? a = b, 1 : 0; }
template<class T> bool ckmax(T &a, const T &b) { return a < b ? a = b, 1 : 0; }

const int inf = 1e9 + 7;
const int mod = inf;
const ll infll = 0x3f3f3f3f3f3f3f3fll;

int main() {
  int n, f; cin >> n >> f;
  ll ret = 0;
  priority_queue<ll> pq;
  for (int i = 0; i < n; ++i) {
    ll k, l; cin >> k >> l;
    ret += min(k, l);
    pq.push(max(0ll, min(k, l - k)));
  }
  for (int i = 0; i < f; ++i) {
    ret += pq.top(); pq.pop();
  }
  cout << ret << endl;
}
