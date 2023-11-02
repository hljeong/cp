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

const int inf = 1e9 + 7;
const int mod = inf;
const ll infll = 0x3f3f3f3f3f3f3f3fll;

// keep ub and lb
int main() {
  cin.tie(0) -> sync_with_stdio(0);

  while (true) {
    int x; cin >> x;
    if (!x) break;
    string _;
    getline(cin, _);
    string resp; getline(cin, resp);
    bool good = true;
    int lb = 1, rb = 10;
    while (resp != "right on") {
      if (good) {
        if (resp == "too high") {
          if (x < lb) good = false;
          ckmin(rb, x - 1);
        } else {
          if (x > rb) good = false;
          ckmax(lb, x + 1);
        }
        if (lb > rb) good = false;
      }
      cin >> x;
      getline(cin, _);
      getline(cin, resp);
    }
    if (x < lb || x > rb) good = false;
    cout << (good ? "Stan may be honest" : "Stan is dishonest") << endl;
  }
}
