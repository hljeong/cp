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
template<class T> bool ckmax(T &a, const T &b) { return a < b ? a = b, 1 : 0; }

const int inf = 1e9 + 7;
const int mod = inf;
const ll infll = 0x3f3f3f3f3f3f3f3fll;

int main() {
  int h, w, k; cin >> h >> w >> k;
  vc<vc<pii>> g(w, vc<pii>(h));
  vi p(w);
  for (int i = 0; i < h * w; ++i) {
    int c; cin >> c; --c;
    g[c][p[c]++] = {i, i & 1};
  }
  vc<vc<pii>> md(h + w - 1), ad(h + w - 1);
  for (int i = 0; i < w; ++i) {
    for (int j = 0; j < h; ++j) {
      md[i + j].pb(g[i][j]);
      ad[i + (h - 1) - j].pb(g[i][j]);
    }
  }
  int winner = -1, t = h * w;
  for (int i = 0; i < w; ++i) {
    int i1 = 0, i2 = 0;
    array<int, 2> cnt = {0};
    set<pii> cur;
    if (h < k) continue;
    while (i2 < k) {
      cur.insert(g[i][i2]);
      ++cnt[g[i][i2++].B];
    }
    while (i2 <= h) {
      if (cnt[0] == k) {
        if (ckmin(t, (*--cur.end()).A)) winner = 0;
      } else if (cnt[1] == k) {
        if (ckmin(t, (*--cur.end()).A)) winner = 1;
      }
      if (i2 == h) break;
      cur.erase(g[i][i1]);
      --cnt[g[i][i1++].B];
      cur.insert(g[i][i2]);
      ++cnt[g[i][i2++].B];
    }
  }
  for (int i = 0; i < h; ++i) {
    int i1 = 0, i2 = 0;
    array<int, 2> cnt = {0};
    set<pii> cur;
    if (w < k) continue;
    while (i2 < k) {
      cur.insert(g[i2][i]);
      ++cnt[g[i2++][i].B];
    }
    while (i2 <= w) {
      if (cnt[0] == k) {
        if (ckmin(t, (*--cur.end()).A)) winner = 0;
      } else if (cnt[1] == k) {
        if (ckmin(t, (*--cur.end()).A)) winner = 1;
      }
      if (i2 == w) break;
      cur.erase(g[i1][i]);
      --cnt[g[i1++][i].B];
      cur.insert(g[i2][i]);
      ++cnt[g[i2++][i].B];
    }
  }
  for (int i = 0; i < h + w - 1; ++i) {
    int m = md[i].size(), i1 = 0, i2 = 0;
    array<int, 2> cnt = {0};
    set<pii> cur;
    if (m < k) continue;
    while (i2 < k) {
      cur.insert(md[i][i2]);
      ++cnt[md[i][i2++].B];
    }
    while (i2 <= m) {
      if (cnt[0] == k) {
        if (ckmin(t, (*--cur.end()).A)) winner = 0;
      } else if (cnt[1] == k) {
        if (ckmin(t, (*--cur.end()).A)) winner = 1;
      }
      if (i2 == m) break;
      cur.erase(md[i][i1]);
      --cnt[md[i][i1++].B];
      cur.insert(md[i][i2]);
      ++cnt[md[i][i2++].B];
    }
  }
  for (int i = 0; i < h + w - 1; ++i) {
    int m = ad[i].size(), i1 = 0, i2 = 0;
    array<int, 2> cnt = {0};
    set<pii> cur;
    if (m < k) continue;
    while (i2 < k) {
      cur.insert(ad[i][i2]);
      ++cnt[ad[i][i2++].B];
    }
    while (i2 <= m) {
      if (cnt[0] == k) {
        if (ckmin(t, (*--cur.end()).A)) winner = 0;
      } else if (cnt[1] == k) {
        if (ckmin(t, (*--cur.end()).A)) winner = 1;
      }
      if (i2 == m) break;
      cur.erase(ad[i][i1]);
      --cnt[ad[i][i1++].B];
      cur.insert(ad[i][i2]);
      ++cnt[ad[i][i2++].B];
    }
  }
  if (winner == -1) {
    cout << "D" << endl;
  } else if (!winner) {
    cout << "A " << (t + 1) << endl;
  } else {
    cout << "B " << (t + 1) << endl;
  }
}
