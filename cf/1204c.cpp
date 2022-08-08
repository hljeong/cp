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

const int inf = 1e9 + 7;

int main() {
  int n;
  cin >> n;
  vc<vi> d(n, vi(n));
  for (int i = 0; i < n; ++i) {
    string s;
    cin >> s;
    for (int j = 0; j < n; ++j) {
      d[i][j] = s[j] - '0';
      if (!d[i][j]) d[i][j] = inf;
    }
  }
  for (int i = 0; i < n; ++i) d[i][i] = 0;
  for (int i = 0; i < n; ++i) for (int j = 0; j < n; ++j) for (int k = 0; k < n; ++k)
    if (d[i][k] < inf && d[k][j] < inf) ckmin(d[i][j], d[i][k] + d[k][j]);
  int m, p, lst, step = 0;
  cin >> m >> p, --p;
  vi ans(1, p);
  lst = p;
  for (int i = 1; i < m; ++i) {
    cin >> p, --p;
    ++step;
    if (d[ans[ans.size() - 1]][p] < step) {
      ans.push_back(lst);
      step = 1;
    }
    lst = p;
  }
  ans.push_back(p);
  cout << ans.size() << endl;
  for (int i = 0; i < ans.size(); ++i) cout << (ans[i] + 1) << " \n"[i == ans.size() - 1];
}