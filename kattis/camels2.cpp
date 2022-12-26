#include <bits/stdc++.h>
#define A first
#define B second
using namespace std;
using ll = long long;
using vi = vector<int>;

const int maxn = 2e5 + 5;
int sgt[4 * maxn], n;

int mid(int l, int r) {
  return l + (r - l) / 2;
}

void pull(int node) {
  sgt[node] = sgt[node << 1] + sgt[node << 1 | 1];
}

void upd(int i, int node = 1, int l = 0, int r = n - 1) {
  if (l == r) {
    ++sgt[node];
  } else {
    int m = mid(l, r);
    if (i <= m) upd(i, node << 1, l, m);
    else upd(i, node << 1 | 1, m + 1, r);
    pull(node);
  }
}

int qry(int i, int j, int node = 1, int l = 0, int r = n - 1) {
  if (r < i || j < l) return 0;
  if (i <= l && r <= j) return sgt[node];
  int m = mid(l, r);
  return qry(i, j, node << 1, l, m) + qry(i, j, node << 1 | 1, m + 1, r);
}

int main() {
  cin >> n;
  vi a(n), b(n), c(n);
  for (int i = 0; i < n; ++i) cin >> a[i], --a[i];
  for (int i = 0; i < n; ++i) cin >> b[i], --b[i];
  for (int i = 0; i < n; ++i) cin >> c[i], --c[i];
  ll cnt = 0;
  vi x = a, y = b, imap(n);
  for (int i = 0; i < n; ++i) imap[x[i]] = i;
  memset(sgt, 0, 4 * n * sizeof(int));
  for (int i = 0; i < n; ++i) {
    cnt += qry(imap[y[i]], n - 1);
    upd(imap[y[i]]);
  }
  x = b, y = c;
  for (int i = 0; i < n; ++i) imap[x[i]] = i;
  memset(sgt, 0, 4 * n * sizeof(int));
  for (int i = 0; i < n; ++i) {
    cnt += qry(imap[y[i]], n - 1);
    upd(imap[y[i]]);
  }
  x = a, y = c;
  for (int i = 0; i < n; ++i) imap[x[i]] = i;
  memset(sgt, 0, 4 * n * sizeof(int));
  for (int i = 0; i < n; ++i) {
    cnt += qry(imap[y[i]], n - 1);
    upd(imap[y[i]]);
  }
  // cout << "ans ";
  cout << ((ll) n * (n - 1) - cnt) / 2 << endl;
}