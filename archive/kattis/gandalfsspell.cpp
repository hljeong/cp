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
  string s; cin >> s;
  map<char, string> m;
  map<string, char> im;
  int i = 0;
  string w;
  bool good = true;
  while (cin >> w) {
    if (i == s.length()) {
      // cout << "bad1" << endl;
      good = false;
      break;
    }
    if (im.find(w) != im.end() && s[i] != im[w]) {
      // cout << "bad2" << endl;
      good = false;
      break;
    } else if (m.find(s[i]) != m.end() && w != m[s[i]]) {
      // cout << "bad3" << endl;
      good = false;
      break;
    } else {
      m[s[i]] = w;
      im[w] = s[i];
    }
    ++i;
  }
  if (i < s.length()) good = false;
  cout << (good ? "True" : "False") << endl;
}
