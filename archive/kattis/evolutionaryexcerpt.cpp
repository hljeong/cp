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
  string a, b; cin >> a >> b;
  vc<queue<int>> q(8);
  for (int i = 0; i < n; ++i) {
    if (a[i] == 'A') {
      q[0].push(i);
    } else if (a[i] == 'T') {
      q[1].push(i);
    } else if (a[i] == 'C') {
      q[2].push(i);
    } else if (a[i] == 'G') {
      q[3].push(i);
    }
    if (b[i] == 'A') {
      q[4].push(i);
    } else if (b[i] == 'T') {
      q[5].push(i);
    } else if (b[i] == 'C') {
      q[6].push(i);
    } else if (b[i] == 'G') {
      q[7].push(i);
    }
  }
  string ret;
  int cur1 = 0, cur2 = 0;
  while (true) {
    int mn = n, which = -1;
    for (int i = 0; i < 4; ++i) {
      if (q[i].size() && q[4 + i].size() && ckmin(mn, max(q[i].front(), q[4 + i].front()))) {
        which = i;
      } 
    }
    if (which == -1) break;
    cur1 = q[which].front();
    cur2 = q[4 + which].front();
    if (which == 0) ret += "A";
    else if (which == 1) ret += "T";
    else if (which == 2) ret += "C";
    else if (which == 3) ret += "G";
    for (int i = 0; i < 4; ++i) while (q[i].size() && q[i].front() <= cur1) q[i].pop();
    for (int i = 4; i < 8; ++i) while (q[i].size() && q[i].front() <= cur2) q[i].pop();
  }
  cout << ret << endl;
}
