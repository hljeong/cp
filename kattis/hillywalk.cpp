#include <bits/stdc++.h>
#define A first
#define B second
#define vc vector
#define pb push_back
#define endl '\n'
using namespace std;
using ll = long long; using ld = long double;
using vi = vc<int>; using vll = vc<ll>;
using si = set<int>; using sll = set<ll>;
using pi = pair<int, int>; using pll = pair<ll, ll>;
using qi = queue<int>; using mi = map<int, int>;

template<class T> bool ckmin(T &a, const T &b) { return b < a ? a = b, 1 : 0; }
template<class T> bool ckmax(T &a, const T &b) { return a < b ? a = b, 1 : 0; }

const int inf = 1e9 + 7;
const int mod = inf;
const ll infll = 0x3f3f3f3f3f3f3f3fll;

using ev = array<int, 4>;

ld integrate(ld a, ld b, ld c, ld l, ld r) {
  ld l2 = l * l, l3 = l2 * l, r2 = r * r, r3 = r2 * r;
  return a / 3 * (r3 - l3) + b / 2 * (r2 - l2) + c * (r - l);
}

// convert to a x^2 + b x + c form
int main() {
  cin.tie(0) -> sync_with_stdio(0);

  int n; cin >> n;
  vc<pair<ld, ev>> q;
  for (int i = 0; i < n; ++i) {
    ld a, b; cin >> a >> b;
    ld x1 = a - sqrt(b), x2 = a + sqrt(b);
    int ca = -1, cb = 2 * a, cc = b - a * a;
    q.pb({ x1, { ca, cb, cc, 1 }});
    q.pb({ x2, { -ca, -cb, -cc, -1 }});
  }
  sort(q.begin(), q.end());
  int cnt = 0;
  ld ret = 0;
  ld a = 0, b = 0, c = 0, lst = -infll;
  constexpr ld err = 1e-6;
  for (int i = 0; i < 2 * n; ++i) {
    // cout << q[i].A << ": " << a << " " << b << " " << c << " " << cnt << endl;
    if (cnt > 1) {
      // cout << "integrating: " << lst << " " << q[i].A << " -> " << integrate(a, b, c, lst, q[i].A) << endl;
      ret += integrate(a, b, c, lst, q[i].A);
    }
    a += q[i].B[0];
    b += q[i].B[1];
    c += q[i].B[2];
    cnt += q[i].B[3];
    lst = q[i].A;
  }
  cout << fixed << setprecision(12) << ret << endl;
}
