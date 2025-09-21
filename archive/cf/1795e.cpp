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

// make hill
int main() {
  cin.tie(0) -> sync_with_stdio(0);

  int t; cin >> t;
  while (t--) {
    int n; cin >> n;
    vi h(n), ha(n), hb(n);
    for (int i = 0; i < n; ++i) {
      cin >> h[i];
      ha[i] = h[i] - i;
    }
    // upto[i] = cost to get h[:i] to be increasing up to h[i - 1] < h[i]
    // from[i] = cost to get h[i + 1:] to be decreasing down from h[i + 1] < h[i]
    vll upto(n), from(n);
    using a3 = array<int, 3>;
    deque<a3> q;
    // { h[i] - i, start index, end index }
    q.pb({ ha[0], 0, 0 });
    for (int i = 1; i < n; ++i) {
      upto[i] = upto[i - 1];
      // take care of things that went to 0
      while (q.size() && q.front()[1] < i - (ha[i] + i)) {
        auto [v, s, e] = q.front(); q.pop_front();
        // last chunk that went to 0, split and push back to front of queue
        if (e >= i - (ha[i] + i)) {
          q.push_front({ v, i - (ha[i] + i), e });
          e = i - (ha[i] + i) - 1;
        }
        // arithmetic series
        upto[i] += (ll) ((v + s) + (v + e)) * (e - s + 1) / 2;
      }
      int tot = 0;
      // cut the rest down to ha[i]
      while (q.size() && q.back()[0] > ha[i]) {
        auto [v, s, e] = q.back(); q.pop_back();
        upto[i] += (ll) (e - s + 1) * (v - ha[i]);
        tot += e - s + 1;
      }
      q.pb({ ha[i], i - tot, i });
    }

    // reverse and do it again for the right side
    for (int i = 0; i < n; ++i) {
      ha[i] = h[n - i - 1] - i;
    }
    q = deque<a3>();
    q.pb({ ha[0], 0, 0 });
    for (int i = 1; i < n; ++i) {
      from[i] = from[i - 1];
      while (q.size() && q.front()[1] < i - (ha[i] + i)) {
        auto [v, s, e] = q.front(); q.pop_front();
        if (e >= i - (ha[i] + i)) {
          q.push_front({ v, i - (ha[i] + i), e });
          e = i - (ha[i] + i) - 1;
        }
        from[i] += (ll) ((v + s) + (v + e)) * (e - s + 1) / 2;
      }
      int tot = 0;
      while (q.size() && q.back()[0] > ha[i]) {
        auto [v, s, e] = q.back(); q.pop_back();
        from[i] += (ll) (e - s + 1) * (v - ha[i]);
        tot += e - s + 1;
      }
      q.pb({ ha[i], i - tot, i });
    }
    reverse(from.begin(), from.end());

    // for (int i = 0; i < n; ++i) cout << upto[i] << " \n"[i == n - 1];
    // for (int i = 0; i < n; ++i) cout << from[i] << " \n"[i == n - 1];

    ll ret = infll;
    for (int i = 0; i < n; ++i) {
      ckmin(ret, h[i] + upto[i] + from[i]);
    }
    cout << ret << endl;
  }
}
