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
  vi l;
  set<int> ls;
  int li; cin >> li;
  while (li != -1) {
    l.push_back(li);
    ls.insert(li);
    cin >> li;
  }
  for (int li : l) {
    int cnt = 0;
    for (int i = 0; i < 18; ++i) {
      for (int j = i + 1; j < 18; ++j) {
        int nl = li ^ (1 << i) ^ (1 << j);
        if (nl <= li) continue;
        cnt += ls.find(nl) != ls.end();
      }
      int nl = li ^ (1 << i);
      if (nl <= li) continue;
      cnt += ls.find(nl) != ls.end();
    }
    cout << li << ":" << cnt << endl;
  }
}
