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

int divd[10000007];

void sieve() {
  for (int i = 2; i <= 10000000; ++i) {
    if (divd[i] == 0) {
      divd[i] = i;
      if ((ll) i * i <= 10000000) {
        int j = i * i;
        while (j <= 10000000) {
          divd[j] = i;
          j += i;
        }
      }
    }
  }
}

bool solve(int par, int l, int r, map<int, set<int>> &mp, vc<vi> &pf, vi &p) {
  if (r < l) return true;
  int rt = -1;
  for (int i = 0; i <= (r - l + 1) / 2; ++i) {
    bool good = true;
    for (int f : pf[l + i]) {
      auto lb = mp[f].lower_bound(l + i);
      if (lb != mp[f].begin() && *(--lb) >= l) {
        good = false;
        break;
      }
      auto rb = mp[f].upper_bound(l + i);
      if (rb != mp[f].end() && (*rb) <= r) {
        good = false;
        break;
      }
    }
    if (good) {
      rt = l + i;
      break;
    }
    good = true;
    for (int f : pf[r - i]) {
      auto lb = mp[f].lower_bound(r - i);
      if (lb != mp[f].begin() && *(--lb) >= l) {
        good = false;
        break;
      }
      auto rb = mp[f].upper_bound(r - i);
      if (rb != mp[f].end() && (*rb) <= r) {
        good = false;
        break;
      }
    }
    if (good) {
      rt = r - i;
      break;
    }
  }
  if (rt < 0) return false;
  p[rt] = par + 1;
  return solve(rt, l, rt - 1, mp, pf, p) && solve(rt, rt + 1, r, mp, pf, p);
}

int main() {
  int n;
  cin >> n;
  vi a(n);
  sieve();
  map<int, set<int>> mp;
  vc<vi> pf(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
    int x = a[i];
    while (x > 1) {
      int p = divd[x];
      while (!(x % p)) x /= p;
      pf[i].push_back(p);
      mp[p].insert(i);
    }
  }
  vi p(n);
  if (solve(-1, 0, n - 1, mp, pf, p)) {
    for (int i = 0; i < n; ++i) {
      if (i) cout << ' ';
      cout << p[i];
    }
    cout << endl;
  } else {
    cout << "impossible" << endl;
  }
}