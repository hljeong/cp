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
  vll s(n); for (int i = 0; i < n; ++i) cin >> s[i];
  sort(s.begin(), s.end());
  ll sum = 0, lsum = 0;
  int last = n;
  for (int i = n - 1; i >= 0; --i) {
    sum += s[i];
    if (sum >= lsum) {
      last = i;
       lsum += sum;
       sum = 0;
    }
  }
  cout << (n - last) << endl;
}