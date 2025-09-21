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

using ins = array<int, 3>;

int main() {
  int l, s; cin >> l >> s;
  map<pii, ins> fsm;
  for (int i = 0; i < 2 * s; ++i) {
    int ss, ii, t, o, d; cin >> ss >> ii >> t >> o >> d;
    fsm[{ss, ii}] = {t, o, d * 2 - 1};
  }
  bool ret = true;
  for (int in = 0; in < (1 << l); ++in) {
    int p = 0, st = 0, inp = in;
    for (int i = 0; i < l; ++i) {
      auto to = fsm[{st, (inp >> p) & 1}];
      st = to[0];
      inp &= ~(1 << p);
      inp |= to[1] << p;
      p = max(0, p + to[2]);
      if (st == -1) break;
    }
    if (st != -1) {
      ret = false;
      break;
    }
  }
  cout << (int) ret << endl;
}