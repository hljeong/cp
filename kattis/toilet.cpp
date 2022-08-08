#include <bits/stdc++.h>
using namespace std;

string s;
char cur;
int ans;

int main() {
  cin >> s;
  cur = s[0];

  ans = 0;
  for (int i = 1, len = s.length(); i < len; ++i) {
    if (cur != s[i]) {
      ++ans;
    }
    if (s[i] != 'U') {
      ++ans;
    }
    cur = 'U';
  }
  cout << ans << endl;

  cur = s[0];
  ans = 0;
  for (int i = 1, len = s.length(); i < len; ++i) {
    if (cur != s[i]) {
      ++ans;
    }
    if (s[i] != 'D') {
      ++ans;
    }
    cur = 'D';
  }
  cout << ans << endl;

  cur = s[0];
  ans = 0;
  for (int i = 1, len = s.length(); i < len; ++i) {
    if (cur != s[i]) {
      ++ans;
    }
    cur = s[i];
  }
  cout << ans << endl;
}