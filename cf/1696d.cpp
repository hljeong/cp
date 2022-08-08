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

const int maxn = 3e5 + 5;

int a[maxn], mn[4 * maxn], mx[4 * maxn];

int mid(int l, int r) {
  return l + (r - l) / 2;
}

void pull(int node) {
  if (a[mn[node << 1]] < a[mn[node << 1 | 1]]) {
    mn[node] = mn[node << 1];
  } else {
    mn[node] = mn[node << 1 | 1];
  }
  if (a[mx[node << 1]] > a[mx[node << 1 | 1]]) {
    mx[node] = mx[node << 1];
  } else {
    mx[node] = mx[node << 1 | 1];
  }
}

void build(int node, int l, int r) {
  if (l == r) {
    mn[node] = mx[node] = l;
  } else {
    int m = mid(l, r);
    build(node << 1, l, m);
    build(node << 1 | 1, m + 1, r);
    pull(node);
  }
}

int qmn(int i, int j, int node, int l, int r) {
  if (r < i || j < l) {
    return -1;
  } else if (i <= l && r <= j) {
    return mn[node];
  } else {
    int m = mid(l, r);
    int lf = qmn(i, j, node << 1, l, m), rg = qmn(i, j, node << 1 | 1, m + 1, r);
    if (lf == -1) return rg;
    if (rg == -1) return lf;
    return a[lf] < a[rg] ? lf : rg;
  }
}

int qmx(int i, int j, int node, int l, int r) {
  if (r < i || j < l) {
    return -1;
  } else if (i <= l && r <= j) {
    return mx[node];
  } else {
    int m = mid(l, r);
    int lf = qmx(i, j, node << 1, l, m), rg = qmx(i, j, node << 1 | 1, m + 1, r);
    if (lf == -1) return rg;
    if (rg == -1) return lf;
    return a[lf] > a[rg] ? lf : rg;
  }
}

int solve(int i, int j, int n) {
  if (j - i <= 1) return 0;
  int ans = 0, lb = qmn(i, j, 1, 0, n - 1), rb = qmx(i, j, 1, 0, n - 1);
  ans += abs(rb - lb) - 1;
  ans += solve(i, min(lb, rb), n);
  ans += solve(max(lb, rb), j, n);
  return ans;
}

int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) cin >> a[i];
    build(1, 0, n - 1);
    cout << (n - 1 - solve(0, n - 1, n)) << endl;
  }
}