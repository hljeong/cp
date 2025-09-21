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

void sorts(vi &a, vi& inds) {
  vi sorted;
  for (int i : inds) sorted.pb(a[i]);
  sort(sorted.begin(), sorted.end());
  for (int i = 0; i < inds.size(); ++i) a[inds[i]] = sorted[i];
}

int main() {
  int n; cin >> n;
  vc<pii> ap(n);
  for (int i = 0; i < n; ++i) {
    cin >> ap[i].A;
    ap[i].B = i;
  }
  vi a(n), ia(n);
  sort(ap.begin(), ap.end());
  for (int i = 0; i < n; ++i) {
    a[ap[i].B] = i;
    ia[i] = ap[i].B;
  }
  cout << 3 << endl;
  si q1s, q2s;
  vi q1, q2, q3;
  for (int i = 0; i < n / 4; ++i) q1s.insert(ia[i]);
  for (int i = 0; q1s.size() < n / 2; ++i) q1s.insert(i);
  for (int i : q1s) q1.pb(i);
  sorts(a, q1);
  for (int i = 0; i < n; ++i) ia[a[i]] = i;
  for (int i = n / 4; i < n / 2; ++i) q2s.insert(ia[i]);
  for (int i = n / 4; q2s.size() < n / 2; ++i) q2s.insert(i);
  for (int i : q2s) q2.pb(i);
  sorts(a, q2);
  for (int i = 0; i < n / 2; ++i) q3.pb(n / 2 + i);
  for (int i = 0; i < n / 2; ++i) cout << (q1[i] + 1) << " \n"[i == n / 2 - 1];
  for (int i = 0; i < n / 2; ++i) cout << (q2[i] + 1) << " \n"[i == n / 2 - 1];
  for (int i = 0; i < n / 2; ++i) cout << (q3[i] + 1) << " \n"[i == n / 2 - 1];
}