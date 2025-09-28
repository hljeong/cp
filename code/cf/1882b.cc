#include <bits/stdc++.h>
#define A first
#define B second
#define pb push_back
#define endl '\n'
using namespace std;
template <typename T> using vc = vector<T>;
using ll = long long;
using ld = long double;
using vi = vc<int>;
using vll = vc<ll>;
using si = set<int>;
using sll = set<ll>;
using pi = pair<int, int>;
using pll = pair<ll, ll>;
using qi = queue<int>;
using mi = map<int, int>;

template <class T, class U> T max(T a, U b) { return a > b ? a : b; }
template <class T, class U> T min(T a, U b) { return a < b ? a : b; }
template <class T, class U> bool ckmin(T &a, U b) {
  return b < a ? a = b, 1 : 0;
}
template <class T, class U> bool ckmax(T &a, U b) {
  return a < b ? a = b, 1 : 0;
}

constexpr int inf = 1e9 + 7;
constexpr int mod = 1e9 + 7;
constexpr ll infll = 0x3f3f'3f3f'3f3f'3f3fll;

int main() {
  cin.tie(0)->sync_with_stdio(0);

  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    si su;
    vc<si> s;
    for (int i = 0; i < n; i++) {
      int k;
      cin >> k;
      si si;
      for (int j = 0; j < k; j++) {
        int sij;
        cin >> sij;
        si.insert(sij);
        su.insert(sij);
      }
      s.pb(si);
    }
    int ans = 0;
    // try excluding every element
    for (auto excl : su) {
      si sc;
      for (auto si : s) {
        if (!si.count(excl)) {
          for (auto sij : si)
            sc.insert(sij);
        }
      }
      ckmax(ans, sc.size());
    }
    cout << ans << endl;
  }
}
