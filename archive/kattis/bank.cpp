#include <bits/stdc++.h>
#define A first
#define B second
#define vc vector
using namespace std;
using ll = long long; using ld = long double;
using vi = vc<int>; using vll = vc<ll>;
using si = set<int>; using sll = set<ll>;
using pii = pair<int, int>; using mii = map<int, int>;
using gr = vc<vi>;

template<class T> bool ckmin(T &a, const T &b) { return b < a ? a = b, 1 : 0; }
template<class T> bool ckmax(T &a, const T &b) { return a < b ? a = b, 1 : 0; }

const int inf = 1e9 + 7;
const int mod = inf;

int main() {
  int n, t; cin >> n >> t;
  vc<pii> p(n);
  for (int i = 0; i < n; ++i) {
    cin >> p[i].B >> p[i].A;
  }
  sort(p.rbegin(), p.rend());
  priority_queue<int> pq;
  int ct = t - 1, i = 0;
  ll ret = 0;
  while (ct >= 0) {
    while (i < n && p[i].A >= ct) pq.push(p[i++].B);
    if (pq.size()) {
      ret += pq.top();
      pq.pop();
    }
    --ct;
  }
  cout << ret << endl;
}
