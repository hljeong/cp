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

constexpr int inf = 1e9 + 7;
constexpr int mod = inf;
constexpr ll infll = 0x3f3f3f3f3f3f3f3fll;

// cut days greedily

int main() {
  cin.tie(0) -> sync_with_stdio(0);

  int n; cin >> n;
  vi a(n); for (int i = 0; i < n; ++i) cin >> a[i];
  si seen, in;
  vi d;
  int last = -1;
  if (a[0] < 0) return !printf("-1\n");
  in.insert(a[0]);
  seen.insert(a[0]);
  for (int i = 1; i < n; ++i) {
    if (a[i] > 0) {
      // if already in office or seen then bad
      if (in.count(a[i]) || seen.count(a[i])) return !printf("-1\n");
      in.insert(a[i]);
      seen.insert(a[i]);
    } else {
      // if office empty then bad
      if (!in.size()) return !printf("-1\n");
      if (in.count(-a[i])) in.erase(in.find(-a[i]));
      // if not in office then bad
      else return !printf("-1\n");
      // cut day if office empty
      if (!in.size()) {
        d.pb(i - last);
        last = i;
        seen = si();
      }
    }
  }
  // check if last day is cut (wa on 5)
  if (last != n - 1) return !printf("-1\n");
  cout << d.size() << endl;
  for (int i = 0; i < d.size(); ++i) cout << d[i] << " \n"[i == d.size() - 1];
}
