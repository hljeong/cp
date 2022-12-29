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

const ld lg2 = log(2), lg3 = log(3);

int main() {
  int n; cin >> n;
  vc<pii> p(n);
  vi mna(n + 1, 1000), mnb(n + 1, 1000), amn(n + 1, 1000), bmn(n + 1, 1000);
  vi mxa(n + 1), mxb(n + 1), amx(n + 1), bmx(n + 1);
  for (int i = 0; i < n; ++i) {
    cin >> p[i].A >> p[i].B;
    mna[i + 1] = min(mna[i], p[i].A);
    mnb[i + 1] = min(mnb[i], p[i].B);
    mxa[i + 1] = max(mxa[i], p[i].A);
    mxb[i + 1] = max(mxb[i], p[i].B);
  }
  for (int i = n - 1; i >= 0; --i) {
    amn[i] = min(amn[i + 1], p[i].A);
    bmn[i] = min(bmn[i + 1], p[i].B);
    amx[i] = max(amx[i + 1], p[i].A);
    bmx[i] = max(bmx[i + 1], p[i].B);
  }
  vc<pii> mnret(n, {1000, 1000}), mxret(n);
  mnret[0].A = mxret[0].A = amx[0];
  mnret[0].B = mxret[0].B = bmx[0];
  mnret[n - 1].A = mxret[n - 1].A = amn[0];
  mnret[n - 1].B = mxret[n - 1].B = bmn[0];
  if (n > 1) {
    for (int i = 0; i < n; ++i) {
      {
        ld lgret = mnret[1].A * lg2 + mnret[1].B * lg3;
        int a = min(p[i].A, max(mxa[i], amx[i + 1])), b = min(p[i].B, max(mxb[i], bmx[i + 1]));
        ld lgab = a * lg2 + b * lg3;
        if (lgab <= lgret) {
          mnret[1].A = a;
          mnret[1].B = b;
        }
      }
      {
        ld lgret = mxret[n - 2].A * lg2 + mxret[n - 2].B * lg3;
        int a = max(p[i].A, min(mna[i], amn[i + 1])), b = max(p[i].B, min(mnb[i], bmn[i + 1]));
        ld lgab = a * lg2 + b * lg3;
        if (lgab >= lgret) {
          mxret[n - 2].A = a;
          mxret[n - 2].B = b;
        }
      }
    }
    for (int i = 2; i < n; ++i) {
      mnret[i].A = amn[0];
      mnret[i].B = bmn[0];
      mxret[n - i - 1].A = amx[0];
      mxret[n - i - 1].B = bmx[0];
    }
  }
  for (int i = 0; i < n; ++i) {
    cout << mxret[i].A << ' ' << mxret[i].B << ' ' << mnret[i].A << ' ' << mnret[i].B << endl;
  }
}
