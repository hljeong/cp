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

bool good(string a, string b) {
  for (int i = 0; i <= b.length() - a.length(); ++i) {
    if (a == b.substr(i, a.length())) return true;
  }
  return false;
}

int main() {
  int n;
  cin >> n;
  vc<pair<int, string>> s;
  for (int i = 0; i < n; ++i) {
    string str;
    cin >> str;
    s.push_back({str.length(), str});
  }
  sort(s.begin(), s.end());
  bool bad = false;
  for (int i = 1; i < n; ++i) {
    if (!good(s[i - 1].B, s[i].B)) bad = true;
  }
  cout << (bad ? "NO" : "YES") << endl;
  if (!bad) {
    for (int i = 0; i < n; ++i) cout << s[i].B << endl;
  }
}