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

int p10(int x) {
  int ans = 1;
  while (x) x /= 10, ans *= 10;
  return ans;
}

int main() {
  set<int> cands;
  for (int i = 0; 1 << i <= 1000000; ++i) {
    int p2 = 1 << i, p5 = 1;
    while (p2 * p5 <= 1000000) {
      cands.insert(p2 * p5);
      cands.insert(p2 * p5 + 1);
      p5 *= 5;
    }
  } 
  cands.erase(cands.find(1));
  int n;
  cin >> n;
  vc<vll> a(n, vll(20));
  vi p(n);
  for (int i = 0; i < n; ++i) { 
    cin >> a[i][0];
    p[i] = p10(a[i][0]);
    for (int j = 1; j < 20; ++j) a[i][j] = a[i][j - 1] * a[i][j - 1] % p[i];
  }
  for (int ans : cands) {
    bool bad = false;
    for (int i = 0; i < n; ++i) {
      ll res = 1;
      for (int j = 0; j < 20; ++j) if (ans & (1 << j)) res = res * a[i][j] % p[i];
      if (bad |= (res != a[i][0])) break;
    }
    if (bad) continue;
    cout << ans << endl;
    return 0;
  }
  cout << -1 << endl;
}