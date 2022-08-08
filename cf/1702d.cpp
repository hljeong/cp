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

template<class T> bool ckmin(T &a, const T &b) { return b < a ? a = b, 1 : 0; }
template<class T> bool ckmax(T &a, const T &b) { return a < b ? a = b, 1 : 0; }

int main() {
  int t; cin >> t;
  while (t--) {
    string w; cin >> w;
    priority_queue<pair<char, int>> pq;
    ll s = 0;
    for (int i = 0; i < w.length(); ++i) {
      s += w[i] - 'a' + 1;
      pq.push({w[i], i});
    }
    int p; cin >> p;
    while (s > p) {
      auto pr = pq.top();
      pq.pop();
      s -= pr.A - 'a' + 1;
    }
    vc<pair<int, char>> v;
    while (pq.size()) {
      v.push_back({pq.top().B, pq.top().A});
      pq.pop();
    }
    sort(v.begin(), v.end());
    string ans = "";
    for (auto pr : v) ans += pr.B;
    cout << ans << endl;
  }
}