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

const int mod = 1e9 + 7;

int mul(int a, int b) {
  return int(ll(a) * b % mod);
}

int neg(int x) {
  if (!x) return 0;
  return mod - x;
}

int add(int a, int b) {
  int s = a + b;
  if (s >= mod) s -= mod;
  return s;
}

int fpow(int a, ll b) {
  int ans = 1;
  while (b) {
    if (b & 1) ans = mul(ans, a);
    a = mul(a, a);
    b >>= 1;
  }
  return ans;
}

void matmul(pair<pii, pii> &a, pair<pii, pii> &b) {
  a = {{add(mul(a.A.A, b.A.A), mul(a.A.B, b.B.A)), add(mul(a.A.A, b.A.B), mul(a.A.B, b.B.B))}, {add(mul(a.B.A, b.A.A), mul(a.B.B, b.B.A)), add(mul(a.B.A, b.A.B), mul(a.B.B, b.B.B))}};
}

pair<pii, pii> matpow(pair<pii, pii> a, ll b) {
  pair<pii, pii> ans = {{1, 0}, {0, 1}};
  while (b) {
    if (b & 1) matmul(ans, a);
    matmul(a, a);
    b >>= 1;
  }
  return ans;
}

int main() {
  int a, b; ll n; cin >> a >> b >> n;
  int a2 = mul(a, a), b2 = mul(b, b), tab = mul(2, mul(a, b)), a2mb2 = add(a2, neg(b2)), ia2pb2 = fpow(add(a2, b2), mod - 2);
  pair<pii, pii> rot = matpow({{mul(a2mb2, ia2pb2), mul(tab, ia2pb2)}, {mul(neg(tab), ia2pb2), mul(a2mb2, ia2pb2)}}, n + 1);
  cout << neg(rot.A.A) << endl;
}
