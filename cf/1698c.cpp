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
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    vll a(n);
    for (int i = 0; i < n; ++i) cin >> a[i];
    sort(a.begin(), a.end());
    if (a[2] < 0 || a[n - 3] > 0) {
      cout << "NO" << endl;
      continue;
    }
    vll b;
    set<ll> s;
    b.push_back(a[0]);
    s.insert(a[0]);
    for (int i = 1; i < n; ++i) {
      if (a[i] || a[i] != a[i - 1]) {
        b.push_back(a[i]);
        s.insert(a[i]);
      }
    }
    n = b.size();
    bool bad = false;
    for (int i = 0; i < n - 2; ++i) {
      for (int j = i + 1; j < n - 1; ++j) {
        for (int k = j + 1; k < n; ++k) {
          if (s.find(b[i] + b[j] + b[k]) == s.end()) bad = true;
        }
      }
    }
    cout << (bad ? "NO" : "YES") << endl;
  }
}