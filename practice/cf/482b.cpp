#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e5 + 5;
int n, m, l[maxn], r[maxn], q[maxn];
int val[4 * maxn], lazy[4 * maxn];

int mid(int l, int r) {
  return l + (r - l) / 2;
}

int update(int old, int x) {
  return old | x;
}

int merge(int a, int b) {
  return a & b;
}

void push(int seg, int l, int r) {
  val[seg] |= lazy[seg];
  if (l != r) {
    lazy[seg * 2] |= lazy[seg];
    lazy[seg * 2 + 1] |= lazy[seg];
  }
  lazy[seg] = 0;
}

void upd(int i, int j, int x, int seg = 1, int l = 0, int r = n - 1) {
  push(seg, l, r);
  if (r < i || j < l) {
    return;
  } else if (i <= l && r <= j) {
    lazy[seg] = x;
    push(seg, l, r);
  } else {
    int m = mid(l, r);
    upd(i, j, x, seg * 2, l, m);
    upd(i, j, x, seg * 2 + 1, m + 1, r);
    val[seg] = merge(val[seg * 2], val[seg * 2 + 1]);
  }
}

int qry(int i, int j, int seg = 1, int l = 0, int r = n - 1) {
  push(seg, l, r);
  if (r < i || j < l) {
    return (1 << 30) - 1;
  } else if (i <= l && r <= j) {
    return val[seg];
  } else {
    int m = mid(l, r);
    return merge(qry(i, j, seg * 2, l, m), qry(i, j, seg * 2 + 1, m + 1, r));
  }
}

void print(int seg = 1, int l = 0, int r = n - 1) {
  push(seg, l, r);
  if (l == r) {
    cout << val[seg] << ' ';
  } else {
    int m = mid(l, r);
    print(seg * 2, l, m);
    print(seg * 2 + 1, m + 1, r);
  }
}

int main() {
  cin >> n >> m;
  for (int i = 0; i < m; ++i) {
    cin >> l[i] >> r[i] >> q[i], --l[i], --r[i];
    upd(l[i], r[i], q[i]);
  }
  for (int i = 0; i < m; ++i) {
    if (qry(l[i], r[i]) != q[i]) {
      cout << "NO" << endl;
      return 0;
    }
  }
  cout << "YES" << endl;
  print();
}