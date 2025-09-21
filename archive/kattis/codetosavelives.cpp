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
  string x;
  getline(cin, x);
  while (t--) {
    string a, b;
    getline(cin, a);
    getline(cin, b);
    int alen = a.length(), blen = b.length();
    remove(a.begin(), a.end(), ' ');
    remove(b.begin(), b.end(), ' ');
    a.resize((alen + 1) / 2);
    b.resize((blen + 1) / 2);
    // cout << a << endl;
    // cout << b << endl;
    int ai = stoi(a), bi = stoi(b);
    int ci = ai + bi;
    string c = to_string(ci);
    int n = c.length();
    for (int i = 0; i < n; ++i) cout << c[i] << " \n"[i == n - 1];
  }
}
