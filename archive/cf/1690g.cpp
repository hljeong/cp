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

// cht??? bro what

void insert(set<pii> &s, pii p) {
  auto nxt = s.lower_bound(p);
  if (nxt != s.begin() && prev(nxt)->B <= p.B) return;
  while (nxt != s.end() && nxt->B >= p.B) {
    s.erase(nxt);
    nxt = s.lower_bound(p);
  }
  s.insert(p);
}

int main() {
  int t;
  cin >> t;
  while (t--) {
    int n, m;
    cin >> n >> m;
    vi a(n);
    set<pii> s;
    for (int i = 0; i < n; ++i) {
      cin >> a[i];
      insert(s, {i, a[i]});
    }
    vi ans(m);
    for (int i = 0; i < m; ++i) {
      int k, d;
      cin >> k >> d, --k;
      insert(s, {k, a[k] -= d});
      ans[i] = s.size();
    }
    for (int i = 0; i < m; ++i) cout << ans[i] << " \n"[i == m - 1];
  }
}