#include <bits/stdc++.h>
#define A first
#define B second
#define pb push_back
#define endl '\n'
using namespace std;
template <typename T> using vc = vector<T>;
using ll = long long;
using ld = long double;
using vi = vc<int>;
using vll = vc<ll>;
using si = set<int>;
using sll = set<ll>;
using pi = pair<int, int>;
using pll = pair<ll, ll>;
using qi = queue<int>;
using mi = map<int, int>;

#define max(a, b) ((a) > (b) ? (a) : (b))
#define min(a, b) ((a) < (b) ? (a) : (b))
template <class T> bool ckmin(T &a, T &b) { return b < a ? a = b, 1 : 0; }
template <class T> bool ckmax(T &a, T &b) { return a < b ? a = b, 1 : 0; }

constexpr int inf = 1e9 + 7;
constexpr int mod = 1e9 + 7;
constexpr ll infll = 0x3f3f'3f3f'3f3f'3f3fll;

int main() {
  cin.tie(0)->sync_with_stdio(0);

  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    vi a(n);
    for (int i = 0; i < n; i++)
      cin >> a[i];
    int b = 1;
    for (int i = 0; i < n; i++) {
      if (b == a[i]) {
        b++;
      }
      b++;
    }
    cout << (b - 1) << endl;
  }
}
