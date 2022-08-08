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

const int maxn = 200005;
int n;
ll sgt[4 * maxn];

int mid(int l, int r) { return l + (r - l) / 2; }

int pull(int node) {
  sgt[node] = sgt[node << 1] + sgt[node << 1 | 1];
}

void reset(int node = 1, int l = 0, int r = n - 1) {
  if (l != r) {
    int m = mid(l, r);
    reset(node << 1 , l, m);
    reset(node << 1 | 1, m + 1, r);
  }
  sgt[node] = 0;
}

void upd(int i, int x, int node = 1, int l = 0, int r = n - 1) {
  if (l == r) {
    sgt[node] += x;
  } else {
    int m = mid(l, r);
    if (i <= m) {
      upd(i, x, node << 1, l, m);
    } else {
      upd(i, x, node << 1 | 1, m + 1, r);   
    }
    pull(node);
  }
}

ll qry(int i, int j, int node = 1, int l = 0, int r = n - 1) {
  if (r < i || j < l) {
    return 0;
  } else if (i <= l && r <= j) {
    return sgt[node];
  } else {
    int m = mid(l, r);
    return qry(i, j, node << 1, l, m) + qry(i, j, node << 1 | 1, m + 1, r);
  }
}

int main() {
  int t;
  cin >> t;
  while (t--) {
    ll ans = 0;
    cin >> n;
    vi a(n);
    reset();
    for (int i = 0; i < n; ++i) {
      cin >> a[i];
      --a[i];
      ans += qry(a[i], n - 1);
      upd(a[i], 1);
    }
    cout << ans << endl;
  }
}