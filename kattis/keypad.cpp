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
    int r, c;
    cin >> r >> c;
    vc<vi> m(r, vi(c)), mp(r, vi(c));
    set<int> rs, cs;
    for (int i = 0; i < r; ++i) {
      string s;
      cin >> s;
      for (int j = 0; j < c; ++j) {
        m[i][j] = s[j] - '0';
        mp[i][j] = m[i][j] *= 3;
        if (m[i][j]) {
          rs.insert(i);
          cs.insert(j);
        }
      }
    }
    for (int i = 0; i < r; ++i) {
      for (int j = 0; j < c; ++j) {
        if (mp[i][j] == 3) {
          for (int k = 0; k < r; ++k) {
            mp[k][j] |= 1;
          }
          for (int k = 0; k < c; ++k) {
            mp[i][k] |= 2;
          }
        }
      }
    }
    bool good = true;
    for (int i = 0; i < r; ++i) {
      for (int j = 0; j < c; ++j) {
        if (mp[i][j] == 3 && m[i][j] != 3) {
          good = false;
          break;
        }
      }
      if (!good) break;
    }
    if (!good) {
      cout << "impossible" << endl;
      cout << "----------" << endl;
      continue;
    }
    if (rs.size() == 1 || cs.size() == 1) {
      for (int i = 0; i < r; ++i) {
        for (int j = 0; j < c; ++j) {
          if (m[i][j]) cout << 'P';
          else cout << 'N';
        }
        cout << endl;
      }
    } else {
      for (int i = 0; i < r; ++i) {
        for (int j = 0; j < c; ++j) {
          if (m[i][j]) cout << 'I';
          else cout << 'N';
        }
        cout << endl;
      }
    }
    cout << "----------" << endl;
  }
}