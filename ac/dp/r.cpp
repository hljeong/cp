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

const int mod = 1e9 + 7; 

int main() {
  int n; ll k, ans = 0; cin >> n >> k;
  vc<vc<vll>> a(63, vc<vll>(n, vll(n)));
  for (int i = 0; i < n; ++i) for (int j = 0; j < n; ++j) cin >> a[0][i][j];
  for (int i = 1; i < 63; ++i) {
    for (int j = 0; j < n; ++j) {
      for (int knd = 0; knd < n; ++knd) {
        for (int l = 0; l < n; ++l) {
          a[i][j][knd] += a[i - 1][j][l] * a[i - 1][l][knd];
          a[i][j][knd] %= mod;
        }
      }
    }
  }
  vc<vll> mat(n, vll(n));
  for (int i = 0; i < n; ++i) mat[i][i] = 1; 
  for (int i = 0; i < 63; ++i) {
    if ((k >> i) & 1) {
      vc<vll> nmat(n, vll(n));
      for (int j = 0; j < n; ++j) {
        for (int knd = 0; knd < n; ++knd) {
          for (int l = 0; l < n; ++l) {
            nmat[j][knd] += mat[j][l] * a[i][l][knd];
            nmat[j][knd] %= mod;
          }
        }
      }
      mat = nmat;
    }
  }
  for (int i = 0; i < n; ++i) for (int j = 0; j < n; ++j) {
    ans += mat[i][j];
    ans %= mod;
  }
  cout << ans << endl;
}