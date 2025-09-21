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
  int h1, w1, h2, w2, h3, w3;
  cin >> h1 >> w1 >> h2 >> w2 >> h3 >> w3;
  if (h1 < w1) swap(h1, w1);
  if (h2 < w2) swap(h2, w2);
  if (h3 < w3) swap(h3, w3);
  bool good = false;
  good |= h1 == h2 && h2 == h3 && w1 + w2 + w3 == h1;
  good |= h1 == h2 && h1 + w3 == h3 && w1 + w2 == h3;
  good |= h1 == h3 && h1 + w2 == h2 && w1 + w3 == h2;
  good |= h2 == h3 && h2 + w1 == h1 && w2 + w3 == h1;
  good |= w1 == w2 && w1 + w3 == h3 && h1 + h2 == h3;
  good |= w1 == w3 && w1 + w2 == h2 && h1 + h3 == h2;
  good |= w2 == w3 && w2 + w1 == h1 && h2 + h3 == h1;
  good |= w1 == h2 && w1 + w3 == h3 && h1 + w2 == h3;
  good |= w1 == h3 && w1 + w2 == h2 && h1 + w3 == h2;
  good |= w2 == h3 && w2 + w1 == h1 && h2 + w3 == h1;
  good |= h1 == w2 && h1 + w3 == h3 && w1 + h2 == h3;
  good |= h1 == w3 && h1 + w2 == h2 && w1 + h3 == h2;
  good |= h2 == w3 && h2 + w1 == h1 && w2 + h3 == h1;
  cout << (good ? "YES" : "NO") << endl;
}
