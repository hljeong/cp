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

ll gcd(ll a, ll b) {
  if (!b) return a;
  return gcd(b, a % b);
}

// try all primes from left and right
int main() {
  cin.tie(0) -> sync_with_stdio(0);

  int n, a, b; cin >> n >> a >> b;
  vi aa(n); for (int i = 0; i < n; ++i) cin >> aa[i];
  ll g = aa[0];
  for (int i = 1; i < n; ++i) g = gcd(g, aa[i]);
  if (g > 1) return !printf("0\n");

  map<int, vll> lf, rg;

  {
    // left end assumes the suffix is deleted, hence pushing a * (n - 1)
    // get all primes from left end, try a[0], a[0] - 1, && a[0] + 1
    int ai = aa[0];
    for (int p = 2; (ll) p * p <= ai; ++p) {
      if (!(ai % p)) {
        lf[p].pb((ll) a * (n - 1));
        while (!(ai % p)) ai /= p;
      }
    }
    if (ai > 1) lf[ai].pb((ll) a * (n - 1));
    // +/- 1
    ai = aa[0] - 1;
    for (int p = 2; (ll) p * p <= ai; ++p) {
      if (!(ai % p)) {
        lf[p].pb((ll) a * (n - 1) + b);
        while (!(ai % p)) ai /= p;
      }
    }
    if (ai > 1) lf[ai].pb((ll) a * (n - 1) + b);
    ai = aa[0] + 1;
    for (int p = 2; (ll) p * p <= ai; ++p) {
      if (!(ai % p)) {
        if (!lf.count(p)) lf[p].pb((ll) a * (n - 1) + b);
        while (!(ai % p)) ai /= p;
      }
    }
    if (ai > 1) lf[ai].pb((ll) a * (n - 1) + b);

    // extend primes whenever possible
    for (int j = 1; j < n; ++j) {
      vi upd;
      for (auto &[p, v] : lf) {
        if (v.size() == j && !(aa[j] % p)) {
          upd.pb(p);
        }
      }
      // divisible, no cost
      for (int p : upd) lf[p].pb(lf[p].back() - a);
      upd = vi();
      for (auto &[p, v] : lf) {
        if (v.size() == j && (!((aa[j] - 1) % p) || !((aa[j] + 1) % p))) {
          upd.pb(p);
        }
      }
      // need +/- 1
      for (int p : upd) lf[p].pb(lf[p].back() - a + b);
    }
  }

  {
    // do it again from the right
    // except there's no base a * n
    reverse(aa.begin(), aa.end());
    int ai = aa[0];
    for (int p = 2; (ll) p * p <= ai; ++p) {
      if (!(ai % p)) {
        rg[p].pb(-a);
        while (!(ai % p)) ai /= p;
      }
    }
    if (ai > 1) rg[ai].pb(-a);
    ai = aa[0] - 1;
    for (int p = 2; (ll) p * p <= ai; ++p) {
      if (!(ai % p)) {
        rg[p].pb(-a + b);
        while (!(ai % p)) ai /= p;
      }
    }
    if (ai > 1) rg[ai].pb(-a + b);
    ai = aa[0] + 1;
    for (int p = 2; (ll) p * p <= ai; ++p) {
      if (!(ai % p)) {
        if (!rg.count(p)) rg[p].pb(-a + b);
        while (!(ai % p)) ai /= p;
      }
    }
    if (ai > 1) rg[ai].pb(-a + b);
    for (int j = 1; j < n; ++j) {
      vi upd;
      for (auto &[p, v] : rg) {
        if (v.size() == j && !(aa[j] % p)) {
          upd.pb(p);
        }
      }
      for (int p : upd) rg[p].pb(rg[p].back() - a);
      upd = vi();
      for (auto &[p, v] : rg) {
        if (v.size() == j && (!((aa[j] - 1) % p) || !((aa[j] + 1) % p))) {
          upd.pb(p);
        }
      }
      for (int p : upd) rg[p].pb(rg[p].back() - a + b);
    }
  }

  /*
  cout << "lf: " << endl;
  for (auto [p, v] : lf) {
    cout << p << " -> ";
    for (int x : v) cout << x << " ";
    cout << endl;
  }
  cout << endl;
  cout << "rg: " << endl;
  for (auto [p, v] : rg) {
    cout << p << " -> ";
    for (int x : v) cout << x << " ";
    cout << endl;
  }
  cout << endl;
  */

  ll ret = (ll) a * (n - 1);
  for (auto [p, v] : lf) {
    for (ll c : v) ckmin(ret, c);
    if (rg.count(p)) {
      auto &rv = rg[p];
      vll pre_mn(rv.size() + 1, infll);
      for (int i = 0; i < rv.size(); ++i) {
        pre_mn[i + 1] = min(pre_mn[i], rv[i]);
      }
      // for each possible cost from the left for prime p
      // pair it with the minimum in the suffix
      for (int i = 0; i < v.size(); ++i) {
        // i can pair up w at most i + 1 = n - (n - i - 1)
        ckmin(ret, v[i] + pre_mn[min((int) rv.size(), n - i - 1)]);
      }
    }
  }
  for (auto [p, v] : rg) {
    for (ll c : v) ckmin(ret, (ll) a * n + c);
  }
  cout << ret << endl;
}
