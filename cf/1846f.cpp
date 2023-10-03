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

int main() {
  // cin.tie(0) -> sync_with_stdio(0);

  int t; cin >> t;
  while (t--) {
    int n; cin >> n;
    vi a(n);
    vi f(10);
    for (int i = 0; i < n; ++i) {
      cin >> a[i];
      ++f[a[i]];
    }
    cout << "- 0" << endl << flush;
    vi na(n);
    vi nf(10);
    for (int i = 0; i < n; ++i) {
      cin >> na[i];
      ++nf[na[i]];
    }
    int changed = 0;
    for (int i = 1; i <= 9; ++i) {
      if (nf[i] > f[i]) {
        changed = i;
      }
    }
    a = na;
    f = nf;
    if (!changed) {
      cout << "- 0" << endl << flush;
      for (int i = 1; i <= 9; ++i) nf[i] = 0;
      for (int i = 0; i < n; ++i) {
        cin >> na[i];
        ++nf[na[i]];
      }
      for (int i = 1; i <= 9; ++i) {
        if (nf[i] > f[i]) {
          changed = i;
        }
      }
      a = na;
      f = nf;
    }
    vi rem;
    for (int i = 0; i < n; ++i) {
      if (a[i] != changed) {
        rem.pb(i + 1);
      }
    }
    cout << "- " << rem.size();
    for (int i : rem) cout << " " << i;
    cout << endl << flush;
    n -= rem.size();
    for (int i = 0; i < n; ++i) {
      cin >> na[i];
    }
    bool done = false;
    for (int i = 0; i < n; ++i) {
      if (na[i] != changed) {
        cout << "! " << (i + 1) << endl << flush;
        done = true;
        break;
      }
    }
    if (done) continue;
    cout << "- 0" << endl << flush;
    for (int i = 0; i < n; ++i) {
      cin >> na[i];
    }
    for (int i = 0; i < n; ++i) {
      if (na[i] != changed) {
        cout << "! " << (i + 1) << endl << flush;
        done = true;
        break;
      }
    }
  }
}
