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

// mle on test 3

void merge(unordered_map<int, int> &a, const unordered_map<int, int> &b) {
  for (auto const &e : b) a[e.A] += e.B;
}

bool subset(const unordered_map<int, int> &a, const unordered_set<int> &b) {
  for (auto const &e : a) if (b.find(e.A) == b.end()) return false;
  return true;
}

int main() {
  cin.tie(0);
  ios::sync_with_stdio(0);

  int n; cin >> n;
  vi a(n); for (int i = 0; i < n; ++i) cin >> a[i];
  vc<vc<unordered_map<int, int>>> st(n, vc<unordered_map<int, int>>());
  for (int i = 0; i < n; ++i) {
    unordered_map<int, int> f;
    f[a[i]] = 1;
    st[i].push_back(f);
  }
  for (int j = 1; (1 << j) <= n; ++j) {
    for (int i = 0; i <= n - (1 << j); ++i) {
      st[i].push_back(st[i][j - 1]);
      merge(st[i][j], st[i + (1 << (j - 1))][j - 1]);
    }
  }
  int q; cin >> q;
  while (q--) {
    int ind, m; cin >> ind >> m; --ind;
    unordered_set<int> b; for (int i = 0; i < m; ++i) {
      int bi; cin >> bi;
      b.insert(bi);
    }
    int ans = 0;
    for (int j = st[ind].size() - 1; j >= 0; --j) {
      if (ind >= n) break;
      if (j >= st[ind].size()) continue;
      if (subset(st[ind][j], b)) {
        ans += 1 << j;
        ind += 1 << j;
      }
    }
    cout << ans << endl;
  }
}
