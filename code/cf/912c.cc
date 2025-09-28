#include <bits/stdc++.h>
#include <cstdlib>
using namespace std;
using ll = long long;
template <typename T> using vc = vector<T>;
using vi = vc<int>;
using vll = vc<ll>;
using pii = pair<int, int>;
using mii = map<int, int>;

#define max(a, b) ((a) > (b) ? (a) : (b))
#define min(a, b) ((a) < (b) ? (a) : (b))

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int n, m;
  cin >> n >> m;
  int b, inc, d;
  cin >> b >> inc >> d;
  vll s(n), mx(n), r(n);
  for (int i = 0; i < n; i++) {
    cin >> mx[i] >> s[i] >> r[i];
  }
  vc<vc<pair<ll, ll>>> mp(n);
  for (int i = 0; i < m; i++) {
    ll t, h;
    int e;
    cin >> t >> e >> h;
    --e;
    mp[e].emplace_back(t, h);
  }

  map<ll, int> tl; // timeline
  for (int e = 0; e < n; e++) {
    auto &mpe = mp[e];
    sort(mpe.begin(), mpe.end());
    ll last_t = 0, last_h0 = s[e];
    for (auto &[t, ht] : mpe) {
      // process segment [last_t, t)
      if (mx[e] <= d) {
        // if enemy will always be killable, set segment to 1
        tl[last_t]++;
        tl[t]--;
      } else {
        // enemy might be killable. 3 cases:
        // 1. always unkillable during segment
        // 2. always killable during segment
        // 3. becomes unkillable during segment
        // note that mx[e] is no longer relevant, pretend it doesnt exist
        ll left = last_h0 + last_t * r[e];
        ll right = last_h0 + (t - 1) * r[e];
        if (left > d && right > d) {
          // case 1: no-op
        } else if (left <= d && right <= d) {
          // case 2: set segment to 1
          tl[last_t]++;
          tl[t]--;
        } else {
          // case 3: find intercept
          // min t_ s.t. h0 + t_ * r[e] > d
          // => h0 + t_ * r[e] >= d + 1
          // => t_ * r[e] >= d + 1 - h0
          // => t_ = cdiv(d + 1 - h0, r[e])
          // => t_ = (d - h0) / r[e] + 1
          tl[last_t]++;
          tl[(d - last_h0) / r[e] + 1]--;
        }
      }

      last_t = t;
      last_h0 = ht - t * r[e];
    }

    // dup the logic
    ll left = last_h0 + last_t * r[e];
    ll right = min(min(1'000'000'000ll * r[e] + left, mx[e]), d + 1);
    if (left > d && right > d) {
      // case 1: no-op
    } else if (left <= d && right <= d) {
      // case 2: set segment to 1
      tl[last_t]++;
    } else {
      // case 3: find intercept
      // min t_ s.t. h0 + t_ * r[e] > d
      // => h0 + t_ * r[e] >= d + 1
      // => t_ * r[e] >= d + 1 - h0
      // => t_ = cdiv(d + 1 - h0, r[e])
      // => t_ = (d - h0) / r[e] + 1
      tl[last_t]++;
      tl[(d - last_h0) / r[e] + 1]--;
    }
  }

  ll ret = 0;
  ll cnt = 0;
  for (auto &[t, delta] : tl) {
    if (!delta)
      continue;
    // cout << t << ", " << delta << endl;
    if (t) {
      ll ret_ = cnt * (b + (ll)(t - 1) * inc);
      if (ret_ > ret) {
        ret = ret_;
      }
    }
    cnt += delta;
  }
  if (cnt) {
    if (inc) {
      cout << -1 << endl;
      return 0;
    } else {
      ll ret_ = cnt * b;
      if (ret_ > ret) {
        ret = ret_;
      }
    }
  }
  cout << ret << endl;

#ifdef works_but_holy_shit
  map<ll, int> tl;
  for (int e = 0; e < n; e++) {
    auto &mpe = mp[e];
    ll h0 = s[e];
    if (h0 <= d) {
      tl[0]++;
      if (r[e] && mx[e] > d) {
        // will become unkillable in the future
        tl[(d - h0) / r[e] + 1]--;
      }
    }
    sort(mpe.begin(), mpe.end());
    for (auto &[t, ht_] : mpe) {
      ll htm1 = min(mx[e], h0 + (ll)(t - 1) * r[e]);
      ll ht = min(mx[e], h0 + (ll)t * r[e]);
      if (htm1 <= d && r[e] && mx[e] > d) {
        // wouldve become unkillable at t or later; undo
        tl[(d - h0) / r[e] + 1]++;
      }

      if (htm1 > d && ht_ <= d) {
        tl[t]++;
      } else if (htm1 <= d && ht_ > d) {
        tl[t]--;
      }

      // h0 += (ht_ - ht);

      // ht_ = h0_ + t * r[e]
      h0 = ht_ - t * r[e];

      if (ht_ <= d && r[e] && mx[e] > d) {
        // will become unkillable in future
        // find min t_ such that h0 + t_ * r[e] > d
        // t_ = (d - h0 + 1 + r[e] - 1) / r[e]
        tl[(d - h0) / r[e] + 1]--;
      }
    }
  }
  ll ret = 0;
  ll cnt = 0;
  for (auto &[t, delta] : tl) {
    // cout << t << ", " << delta << endl;
    if (t) {
      ll ret_ = cnt * (b + (ll)(t - 1) * inc);
      if (ret_ > ret) {
        ret = ret_;
      }
    }
    cnt += delta;
  }
  if (cnt) {
    if (inc) {
      cout << -1 << endl;
      return 0;
    } else {
      ll ret_ = cnt * b;
      if (ret_ > ret) {
        ret = ret_;
      }
    }
  }
  cout << ret << endl;
#endif
}
