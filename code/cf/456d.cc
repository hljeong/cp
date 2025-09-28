#include <bits/stdc++.h>
using namespace std;
using ll = long long;
template <typename T> using vc = vector<T>;
using vi = vc<int>;

#define max(a, b) ((a) > (b) ? (a) : (b))
#define min(a, b) ((a) < (b) ? (a) : (b))

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout << fixed << setprecision(12);

  ll n, m, r, k;
  cin >> n >> m >> r >> k;

  // 5 5 2 1 -> 4 /
  // 5 5 2 9 -> 36

  // fish at (x, y) contributes
  // (min(n, x + r) - max(x, r) + 1) * (min(m, y + r) - max(y, r) + 1) /
  // ((n - r + 1) * (m - r + 1))

  ll denom = (n - r + 1) * (m - r + 1);
  if (k <= (n - r) * (m - r)) {
    cout << ((long double)k * r * r / denom) << endl;
    return 0;
  }

  ll rect = (n - r) * (m - r);
  k -= rect;
  ll nom = rect * r * r;
  ll in = n - r, im = m - r;
  ll h = r, w = r;
  while (k) {
    ll d = min(k, 2 * in + 2 * im);
    k -= d;
    nom += (--h) * w * d;

    d = min(k, 0);
    k -= d;
    nom += h * (--w) * d;
  }
  cout << ((long double)nom / denom) << endl;
}
