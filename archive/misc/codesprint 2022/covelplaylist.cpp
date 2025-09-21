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

template<class T> bool ckmin(T& a, const T& b) { return b < a ? a = b, 1 : 0; }
template<class T> bool ckmax(T& a, const T& b) { return a < b ? a = b, 1 : 0; }

const int maxn = 1005, maxm = 1005;
const int b1 = 29, b2 = 37;
const int m1 = 1000000007, m2 = 100000007;

int n, m;
string s[maxm];

bool check(int k) {
  int cnt = n;
  map<pii, int> h2c;
  map<pii, bool> good;
  {
    pii h = make_pair(0, 0);
    int st = 0, j = 0;
    ll b1k = 1, b2k = 1;
    while (j < k) {
      h.A = (int) ((ll) b1 * h.A % m1);
      h.A += (s[0][j] - 'A' + 1);
      if (h.A >= m1) h.A -= m1;
      h.B = (int) ((ll) b2 * h.B % m2);
      h.B += (s[0][j] - 'A' + 1);
      if (h.B >= m2) h.B -= m2;
      b1k = b1k * b1 % m1;
      b2k = b2k * b2 % m2;
      ++j;
    }
    ++h2c[h];
    good[h] = true;
    while (j < n) {
      h.A = (int) ((ll) b1 * h.A % m1);
      h.A += (s[0][j] - 'A' + 1);
      if (h.A >= m1) h.A -= m1;
      h.A -= (int) (b1k * (s[0][st] - 'A' + 1) % m1);
      if (h.A < 0) h.A += m1;
      h.B = (int) ((ll) b2 * h.B % m2);
      h.B += (s[0][j] - 'A' + 1);
      if (h.B >= m2) h.B -= m2;
      h.B -= (int) (b2k * (s[0][st] - 'A' + 1) % m2);
      if (h.B < 0) h.B += m2;
      ++h2c[h];
      good[h] = true;
      ++st;
      ++j;
    }
    while (st < n - 1) {
      h.A = (int) ((ll) b1 * h.A % m1);
      h.A -= (int) (b1k * (s[0][st] - 'A' + 1) % m1);
      if (h.A < 0) h.A += m1;
      h.B = (int) ((ll) b2 * h.B % m2);
      h.B -= (int) (b2k * (s[0][st] - 'A' + 1) % m2);
      if (h.B < 0) h.B += m2;
      ++h2c[h];
      good[h] = true;
      ++st;
    }
  }
  // for (auto it : h2c) {
  //   cout << "(" << it.A.A << ", " << it.A.B << ") -> " << it.B << endl;
  // }
  for (int i = 1; i < m; ++i) {
    pii h = make_pair(0, 0);
    int st = 0, j = 0;
    ll b1k = 1, b2k = 1;
    while (j < k) {
      h.A = (int) ((ll) b1 * h.A % m1);
      h.A += (s[i][j] - 'A' + 1);
      if (h.A >= m1) h.A -= m1;
      b1k = b1k * b1 % m1;
      h.B = (int) ((ll) b2 * h.B % m2);
      h.B += (s[i][j] - 'A' + 1);
      if (h.B >= m2) h.B -= m2;
      b2k = b2k * b2 % m2;
      ++j;
    }
    if (h2c.find(h) != h2c.end()) {
      if (good[h]) {
        good[h] = false;
        cnt -= h2c[h];
      }
    }
    while (j < n) {
      h.A = (int) ((ll) b1 * h.A % m1);
      h.A += (s[i][j] - 'A' + 1);
      if (h.A >= m1) h.A -= m1;
      h.A -= (int) (b1k * (s[i][st] - 'A' + 1) % m1);
      if (h.A < 0) h.A += m1;
      h.B = (int) ((ll) b2 * h.B % m2);
      h.B += (s[i][j] - 'A' + 1);
      if (h.B >= m2) h.B -= m2;
      h.B -= (int) (b2k * (s[i][st] - 'A' + 1) % m2);
      if (h.B < 0) h.B += m2;
      if (h2c.find(h) != h2c.end()) {
        if (good[h]) {
          good[h] = false;
          cnt -= h2c[h];
        }
      }
      ++st;
      ++j;
    }
    while (st < n - 1) {
      h.A = (int) ((ll) b1 * h.A % m1);
      h.A -= (int) (b1k * (s[i][st] - 'A' + 1) % m1);
      if (h.A < 0) h.A += m1;
      h.B = (int) ((ll) b2 * h.B % m2);
      h.B -= (int) (b2k * (s[i][st] - 'A' + 1) % m2);
      if (h.B < 0) h.B += m2;
      if (h2c.find(h) != h2c.end()) {
        if (good[h]) {
          good[h] = false;
          cnt -= h2c[h];
        }
      }
      ++st;
    }
  }
  // cout << k << ' ' << cnt << endl;
  return cnt >= (n + 1) / 2;
}

int main() {
  cin >> n >> m; 
  for (int i = 0; i < m; ++i) {
    cin >> s[i];
  }
  int ans = -1;
  for (int l = 1, r = n; l <= r; ) {
    int m = (l + r) / 2;
    if (check(m)) {
      ans = m;
      r = m - 1;
    } else l = m + 1;
  }
  cout << ans << endl;
}