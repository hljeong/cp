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

// input string forms 2 loops
// impossible if the loop inside the repeated characters has size 0
int main() {
  cin.tie(0) -> sync_with_stdio(0);

  string s; cin >> s;
  for (int i = 0; i < 26; ++i) {
    if (s[i] == s[i + 1]) {
      return !printf("Impossible\n");
    }
  }

  int a, b;
  for (a = 0; a < 25; ++a) {
    bool good = 0;
    for (b = a + 1; b < 27; ++b) {
      if (s[a] == s[b]) {
        good = 1;
        break;
      }
    }
    if (good)
      break;
  }

  string first(13, ' '), second(13, ' ');
  first[(b - a - 1) / 2] = s[a];
  int i = 1;
  for (int j = (b - a - 1) / 2 - 1; j >= 0; --j) {
    first[j] = s[a + i++];
  }
  for (int j = 0; j < (b - a - 1) / 2; ++j) {
    second[j] = s[a + i++];
  }
  if (a + i < b) second[(b - a - 1) / 2] = s[a + i];
  string rest(27 - (b - a) - 1, ' ');
  int j = 0;
  for (i = b + 1; i < 27; ++i) rest[j++] = s[i];
  for (i = 0; i < a; ++i) rest[j++] = s[i];
  j = 0;
  if (second[(b - a - 1) / 2] == ' ') second[(b - a - 1) / 2] = rest[j++];
  for (i = (b - a - 1) / 2 + 1; i < 13; ++i) second[i] = rest[j++];
  for (i = 12; i > (b - a - 1) / 2; --i) first[i] = rest[j++];
  cout << first << endl;
  cout << second << endl;
}
