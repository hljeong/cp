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

int main() {
  ld t;
  int n, ans = 0;
  cin >> t >> n;
  vi w(n);
  multiset<pair<ld, int>> s;
  for (int i = 0; i < n; ++i) {
    cin >> w[i];
    s.insert({w[i], 1});
  }
  // cout << '{';
  // for (auto pr : s) cout << pr.A << ' ' << pr.B << ", ";
  // cout << '}' << endl;
  while (s.begin()->A < t * s.rbegin()->A) {
    auto p = *s.rbegin();
    s.erase(--s.end());
    p.A *= (ld) p.B / (p.B + 1);
    ++p.B;
    ++ans;
    s.insert(p);
    // cout << '{';
    // for (auto pr : s) cout << pr.A << ' ' << pr.B << ", ";
    // cout << '}' << endl;
  }
  cout << ans << endl;
}