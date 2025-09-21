#include <bits/stdc++.h>
#define A first
#define B second
#define vc vector
using namespace std;
using ll = long long; using ld = long double;
using vi = vc<int>; using vll = vc<ll>;
using si = set<int>; using sll = set<ll>;
using pii = pair<int, int>; using mii = map<int, int>;
using gr = vc<vi>;

template<class T> bool ckmin(T &a, const T &b) { return b < a ? a = b, 1 : 0; }
template<class T> bool ckmax(T &a, const T &b) { return a < b ? a = b, 1 : 0; }

const int inf = 1e9 + 7;
const int mod = inf;

int main() {
  int n; cin >> n;
  vi bal(1e6 + 5), mn(1e6 + 5);
  vc<pii> m(2 * n);
  int cur = 0;
  si s;
  for (int i = 0; i < n; ++i) {
    string mk; cin >> mk;
    m[i].A = m[n + i].A = mk[0] == 'e';
    m[i].B = m[n + i].B = stoi(mk.substr(1, mk.length() - 1)) - 1;
    if (!s.count(m[i].B)) {
      s.insert(m[i].B);
      ++cur;
    }
  }
  int ind = -1, ret = -1;
  int i = 0, j = 0;
  while (j < n) {
    int x = m[j].B;
    if (!bal[x] && !mn[x]) --cur;
    if (!m[j].A) {
      ++bal[x];
    } else {
      ckmin(mn[x], --bal[x]);
    }
    if (!bal[x] && !mn[x]) ++cur;
    ++j;
  }
  while (i < n) {
    // for (int x : s) cout << x << ": " << bal[x] << ", " << mn[x] << endl;
    // cout << endl;
    if (ckmax(ret, cur)) ind = i + 1;
    int x = m[i].B;
    if (!bal[x] && !mn[x]) --cur;
    if (!m[i].A) {
      --bal[x];
      --mn[x];
    } else {
      ++bal[x];
      ++mn[x];
    }
    if (!bal[x] && !mn[x]) ++cur;
    x = m[j].B;
    if (!bal[x] && !mn[x]) --cur;
    if (!m[j].A) {
      ++bal[x];
    } else {
      ckmin(mn[x], --bal[x]);
    }
    if (!bal[x] && !mn[x]) ++cur;
    ++i; ++j;
  }
  cout << ind << ' ' << ret << endl;
}
