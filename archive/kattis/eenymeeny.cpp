#include <bits/stdc++.h>
using namespace std;
#define vc vector
using vi = vc<int>;

const int maxn = 1e5+5;
const int inf = 1e9;

int main() {
  string rr; getline(cin, rr);
  vc<string> r;
  stringstream rrss(rr);
  while (!rrss.eof()) {
    string wd; rrss >> wd;
    r.push_back(wd);
  }
  int n, m = r.size() - 1; cin >> n;
  vc<string> names(n);
  for (int i = 0; i < n; ++i) cin >> names[i];
  vc<string> a, b;
  int cur = 0;
  for (int i = 0; i < n; ++i) {
    cur = (cur + m) % (n - i);
    if (i & 1) b.push_back(names[cur]);
    else a.push_back(names[cur]);
    vc<string> nnames;
    for (int j = 0; j < n - i; ++j) {
      if (j == cur) continue;
      nnames.push_back(names[j]);
    }
    names = nnames;
  }
  cout << a.size() << endl;
  for (string s : a) cout << s << endl;
  cout << b.size() << endl;
  for (string s : b) cout << s << endl;
}