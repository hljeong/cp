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

const int maxn = 2e5 + 5; 

ll sgt[4 * maxn], lz[4 * maxn], sid = 0;

ll merge(ll a, ll b) { return max(a, b); }

ll merge(ll a, ll b, int l, int r) { return max(a, b); }

int mid(int l, int r) { return l + (r - l) / 2; }

void pull(int u) { sgt[u] = merge(sgt[u << 1], sgt[u << 1 | 1]); }

void push(int u, int l, int r) {
  if (lz[u] != sid) {
    sgt[u] = merge(sgt[u], lz[u], l, r);
    if (l != r) {
      lz[u << 1] = merge(lz[u << 1], lz[u]);
      lz[u << 1 | 1] = merge(lz[u << 1 | 1], lz[u]);
    }
    lz[u] = sid;
  }
}

void build(vll &a, int u = 1, int l = 0, int r = maxn - 1) {
  if (l != r) {
    int m = mid(l, r);
    build(a, u << 1, l, m); build(a, u << 1 | 1, m + 1, r);
    pull(u);
  } else if (l < a.size()) sgt[u] = a[l];
}

void upd(int i, int j, ll v, int u = 1, int l = 0, int r = maxn - 1) {
  push(u, l, r);
  if (r < i || j < l) return;
  else if (i <= l && r <= j) {
    lz[u] = v;
    push(u, l, r);
  } else {
    int m = mid(l, r);
    upd(i, j, v, u << 1, l, m); upd(i, j, v, u << 1 | 1, m + 1, r);
    pull(u);
  }
}

void upd(int i, ll v) { upd(i, i, v); }

ll qry(int i, int j, int u = 1, int l = 0, int r = maxn - 1) {
  push(u, l, r);
  if (r < i || j < l) return sid;
  else if (i <= l && r <= j) return sgt[u];
  else {
    int m = mid(l, r);
    return merge(qry(i, j, u << 1, l, m), qry(i, j, u << 1 | 1, m + 1, r));
  }
}

ll qry(int i) { return qry(i, i); }

int main() {
  int n; cin >> n;
  vi h(n); for (int i = 0; i < n; ++i) cin >> h[i];
  vi a(n); for (int i = 0; i < n; ++i) cin >> a[i];
  vi ch = h; sort(ch.begin(), ch.end()); int id = 0; map<int, int> mp;
  for (int x : ch) mp[x] = id++;
  for (int i = 0; i < n; ++i) upd(mp[h[i]], qry(0, mp[h[i]] - 1) + a[i]);
  cout << qry(0, id - 1) << endl;
}