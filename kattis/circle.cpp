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
  int n, k; cin >> n >> k;
  string str; cin >> str;
  set<string> st;
  for (int i = 0; i < k; ++i) {
    stringstream ss;
    for (int j = 0; j < n; ++j) {
      ss << (str[j] == str[(j + 1) % n] ? 'B' : 'W');
    }
    ss >> str;
  }
  // cout << str << endl;
  st.insert(str);
  int ret = 0;
  for (int i = 0; i < k; ++i) {
    ret = 0;
    set<string> nst, check;
    for (string s : st) {
      stringstream b, w;
      b << 'B';
      w << 'W';
      char lb = 'B', lw = 'W';
      for (int j = 0; j < n - 1; ++j) {
        if (s[j] == 'W') {
          lb ^= 'B' ^ 'W';
          lw ^= 'B' ^ 'W';
        }
        b << lb;
        w << lw;
      }
      string bs, ws; b >> bs; w >> ws;
      bool bgood = true;
      if (i < k - 1) for (char c : bs) bgood ^= c == 'W';
      if (!check.count(bs) && bgood) {
        ++ret;
        for (int i = 0; i < n; ++i) check.insert(bs.substr(i, n - i) + bs.substr(0, i));
        nst.insert(bs);
      }
      bool wgood = true;
      if (i < k - 1) for (char c : ws) wgood ^= c == 'W';
      if (!check.count(ws) && wgood) {
        ++ret;
        for (int i = 0; i < n; ++i) check.insert(ws.substr(i, n - i) + ws.substr(0, i));
        nst.insert(ws);
      }
    }
    // for (string sss : nst) cout << sss << ' ';
    // cout << endl;
    st = nst;
  }
  cout << ret << endl;
}
