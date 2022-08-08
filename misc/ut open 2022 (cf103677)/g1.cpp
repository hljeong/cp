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

int diff(string a, int i, string b, int j, int l) {
  int ans = 0;
  for (int k = 0; k < l; ++k) {
    ans += (a[i + k] != b[j + k]); 
  }
  return ans;
}

int mindiff(string s, string t, int l) {
  int ans = 0;
  for (int i = 0; i < l; ++i) {
    ans += (s[i] != t[i]) * (s[i] != t[l + i]);
  }
  return ans;
}

int main() {
  int n;
  cin >> n;
  string last = "";
  ll ans = 0;
  for (int i = 0; i < n; ++i) {
    string s;
    cin >> s;
    int l = last.length();
    if (!i) {
      last = s;
      continue;
    }
    if (last.length() == s.length()) {
      ans += diff(last, 0, s, 0, l);
    } else {
      ans += diff(s, 0, s, l, l) + mindiff(last, s, l) + 1;
    }
    last = s;
  }
  cout << ans << endl;
}