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

template<class T> bool ckmin(T &a, const T &b) { return b < a ? a = b, 1 : 0; }
template<class T> bool ckmax(T &a, const T &b) { return a < b ? a = b, 1 : 0; }

const int inf = 1e9 + 7;
const int mod = inf;
const ll infll = 0x3f3f3f3f3f3f3f3fll;

int mp(char c) {
  if ('A' <= c && c <= 'Z') return c - 'A';
  else if ('0' <= c && c <= '9') return 26 + (c - '0');
  else if (c == ' ') return 36;
  return -1;
}

char inv(int i) {
  if (i < 26) return (char) ('A' + i);
  else if (i < 36) return (char) ('0' + (i - 26));
  else if (i == 36) return ' ';
  return '-';
}

vi matmul(vc<vi> &m, vi v) {
  int n = m.size();
  vi ret(n);
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      ret[i] += m[i][j] * v[j];
      ret[i] %= 37;
    }
  }
  return ret;
}

int main() {
  int n; cin >> n;
  vc<vi> m(n, vi(n));
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) cin >> m[i][j];
  }
  string sr;
  getline(cin, sr);
  getline(cin, sr);
  int l = sr.length(), k = (sr.length() + n - 1) / n;
  vc<vi> s(k, vi(n, 36));
  for (int i = 0; i < l; ++i) s[i / n][i % n] = mp(sr[i]);
  for (int i = 0; i < k; ++i) s[i] = matmul(m, s[i]);
  string ret;
  for (int i = 0; i < k; ++i) for (int j = 0; j < n; ++j) ret += inv(s[i][j]);
  cout << ret << endl;
}
