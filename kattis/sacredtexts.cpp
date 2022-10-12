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

int to_num(string s) {
  int ans = 0;
  for (char c : s) {
    ans += (c - '!' + 1);
  }
  return ans - 1;
}

int main() {
  string rune; cin >> rune;
  char c; cin >> c;
  string x; getline(cin, x);
  int offset = (c - 'a' + 26 - to_num(rune) % 26) % 26;
  string line;

  while (getline(cin, line)) {
    stringstream sin; sin << line;
    while (sin >> rune) {
      if (rune == "<") cout << ',';
      else if (rune == ">") cout << '.';
      else if (rune == "0") cout << ' ';
      else cout << (char) ('a' + (to_num(rune) + offset) % 26);
    }
    cout << endl;
  }
}
