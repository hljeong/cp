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
  int n, k; cin >> n >> k;
  map<int, int> f;
  for (int i = 0; i < n; ++i) {
    int x; cin >> x;
    ++f[x];
  }
  int mf = n;
  vi a;
  for (int i = 1; i <= k; ++i) {
    if (ckmin(mf, f[i])) {
      a.clear();
      a.push_back(i);
    } else if (mf == f[i]) a.push_back(i);
  }
  cout << a.size() << endl;
  for (int i = 0; i < a.size(); ++i) {
    cout << a[i] << " \n"[i == a.size() - 1];
  }
}
