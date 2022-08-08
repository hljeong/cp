#include <bits/stdc++.h>
#define A first
#define B second
using namespace std;
using ll = long long;
using vi = vector<int>;

// attempt to solve using pareto front
// unsuccessful since some edges are not from pareto front to inserted node

int main() {
  int n;
  cin >> n;
  vector<vi> rk(n, vi(3));
  for (int i = 0; i < 3; ++i) for (int j = 0; j < n; ++j) {
    int cml;
    cin >> cml, --cml;
    rk[cml][i] = j;
  }
  vector<vi> g(n, vi());
  vi indeg(n);
  sort(rk.begin(), rk.end(), [&](const vi& a, const vi& b) { return b[0] < a[0]; });
  auto cmp = [&](int a, int b) { return rk[a][1] < rk[b][1]; };
  set<int, decltype(cmp)> pf(cmp);
  for (int i = 0; i < n; ++i) {
    auto rem = pf.upper_bound(i);
    while (rem != pf.end() && rk[*rem][2] > rk[i][2]) {
      g[*rem].push_back(i);
      ++indeg[i];
      rem = pf.erase(rem);
    }
    if (rem == pf.begin() || rk[*--rem][2] > rk[i][2]) pf.insert(i);
  } 
  vector<ll> cnt(n);
  queue<int> q;
  for (int i = 0; i < n; ++i) if (!indeg[i]) q.push(i);
  ll ans = 0;
  while (q.size()) {
    int i = q.front();
    q.pop();
    ans += cnt[i];
    for (int j : g[i]) {
      cnt[j] += cnt[i] + 1;
      if (--indeg[j] == 0) q.push(j);
    }
  }
  cout << "ans ";
  cout << ans << endl;
}