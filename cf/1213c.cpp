#include <bits/stdc++.h>
#define A first
#define B second
#define vc vector
#define pb push_back
#define endl '\n'
using namespace std;
using ll = long long; using ld = long double;
using vi = vc<int>; using vll = vc<ll>;
using si = set<int>; using sll = set<ll>;
using pi = pair<int, int>; using pll = pair<ll, ll>;
using qi = queue<int>; using mi = map<int, int>;

template<class T> bool ckmin(T &a, const T &b) { return b < a ? a = b, 1 : 0; }
template<class T> bool ckmax(T &a, const T &b) { return a < b ? a = b, 1 : 0; }

constexpr int inf = 1e9 + 7;
constexpr int mod = inf;
constexpr ll infll = 0x3f3f3f3f3f3f3f3fll;

// find period and then compute sums
// impl is v ugly

int main() {
  cin.tie(0) -> sync_with_stdio(0);

  int q; cin >> q;
  while (q--) {
    ll n, m; cin >> n >> m;
    vi cyc;
    ll ret = 0;
    ll cur = 0;
    ll persum = 0;
    int per = 0;
    while (cur < n) {
      cur += m;
      if (cur > n) break;
      int dig = cur % 10;
      if (cyc.size() && cyc[0] == dig) {
        per = cyc.size();
        cur -= m;
        break;
      }
      cyc.pb(dig);
      persum += dig;
      ret += dig;
    }
    if (cur < n) {
      ll nper = (n - cur) / m / per;
      ret += persum * nper;
      cur += nper * per * m;
    }
    int ind = 0;
    while (cur < n) {
      cur += m;
      if (cur > n) break;
      ret += cyc[ind++];
    }
    cout << ret << endl;
  }
}
