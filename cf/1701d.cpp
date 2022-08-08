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
  int t; cin >> t;
  while (t--) {
    int n; cin >> n;
    vi b(n); for (int i = 0; i < n; ++i) cin >> b[i];
    vc<pair<pii, int>> ints; for (int i = 0; i < n; ++i) {
      if (!b[i]) ints.push_back({{i + 1 + 1, n}, i});
      else ints.push_back({{(i + 1) / (b[i] + 1) + 1, min(n, (i + 1) / b[i])}, i});
      // cout << ints[i].A.A << ' ' << ints[i].A.B << endl;
    }
    sort(ints.begin(), ints.end());
    int j = 0;
    priority_queue<pii> pq;
    vi ans(n);
    for (int i = 0; i < n; ++i) {
      while (j < n && ints[j].A.A <= i + 1) pq.push({-ints[j].A.B, ints[j++].B});
      ans[pq.top().B] = i + 1;
      pq.pop();
    }
    for (int i = 0; i < n; ++i) cout << ans[i] << " \n"[i == n - 1];
  }
}