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
using gr = vc<vi>; using wgr = vc<vc<pii>>;

template<class T> bool ckmin(T &a, const T &b) { return b < a ? a = b, 1 : 0; }
template<class T> bool ckmax(T &a, const T &b) { return a < b ? a = b, 1 : 0; }

const int inf = 1e9 + 7;
const int mod = inf;
const ll infll = 0x3f3f3f3f3f3f3f3fll;

pair<map<string, int>, pii> dfs(vc<map<string, int>> &trie, int i, vc<ld> &guess, map<int, string> &a, vi &l) {
  pair<map<string, int>, pii> ret = {map<string, int>(), {0, 0}};
  for (const auto &e : trie[i]) {
    int j = e.B;
    auto r = dfs(trie, j, guess, a, l);
    if (r.A.size() > ret.A.size()) swap(r.A, ret.A);
    ret.B.A += r.B.A;
    ckmax(ret.B.B, r.B.B);
    for (const auto &e2 : r.A) {
      ret.A[e2.A] += e2.B;
      ckmax(ret.B.B, ret.A[e2.A]);
    }
  }
  if (ret.B.A == 0) {
    ++ret.B.A;
    ++ret.B.B;
    ret.A[a[i]] = 1;
  }
  guess[i] = (ld) ret.B.B / ret.B.A;
  l[i] = ret.B.A;
  return ret;
}

int main() {
  int t, n; cin >> t >> n;

  vc<string> q[n];
  string a[n], s, w;
  getline(cin, s);
  for(int i = 0; i < n; i++){
    getline(cin, s);
    istringstream ss(s);
    while (1) {
      ss >> w;
      q[i].push_back(w);
      if (w.find('?') != string::npos)
        break;
    }
    ss >> a[i];
    while (!ss.eof()) {
      ss >> w;
      a[i] += " " + w;
    }
  }

  vc<map<string, int>> trie;
  trie.pb(map<string, int>());
  map<int, string> aa;
  int m = 1;
  for (int i = 0; i < n; ++i) {
    int cur = 0;
    for (string token : q[i]) {
      if (!trie[cur].count(token)) {
        trie.pb(map<string, int>());
        trie[cur][token] = m++;
      }
      cur = trie[cur][token];
    }
    aa[cur] = a[i];
  }

  vc<ld> dp(m), guess(m);
  vi leaves(m);
  dfs(trie, 0, guess, aa, leaves);
  // for (int i = 0; i < m; ++i) cout << guess[i] << " \n"[i == m - 1];
  dp[0] = 0;
  for (int i = 0; i < t; ++i) {
    vc<ld> ndp(m);
    for (int j = 0; j < m; ++j) {
      ld wait = 0;
      for (const auto &e : trie[j]) {
        wait += dp[e.B] * leaves[e.B];
      }
      wait /= leaves[j];
      ndp[j] = max(dp[0] + guess[j], wait);
    }
    dp = ndp;
  }
  cout << setprecision(12) << fixed << dp[0] << endl;
}
