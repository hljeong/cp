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

// undercounts xs

const int maxn = 1e6 + 5;

int sgt[4 * maxn], lz[4 * maxn], lf[2 * maxn], rg[2 * maxn], lb[2 * maxn], rb[2 * maxn];

int mid(int l, int r) {
  return l + (r - l) / 2;
}

void push(int node, int l, int r) {
  if (lz[node] != -1) {
    sgt[node] = lz[node];
    if (l != r) {
      lz[node << 1] = lz[node];
      lz[node << 1 | 1] = lz[node];
    }
    lz[node] = -1;
  }
}

void upd(int i, int j, int v, int node = 1, int l = 0, int r = 1e6) {
  push(node, l, r);
  if (j < l || r < i) {
    return;
  } else if (i <= l && r <= j) {
    lz[node] = v;
    push(node, l, r);
  } else {
    int m = mid(l, r);
    upd(i, j, v, node << 1, l, m);
    upd(i, j, v, node << 1 | 1, m + 1, r);
  }
}

int qry(int i, int node = 1, int l = 0, int r = 1e6) {
  push(node, l, r);
  if (l == r) {
    return sgt[node];
  } else {
    int m = mid(l, r);
    if (i <= m) return qry(i, node << 1, l, m);
    else return qry(i, node << 1 | 1, m + 1, r);
  }
}

void upd(int i) {
  if (lf[i] >= 0) {
    lb[i] = lb[lf[i]];
  }
  if (rg[i] >= 0) {
    rb[i] = rb[rg[i]];
  }
}

int main() {
  int n, q;
  cin >> n >> q;
  vc<pair<int, pii>> segs;
  for (int i = 0; i < n; ++i) {
    int x, y, r;
    cin >> x >> y >> r; 
    segs.push_back({y, {x - r, x + r}});
  }
  sort(segs.begin(), segs.end());
  for (int i = 0; i < 4 * maxn; ++i) {
    sgt[i] = lz[i] = -1;
  }
  for (int i = 0; i < 2 * n; ++i) {
    lf[i] = rg[i] = -1; 
    lb[i] = maxn;
    rb[i] = -1;
  }
  for (int i = 0; i < n; ++i) {
    pair<int, pii> seg = segs[i]; 
    int l = seg.B.A, r = seg.B.B;
    int left = qry(l);
    if (left != -1) {
      int ll = segs[left].B.A, lr = segs[left].B.B, lm1 = (ll + lr) / 2, lm2 = (ll + lr + 1) / 2, lp = 2 * l - lm1 - lm2;
      lf[i << 1] = lp <= 0 ? left << 1 : left << 1 | 1;
      rg[i << 1] = lp >= 0 ? left << 1 | 1 : left << 1;
    }
    lb[i << 1] = l;
    rb[i << 1] = l;
    int right = qry(r);
    if (right != -1) {
      int rl = segs[right].B.A, rr = segs[right].B.B, rm1 = (rl + rr) / 2, rm2 = (rl + rr + 1) / 2, rp = 2 * r - rm1 - rm2;
      lf[i << 1 | 1] = rp <= 0 ? right << 1 : right << 1 | 1;
      rg[i << 1 | 1] = rp >= 0 ? right << 1 | 1 : right << 1;
    }
    lb[i << 1 | 1] = r;
    rb[i << 1 | 1] = r;
    upd(l, r, i);
  }
  for (int i = 0; i < 2 * n; ++i) {
    upd(i);
  }
  vi xs, lxs, rxs;
  for (int i = 0; i <= 1e6; ++i) {
    int node = qry(i);
    if (node == -1) {
      xs.push_back(i);
      lxs.push_back(i);
      rxs.push_back(i);
    } else {
      int l = segs[node].B.A, r = segs[node].B.B, m1 = (l + r) / 2, m2 = (l + r + 1) / 2, p = 2 * i - m1 - m2;
      xs.push_back(p <= 0 ? lb[node << 1] : lb[node << 1 | 1]);
      lxs.push_back(p <= 0 ? lb[node << 1] : lb[node << 1 | 1]);
      xs.push_back(p >= 0 ? rb[node << 1 | 1] : rb[node << 1]);
      rxs.push_back(p >= 0 ? rb[node << 1 | 1] : rb[node << 1]);
    }
  }
  sort(xs.begin(), xs.end());
  auto t = unique(xs.begin(), xs.end());
  xs.resize(distance(xs.begin(), t));
  map<int, int> ixs;
  for (int i = 0; i < xs.size(); ++i) {
    ixs[xs[i]] = i;
  }
  for (int i = 0; i < q; ++i) {
    int l, r;
    cin >> l >> r;
    // cout << lxs[l] << ' ' << rxs[r] << endl;
    cout << ixs[rxs[r]] - ixs[lxs[l]] + 1 << endl;
  }
}