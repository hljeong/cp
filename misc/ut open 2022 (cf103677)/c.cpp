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
  vi s(n);
  vll l(n), r(n);
  for (int i = 0; i < n; ++i) {
    cin >> s[i];
  }
  stack<int> q;
  for (int i = 0; i < n; ++i) {
    while (q.size() && s[i] > s[q.top()]) q.pop();
    if (q.size()) l[i] = q.top();
    else l[i] = -1;
    q.push(i);
  }
  while (q.size()) q.pop();
  for (int i = n - 1; i >= 0; --i) {
    while (q.size() && s[i] > s[q.top()]) q.pop();
    if (q.size()) r[i] = q.top();
    else r[i] = n;
    q.push(i);
  }
  for (int i = 0; i < n; ++i) {
    if (i) cout << ' ';
    cout << (i - l[i]) * (r[i] - i);
  }
  cout << endl;
}