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
  int h, w, l, r, cnt = 0;
  ld sum = 0;
  cin >> h >> w;
  for (int i = 0; i < h; ++i) {
    string s;
    cin >> s;
    l = w;
    r = 0;
    for (int j = 0; j < w; ++j) {
      if (s[j] != '.') {
        ckmin(l, j);
        ckmax(r, j);
        sum += j + 0.5;
        ++cnt;
      }
    }
  }
  ld cgx = sum / cnt;
  cout << (cgx < l ? "left" : cgx > r + 1 ? "right" : "balanced") << endl;
}