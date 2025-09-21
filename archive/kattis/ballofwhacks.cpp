#include <bits/stdc++.h>
#define A first
#define B second
#define vc vector
#define pb push_back
using namespace std;
using ll = long long; using ld = long double;
using vi = vc<int>; using vll = vc<ll>;
using si = set<int>; using sll = set<ll>;
using pii = pair<int, int>; using mii = map<int, int>;

template<class T> bool ckmin(T &a, const T &b) { return b < a ? a = b, 1 : 0; }
template<class T> bool ckmax(T &a, const T &b) { return b > a ? a = b, 1 : 0; }

const int inf = 1e9 + 7;
const int mod = inf;
const ll infll = 0x3f3f3f3f3f3f3f3fll;

vi apply(vi &f, vi &x) {
  vi ret(30);
  for (int i = 0; i < 30; ++i) {
    ret[i] = f[x[i]];
  }
  return ret;
}

int main() {
  vi idt {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29};
  vi rot {1, 2, 3, 4, 0, 6, 7, 8, 9, 5, 12, 13, 14, 15, 16, 17, 18, 19, 10, 11, 21, 22, 23, 24, 20, 26, 27, 28, 29, 25};
  vi mov {9, 4, 8, 16, 17, 0, 3, 15, 23, 18, 1, 2, 7, 14, 22, 28, 29, 24, 19, 5, 6, 13, 27, 25, 10, 11, 12, 21, 26, 20};
  vi flp {29, 28, 27, 26, 25, 23, 22, 21, 20, 24, 16, 15, 14, 13, 12, 11, 10, 19, 18, 17, 8, 7, 6, 5, 9, 4, 3, 2, 1, 0};
  vc<vi> t; int p = -1;
  for (int i = 0; i < 5; ++i) {
    t.pb(apply(idt, idt)); ++p;
    for (int j = 0; j < i; ++j) t[p] = apply(rot, t[p]);
  }
  for (int i = 0; i < 5; ++i) {
    vi base = apply(idt, idt);
    for (int j = 0; j < i; ++j) base = apply(rot, base);
    base = apply(mov, base);
    for (int j = 0; j < 5; ++j) {
      t.pb(apply(idt, base)); ++p;
      for (int k = 0; k < j; ++k) t[p] = apply(rot, t[p]);
    }
  }
  for (int i = 0; i < 30; ++i) {
    t.pb(apply(flp, t[i])); ++p;
  }
  int n1, n2, n3;
  cin >> n1;
  vi a1(n1);
  for (int i = 0; i < n1; ++i) {
    cin >> a1[i]; --a1[i];
  }
  cin >> n2;
  vi a2(n2);
  for (int i = 0; i < n2; ++i) {
    cin >> a2[i]; --a2[i];
  }
  cin >> n3;
  vi a3(n3);
  for (int i = 0; i < n3; ++i) {
    cin >> a3[i]; --a3[i];
  }
  if (n1 + n2 + n3 != 30) return !printf("No\n");
  for (int i = 0; i < 60; ++i) {
    for (int j = 0; j < 60; ++j) {
      si vtx;
      for (int i1 = 0; i1 < n1; ++i1) {
        vtx.insert(a1[i1]);
      }
      for (int i2 = 0; i2 < n2; ++i2) {
        vtx.insert(t[i][a2[i2]]);
      }
      for (int i3 = 0; i3 < n3; ++i3) {
        vtx.insert(t[j][a3[i3]]);
      }
      if (vtx.size() == 30) return !printf("Yes\n");
    }
  }
  cout << "No" << endl;
}