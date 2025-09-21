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

int tou(int r, int c) {
  return r * (r + 1) / 2 + c;
}

vc<vc<ld>> gauss(vc<vc<ld>> &c) {
  int n = c.size();
  vc<vc<ld>> inv(n, vc<ld>(n));
  for (int i = 0; i < n; ++i) inv[i][i] = 1;
  for (int i = 0; i < n - 1; ++i) {
    for (int j = i + 1; j < n; ++j) {
      ld mul = c[j][i] / c[i][i];
      for (int k = 0; k < n; ++k) {
        c[j][k] -= c[i][k] * mul;
        inv[j][k] -= inv[i][k] * mul;
      }
    }
  }
  for (int i = n - 1; i > 0; --i) {
    for (int j = i - 1; j >= 0; --j) {
      ld mul = c[j][i] / c[i][i];
      for (int k = 0; k < n; ++k) {
        c[j][k] -= c[i][k] * mul;
        inv[j][k] -= inv[i][k] * mul;
      }
    }
  }
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) inv[i][j] /= c[i][i];
  }
  return inv;
}

int main() {
  int n, h; cin >> n; h = n * (n + 1) / 2;
  vc<ld> v(h); for (int i = 0; i < h; ++i) cin >> v[i];
  vc<vc<ld>> t(h, vc<ld>(h));
  int r = 0, c = 0;
  for (int i = 0; i < h; ++i) {
    ld p0, p1, p2, p3, p4; cin >> p0 >> p1 >> p2 >> p3 >> p4;
    if (r > 0 && c > 0) t[i][tou(r - 1, c - 1)] = -p0;
    if (r > 0 && c < r) t[i][tou(r - 1, c)] = -p1;
    if (r < n - 1) t[i][tou(r + 1, c)] = -p2;
    if (r < n - 1) t[i][tou(r + 1, c + 1)] = -p3;
    t[i][i] = 1;
    v[i] *= p4;
    if (r == c) {
      ++r;
      c = 0;
    } else ++c;
  }
  vc<vc<ld>> inv = gauss(t);
  for (int i = 0; i < h; ++i) {
    for (int j = 0; j < h; ++j) {
      // cout << inv[i][j] << " \n"[j == h - 1];
    }
  }
  ld ret = 0;
  for (int i = 0; i < h; ++i) {
    ret += inv[0][i] * v[i];
  }
  cout << setprecision(12) << fixed << ret << endl;
}
