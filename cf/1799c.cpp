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

const int inf = 1e9 + 7;
const int mod = inf;
const ll infll = 0x3f3f3f3f3f3f3f3fll;

int main() {
  cin.tie(0) -> sync_with_stdio(0);

  int t; cin >> t;
  while (t--) {
    string s; cin >> s;
    int n = s.length();
    mi f;
    for (char c : s) {
      ++f[c];
    }
    stringstream ret, end;
    vc<char> bruh;
    for (int i = 'a'; i <= 'z'; ++i) {
      if (f[i] && bruh.size() && n - f[i]) {
        end << bruh[0];
        for (int j = i; j <= 'z'; ++j) {
          while(f[j]) {
            ret << char(j);
            --f[j];
          }
        }
        bruh.clear();
        break;
      }
      while (f[i] >= 2) {
        ret << char(i);
        end << char(i);
        f[i] -= 2;
        n -= 2;
      }
      if (f[i]) {
        bruh.pb(char(i));
        --n;
        if (bruh.size() == 2) {
          ret << bruh[1];
          end << bruh[0];
          for (int j = i + 1; j <= 'z'; ++j) {
            while (f[j]) {
              ret << char(j);
              --f[j];
            }
          }
          break;
        }
      }
    }
    if (bruh.size() == 1) {
      ret << bruh[0];
    }
    string rets, ends;
    ret >> rets;
    end >> ends;
    reverse(ends.begin(), ends.end());
    cout << rets << ends << endl;
  }
}
