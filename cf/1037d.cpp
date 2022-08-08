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
  int n;
  cin >> n;
  vc<vi> g(n);
  for (int i = 1; i < n; ++i) {
    int u, v;
    cin >> u >> v, --u, --v;
    g[u].push_back(v);
    g[v].push_back(u);
  }
  vi a(n), lbl(n), id(n + 1);
  for (int i = 0; i < n; ++i) cin >> a[i], --a[i];
  bool bad = a[0];
  int last = 0;
  for (int i : a) {
    bad |= lbl[i] < last;
    last = lbl[i];
    for (int j : g[i]) if (!lbl[j]) lbl[j] = lbl[i] + n + id[lbl[i] / n + 1];
    id[lbl[i] / n + 1]++;
  }
  cout << (bad ? "No" : "Yes") << endl;
}