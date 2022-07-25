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
    string s; cin >> s;
    int bal = 0, q = 0;
    for (char c : s) {
      if (c == '(') ++bal;
      else if (c == ')') --bal;
      else ++q;
    }
    bal = -bal;
    vi fix;
    for (int i = 0, e = (q + bal) / 2; i < e; ++i) fix.push_back(1);
    for (int i = 0, e = (q - bal) / 2; i < e; ++i) fix.push_back(-1);
    if (q == abs(bal)) {
      cout << "YES" << endl;
      continue;
    }
    for (int i = 0; i < q - 1; ++i) {
      if (fix[i] ^ fix[i + 1]) {
        swap(fix[i], fix[i + 1]);
        break;
      }
    }
    bal = 0;
    int i = 0;
    bool good = false;
    for (char c : s) {
      if (c == '(') ++bal;
      else if (c == ')') --bal;
      else bal += fix[i++];
      if (bal < 0) {
        good = true;
        break;
      }
    }
    cout << (good ? "YES" : "NO") << endl;
  }
}