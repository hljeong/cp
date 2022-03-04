#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e5 + 5;
int n, s[maxn], t;
pair<int, int> val[4 * maxn];

int gcd(int x, int y) {
  return y == 0 ? x : gcd(y, x % y);
}

int mid(int l, int r) {
  return l + (r - l) / 2;
}

pair<int, int> merge(pair<int, int> a, pair<int, int> b) {
  int new_gcd = gcd(a.first, b.first);
  return make_pair(
    new_gcd, 
    (new_gcd == a.first) * a.second + (new_gcd == b.first) * b.second
  );
}

void build(int seg = 1, int l = 0, int r = n - 1) {
  if (l == r) {
    val[seg] = make_pair(s[l], 1);
  } else {
    int m = mid(l, r);
    build(seg * 2, l, m);
    build(seg * 2 + 1, m + 1, r);
    val[seg] = merge(val[seg * 2], val[seg * 2 + 1]);
  }
}

pair<int, int> qry(int i, int j, int seg = 1, int l = 0, int r = n - 1) {
  if (r < i || j < l) {
    return make_pair(0, 0);
  } else if (i <= l && r <= j) {
    return val[seg];
  } else {
    int m = mid(l, r);
    return merge(qry(i, j, seg * 2, l, m), 
                 qry(i, j, seg * 2 + 1, m + 1, r));
  }
}

int main() {
  cin >> n;
  for (int i = 0; i < n; ++i) cin >> s[i];
  build();
  cin >> t;
  for (int i = 0; i < t; ++i) {
    int l, r;
    cin >> l >> r, --l, --r;
    cout << ((r - l + 1) - qry(l, r).second) << endl;
  }
}