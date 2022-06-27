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
    vector<pair<string, string>> ans;
    for (int i = 0; i < n; ++i) {
      string name, fcls, cls = "", _;
      cin >> name >> fcls >> _;
      name = name.substr(0, name.length() - 1);
      bool dash = true;
      for (char c : fcls) {
        if (dash) {
          cls += c == 'l' ? 'u' : c == 'u' ? 'l' : 'm';
          dash = false;
        } else if (c == '-') {
          dash = true;
        } else {
          dash = false;
        }
      }
      reverse(cls.begin(), cls.end());
      for (int j = cls.length(); j < 30; ++j) cls += 'm';
      ans.push_back({cls, name});
    }
    sort(ans.begin(), ans.end());
    for (auto p : ans) cout << p.B << endl;
    for (int i = 0; i < 30; ++i) cout << '=';
    cout << endl;
  }
}