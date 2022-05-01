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

int main() {
  int t;
  cin >> t;
  for (int tt = 1; tt <= t; ++tt) {
    int n;
    cin >> n;
    multiset<string> s;
    vi fend(26);
    vi samecnt(26);
    for (int i = 0; i < n; ++i) {
      string si;
      cin >> si;
      s.insert(si);
      if (si[0] != si[si.length() - 1])
        ++fend[si[si.length() - 1] - 'A'];
      else 
        ++samecnt[si[0] - 'A'];
    }
    string ans = "";
    char last = 'a';
    bool bad = false;
    while (s.size()) {
      auto nxt = s.end();
      for (auto it = s.begin(); it != s.end(); ++it) {
        if ((*it)[0] == last && (!samecnt[last - 'A'] || (*it)[it->length() - 1] == last)) {
          nxt = it;
          break;
        }
      }
      if (nxt == s.end()) {
        for (auto it = s.begin(); it != s.end(); ++it) {
          if (!fend[(*it)[0] - 'A'] && (!samecnt[(*it)[0] - 'A'] || (*it)[0] == (*it)[it->length() - 1])) {
            nxt = it;
            break;
          }
        }
      }
      if (nxt == s.end()) {
        bad = true;
        break;
      }
      ans += *nxt;
      if ((*nxt)[0] != (*nxt)[nxt->length() - 1])
        --fend[(*nxt)[0] - 'A'];
      else 
        --samecnt[(*nxt)[0] - 'A'];
      last = (*nxt)[nxt->length() - 1];
      s.erase(nxt);
    }
    vc<bool> f(26);
    for (int i = 0; i < ans.length(); ++i) {
      if (bad) break;
      if (i && ans[i] != ans[i - 1] && f[ans[i] - 'A']) {
        bad = true;
        break;
      }
      f[ans[i] - 'A'] = true;
    }
    // cout << ans << endl;
    cout << "Case #" << tt << ": ";
    if (bad) {
      cout << "IMPOSSIBLE" << endl;
    } else {
      cout << ans << endl;
    }
  }
}