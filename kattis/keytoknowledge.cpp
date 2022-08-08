#include <bits/stdc++.h>
#define A first
#define B second
using namespace std;
using ll = long long;
using dhash = pair<ll, ll>;

const int maxn = 12, maxm = 30;
const ll b1 = 23, b2 = 37, mod1 = 1e8 + 7, mod2 = 1e9 + 7;

dhash chash(vector<int> v) {
  ll hash1 = 0, mult1 = 1, hash2 = 0, mult2 = 1;
  for (int x : v) {
    hash1 += x * mult1;
    mult1 = mult1 * b1 % mod1;
    hash2 += x * mult2;
    mult2 = mult2 * b2 % mod2;
  }
  return {hash1, hash2};
}

int main() {
  int T;
  cin >> T;
  while (T--) {
    int n, m, lm, rm;
    cin >> n >> m;
    rm = m / 2;
    lm = m - rm;
    vector<int> s(n);
    vector<int> c(n);
    for (int i = 0; i < n; ++i) {
      string sr;
      cin >> sr;
      for (int j = 0; j < m; ++j) s[i] |= (sr[j] - '0') << j;
      cin >> c[i];
    }
    map<dhash, int> lcnt, rcnt;
    map<dhash, int> lrep, rrep;
    map<dhash, dhash> mhash;
    for (int mask = 0; mask < (1 << lm); ++mask) {
      vector<int> dist(n), mdist = c;
      bool bad = false;
      for (int i = 0; i < n; ++i) {
        dist[i] = lm - __builtin_popcount((s[i] & ((1 << lm) - 1)) ^ mask);
        if ((mdist[i] -= dist[i]) < 0) bad = true;
      }
      dhash h = chash(dist);
      if (!bad) mhash[h] = chash(mdist);
      ++lcnt[h];
      lrep[h] = mask;
    }
    for (int mask = 0; mask < (1 << rm); ++mask) {
      vector<int> dist(n), mdist = c;
      bool bad = false;
      for (int i = 0; i < n; ++i) {
        dist[i] = rm - __builtin_popcount(((s[i] >> lm) & ((1 << rm) - 1)) ^ mask);
      }
      dhash h = chash(dist);
      ++rcnt[h];
      rrep[h] = mask;
    }
    int ans = 0, sample = 0;
    for (auto const& x : lcnt) {
      if (mhash.find(x.A) != mhash.end() && rcnt[mhash[x.A]]) {
        ans += x.B * rcnt[mhash[x.A]];
        sample = rrep[mhash[x.A]] << lm | lrep[x.A];
      }
    }
    if (ans == 1) {
      for (int i = 0; i < m; ++i) cout << ((sample >> i) & 1);
      cout << endl;
    } else {
      cout << ans << " solutions" << endl;
    }
  }
}