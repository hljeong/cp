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
template<class T> bool ckmax(T &a, const T &b) { return b > a ? a = b, 1 : 0; }

const int inf = 1e9 + 7;
const int mod = inf;
const ll infll = 0x3f3f3f3f3f3f3f3fll;

int main() {
  int s, n; cin >> s >> n;
  int t = 0;
  priority_queue<int> q;
  for (int i = 1; i < s; ++i) q.push(0);
  vc<pii> ppl(n);
  for (int i = 0; i < n; ++i) {
    cin >> ppl[i].A;
    string tp; cin >> tp;
    ppl[i].B = tp[0] == 'n';
  }
  sort(ppl.begin(), ppl.end());
  bool good = true;
  for (int i = 0; i < n; ++i) {
    if (!ppl[i].B) {
      if (t >= ppl[i].A) {
        good = false;
        break;
      } else ++t;
    } else if (q.size()) {
      int nt = -q.top();
      if (nt >= ppl[i].A) {
        if (t >= ppl[i].B) {
          good = false;
          break;
        } else ++t;
      } else {
        q.pop();
        q.push(-(++nt));
      }
    } else {
      good = false;
      break;
    }
  }
  cout << (good ? "Yes" : "No") << endl;
}