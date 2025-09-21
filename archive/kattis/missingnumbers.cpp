#include <bits/stdc++.h>
using namespace std;

// impl
int main() {
  int n, cur = 1; cin >> n;
  bool gj = true;
  for (int i = 0; i < n; ++i) {
    int x; cin >> x;
    while (cur < x) {
      cout << cur++ << endl;
      gj = false;
    }
    ++cur;
  }
  if (gj) cout << "good job" << endl;
}
