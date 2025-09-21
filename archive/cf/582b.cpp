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

vc<vi> mul(const vc<vi>& a, const vc<vi>& b) {
  int n = a.size();
  vc<vi> ret(n, vi(n, -inf));
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      for (int k = 0; k < n; ++k) {
        ckmax(ret[i][j], a[i][k] + b[k][j]);
      }
    }
  }
  return ret;
}

vc<vi> fpow(vc<vi> b, ll e) {
  int n = b.size();
  vc<vi> ret(n, vi(n));
  while (e) {
    if (e & 1) {
      ret = mul(ret, b);
    }
    b = mul(b, b);
    e >>= 1;
  }
  return ret;
}

template<class T> T minst(function<bool(T)> pred, T i, T j) {
  T ret = j + 1;
  for (T l = i, r = j, m; l <= r; ) {
    if (pred(m = l + (r - l) / 2)) r = (ret = m) - 1;
    else l = m + 1;
  }
  return ret;
}

template<class T> T maxst(function<bool(T)> pred, T i, T j) {
  T ret = i - 1;
  for (T l = i, r = j, m; l <= r; ) {
    if (pred(m = l + (r - l) / 2)) l = (ret = m) + 1;
    else r = m - 1;
  }
  return ret;
}

int main() {
  cin.tie(0) -> sync_with_stdio(0);

  int n, t; cin >> n >> t;
  vi a(n); for (int i = 0; i < n; ++i) cin >> a[i];
  vc<vi> m(n, vi(n, -inf));
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      if (a[j] < a[i]) continue;
      vi tail(1, -inf);
      for (int k = 0; k < n; ++k) {
        if (a[k] < a[i] || a[k] > a[j]) continue;
        const function<bool(int)> pred = [&](int l) {
          return tail[l] <= a[k];
        };
        int l = maxst(pred, 0, (int) tail.size() - 1);
        if (l == tail.size() - 1) tail.pb(a[k]);
        else if (a[k] < tail[l + 1]) tail[l + 1] = a[k];
        m[i][j] = tail.size() - 1;
      }
    }
  }
  /*
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      cout << m[i][j] << " \n"[j == n - 1];
    }
  }
  */
  int ret = t;
  vc<vi> fin = fpow(m, t);
  /*
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      cout << fin[i][j] << " \n"[j == n - 1];
    }
  }
  */
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      ckmax(ret, fin[i][j]);
    }
  }
  cout << ret << endl;
}
