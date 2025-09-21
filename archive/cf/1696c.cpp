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

int main() {
  int t;
  cin >> t;
  while (t--) {
    int n, m;
    cin >> n >> m;
    vi a(n);
    for (int i = 0; i < n; ++i) cin >> a[i];
    int k;
    cin >> k;
    vi b(k);
    for (int i = 0; i < k; ++i) cin >> b[i];
    vc<pair<ll, ll>> ad, bd;
    for (int i = n - 1; i >= 0; --i) {
      ll cnt = 1;
      while (!(a[i] % m)) {
        cnt *= m;
        a[i] /= m;
      }
      if (ad.size() && a[i] == ad.back().A) {
        cnt += ad.back().B;
        ad.pop_back();
      }
      ad.push_back({(ll) a[i], cnt});
    }
    for (int i = k - 1; i >= 0; --i) {
      ll cnt = 1;
      while (!(b[i] % m)) {
        cnt *= m;
        b[i] /= m;
      }
      if (bd.size() && b[i] == bd.back().A) {
        cnt += bd.back().B;
        bd.pop_back();
      }
      bd.push_back({(ll) b[i], cnt});
    }
    cout << (ad == bd ? "Yes" : "No") << endl;
  }
}

/* 
// disgusting garbage problem
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n, m;
    cin >> n >> m;
    vi a(n);
    for (int i = 0; i < n; ++i) cin >> a[i];
    int k;
    cin >> k;
    vi b(k);
    for (int i = 0; i < k; ++i) cin >> b[i];
    stack<pii> st;
    for (int i = n - 1; i >= 0; --i) {
      int cnt = 1;
      while (!(a[i] % m)) {
        cnt *= m;
        a[i] /= m;
      }
      st.push({a[i], cnt});
    }
    bool bad = false;
    for (int i = 0; i < k; ++i) {
      ll totuse = 0;
      while (b[i]) {
        if (st.empty()) {
          bad = true;
          break;
        }
        pii cur = st.top();
        st.pop();
        int use = min(cur.B, b[i] / cur.A);
        totuse += use;
        cur.B -= use;
        b[i] -= use * cur.A;
        if (cur.B) {
          if (b[i]) bad = true;
          else st.push(cur);
          break;
        }
      }
      if (!totuse) bad = true;
      if (bad) break;
      if ((totuse - 1) % (m - 1)) {
        bad = true;
        break;
      }
    }
    cout << (bad || !st.empty() ? "No" : "Yes") << endl;
  }
}
*/