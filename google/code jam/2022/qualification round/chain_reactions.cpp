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

// wrong solution, see comments in code

template<class T> bool ckmin(T& a, const T& b) { return b < a ? a = b, 1 : 0; }
template<class T> bool ckmax(T& a, const T& b) { return a < b ? a = b, 1 : 0; }

priority_queue<ll>* dfs(vc<vi> &g, vll &f, int i = 0) {
  if (!g[i].size()) {
    priority_queue<ll> *ans = new priority_queue<ll>();
    ans->push(-f[i]); 
    return ans;
  }
  priority_queue<ll> *ans = dfs(g, f, g[i][0]);
  for (int j = 1; j < g[i].size(); ++j) {
    priority_queue<ll> *sans = dfs(g, f, g[i][j]);
    while (sans->size()) {
      ans->push(sans->top());
      sans->pop();
    }
    delete sans;
  }
  // when this happens, should add all other values in pq to final answer and only leave f[i] in pq
  if (i && -f[i] < ans->top()) {
    ans->pop();
    ans->push(-f[i]);
  }
  return ans;
}

int main() {
  int t;
  cin >> t;
  for (int tt = 1; tt <= t; ++tt) {
    cout << "Case #" << tt << ": ";
    int n;
    cin >> n;
    vll f(n + 1);
    vc<vi> g(n + 1, vi());
    for (int i = 1; i <= n; ++i) cin >> f[i];
    for (int i = 0; i < n; ++i) {
      int p;
      cin >> p;
      g[p].push_back(i + 1);
    }
    priority_queue<ll> *s = dfs(g, f);
    ll ans = 0;
    while (s->size()) {
      ans -= s->top();
      s->pop();
    }
    cout << ans << endl;
    delete s;
  }
}