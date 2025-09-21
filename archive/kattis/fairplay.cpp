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
  multiset<pii> s;
  vc<pii> w(n);
  ll a = 0, b = 0;
  for (int i = 0; i < n; ++i) {
    cin >> w[i].A >> w[i].B;
    a += w[i].A;
    b += w[i].B;
  }
  if ((n & 1) || (a % (n / 2)) || (b % (n / 2))) return !printf("impossible\n");
  int as = (int) (a / (n / 2)), bs = (int) (b / (n / 2));
  for (int i = 0; i < n; ++i) {
    pii comp = {as - w[i].A, bs - w[i].B};
    auto it = s.find(comp);
    if (it == s.end()) s.insert(w[i]);
    else s.erase(it);
  }
  cout << (s.size() ? "impossible" : "possible") << endl;
}