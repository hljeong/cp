#include <bits/stdc++.h>
#define A first
#define B second
#define vc vector
using namespace std;
using ll = long long;
using ld = long double;
using vi = vc<int>;
using vll = vc<ll>;
using pii = pair<int, int>;

template<class T> bool ckmin(T &a, const T &b) { return b < a ? a = b, 1 : 0; }
template<class T> bool ckmax(T &a, const T &b) { return a < b ? a = b, 1 : 0; }

int main() {
  int t, ans = 0, solves = 0;
  cin >> t;
  map<string, bool> solved;
  map<string, int> penalty;
  while (t != -1) {
    string prob; cin >> prob;
    string rights; cin >> rights;
    bool right = rights == "right";
    if (solved[prob]) {
      cin >> t;
      continue;
    }
    if (right) {
      ++solves;
      solved[prob] = true;
      ans += t + penalty[prob];
    } else {
      penalty[prob] += 20;
    }
    cin >> t;
  }
  cout << solves << " " << ans << endl;
}
