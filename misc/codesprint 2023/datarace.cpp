#include <bits/stdc++.h>
#define A first
#define B second
#define vc vector
#define pb push_back
using namespace std;
using ll = long long; using ld = long double;
using vi = vc<int>; using vll = vc<ll>;
using si = set<int>; using sll = set<ll>;
using pii = pair<int, int>; using pll = pair<ll, ll>;
using mii = map<int, int>;

template<class T> bool ckmin(T &a, const T &b) { return b < a ? a = b, 1 : 0; }
template<class T> bool ckmax(T &a, const T &b) { return a < b ? a = b, 1 : 0; }

const int inf = 1e9 + 7;
const int mod = inf;
const ll infll = 0x3f3f3f3f3f3f3f3fll;

template<class T> T minst(function<bool(T)> pred, T i, T j) {
  T ret = j + 1;
  for (T l = i, r = j, m; l <= r; ) {
    if (pred(m = l + (r - l) / 2)) r = (ret = m) - 1;
    else l = m + 1;
  }
  return ret;
}

template<class T> T maxst(function<bool(T)> pred, T i, T j) {
  T ret = i - 1;
  for (T l = i, r = j, m; l <= r; ) {
    if (pred(m = l + (r - l) / 2)) l = (ret = m) + 1;
    else r = m - 1;
  }
  return ret;
}

// normalized t, a, p_start, p_end
using thd = array<int, 4>;

int main() {
  int t, n, m; scanf("%d %d %d", &t, &n, &m);
  vc<thd> job;
  si c; c.insert(0); c.insert(n);
  for (int i = 0; i < t; ++i) {
    int ti, p, b, a; scanf("%d %d %d %d", &ti, &p, &b, &a); --b;
    // go to end time
    ti += b;
    // go to end position
    p = (p + b) % n;
    // get excess length after cycles
    b %= n;
    // go to cycles end time
    ti -= b;
    if (b > p) { // if excess length longer than end position
      // starting at n - (b - p) at ti normalized
      job.pb({ti - (n - (b - p)), a, n - (b - p), n - 1});
      // starting at 0 at ti + (b - p)
      // was ti + (n - p)?
      job.pb({ti + (b - p), a, 0, p});
      // add endpoints
      c.insert(p + 1);
      c.insert(n - (b - p));
    } else { // if excess length at most end position
      // go to cycle end
      p -= b;
      // starting at p at ti
      job.pb({ti - p, a, p, p + b});
      // other part of cycle??????
      // add endpoints
      c.insert(p);
      c.insert(p + b + 1);
    }
  }
  // create <= 2 t segments by endpoints
  // set<pii> segs;
  vi ss, se;
  int last = -1;
  for (int p : c) {
    if (~last) {
      // segs.insert({last, p - 1});
      ss.pb(last);
      se.pb(p - 1);
    }
    last = p;
  }
  // sort jobs by normalized time descending then symbol then start time then end time
  sort(job.begin(), job.end(), [&](thd a, thd b) {
    if (a[0] != b[0]) return b[0] < a[0];
    if (a[1] != b[1]) return a[1] < b[1];
    if (a[2] != b[2]) return a[2] < b[2];
    return a[3] < b[3];
  });
  vi ret(m + 1);
  // time, symbol
  int k = ss.size();
  vi tm(k, -inf), sym(k), nxt(k);
  for (int i = 0; i < k; ++i) nxt[i] = i;
  /*
  map<pii, int> tm, sym;
  for (pii seg : segs) {
    tm[seg] = -inf;
    sym[seg] = 0;
  }
  */
  vc<thd> njob;
  thd cur = {-inf, -1, -1, -1};
  for (thd j : job) {
    // if diff normalized time or diff symbol or disjoint
    if (j[0] != cur[0] || j[1] != cur[1] || j[2] > cur[3] + 1) {
      // add job
      if (cur[1] != -1) njob.pb(cur);
      // new current job
      cur = j;
    }
    // extend job
    ckmax(cur[3], j[3]);
  }
  njob.pb(cur);
  job = njob;
  for (thd j : job) {
    auto p = lower_bound(segs.begin(), segs.end(), make_pair(j[2], 0));
    while (p != segs.end() && p->B <= j[3]) {
      if (tm[*p] > j[0]) {
        segs.erase(p++);
      } else if (tm[*p] == j[0]) {
        sym[*p] = m;
        segs.erase(p++);
      } else {
        tm[*p] = j[0];
        sym[*p] = j[1];
        ++p;
      }
    }
  }
  for (auto e : sym) ret[e.B] += e.A.B - e.A.A + 1;
  for (int i = 0; i <= m; ++i) cout << ret[i] << " \n"[i == m];
}
