#include <bits/stdc++.h>
using namespace std;
using ll = long long;
template <typename T> using vc = vector<T>;
using vi = vc<int>;

#define max(a, b) ((a) > (b) ? (a) : (b))
#define min(a, b) ((a) < (b) ? (a) : (b))

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  int n;
  cin >> n;
  vc<vi> p(2);
  for (int i = 0; i < n; i++) {
    int pi;
    cin >> pi;
    p[i & 1].push_back(pi);
  }
  ll e18 = ll(1e18);
  vc<vc<ll>> c{{1}, {1}};
  for (int i = 0; i < 2; i++) {
    for (auto p : p[i]) {
      vc<ll> c_;
      for (ll co : c[i]) {
        ll co_ = co;
        while (e18 / co_ >= p) {
          co_ *= p;
          c_.push_back(co_);
        }
      }
      for (auto co : c_)
        c[i].push_back(co);
    }
  }
  sort(c[0].begin(), c[0].end());
  sort(c[1].begin(), c[1].end());
  ll k;
  cin >> k;
  ll ans = e18;
  int m1 = c[0].size(), m2 = c[1].size();
  // for (int i = 0; i < min(m1, 10); i++) {
  //   cout << c[0][i] << " \n"[i == min(m1, 10) - 1];
  // }
  // for (int i = 0; i < min(m2, 10); i++) {
  //   cout << c[1][i] << " \n"[i == min(m2, 10) - 1];
  // }
  for (ll l = 1, r = e18; l <= r;) {
    ll m = l + (r - l) / 2;
    ll cnt = 0;
    for (int i1 = 0, i2 = m2 - 1; i1 < m1 && i2 >= 0; i1++) {
      // cout << "  " << c[0][i1];
      while (i2 >= 0 &&
             (e18 / c[1][i2] < c[0][i1] || c[0][i1] * c[1][i2] > m)) {
        i2--;
      }
      // if (i2 >= 0)
      //   cout << " " << c[1][i2];
      // cout << " -> " << (i2 + 1) << endl;
      cnt += i2 + 1;
    }
    // cout << m << ", " << cnt << endl;
    if (cnt >= k) {
      r = (ans = m) - 1;
    } else {
      l = m + 1;
    }
  }
  cout << ans << endl;
}
