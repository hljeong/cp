#include <bits/stdc++.h>
#define A first
#define B second
using namespace std;

int main() {
  int T;
  cin >> T;
  while (T--) {
    int n, m, k;
    cin >> n >> m >> k;
    vector<vector<int>> g(n);
    vector<int> deg(n);
    for (int i = 0; i < m; ++i) {
      int u, v;
      cin >> u >> v, --u, --v;
      g[u].push_back(v);
      g[v].push_back(u);
      ++deg[u];
      ++deg[v];
    }

    // good[i] = !(node i sinks)
    vector<bool> good(n, true);
    // topsort-esque loop to find all nodes that sink
    queue<int> q;
    for (int i = 0; i < n; ++i) if (deg[i] == 1) q.push(i);
    while (q.size()) {
      int i = q.front();
      good[i] = false;
      q.pop();
      for (int j : g[i]) if (--deg[j] == 1) q.push(j);
    }

    // dfs to fill anc array: anc[i][j] = (1 << j)-th ancestor of node i
    // disregarding any looping edges
    vector<bool> vis(n);
    vector<vector<int>> anc(n, vector<int>(15)); 
    function<void(int, int)> dfs = [&](int i, int p) {
      vis[i] = true;
      anc[i][0] = p;
      for (int j = 1; j < 15; ++j) anc[i][j] = anc[anc[i][j - 1]][j - 1];
      for (int j : g[i]) if (!vis[j]) dfs(j, i);
    };
    
    // root at any good node, initialize ans to number of bad nodes
    int rt = -1, ans = 0;
    for (int i = 0; i < n; ++i) if (good[i]) rt = i;
    else ++ans; 
    dfs(rt, rt);
    
    // returns number of bad nodes from node i to root (closest good node)
    auto len = [&](int i) {
      int ans = 1;
      for (int j = 14; j >= 0; --j) if (!good[anc[i][j]]) {
        ans += 1 << j;
        i = anc[i][j];
      }
      return ans;
    };
    
    // sort by len(i) nonincreasing
    priority_queue<pair<int, int>> pq;
    // enqueue if is leaf
    for (int i = 0; i < n; ++i) if (g[i].size() == 1) pq.push({len(i), i});
    for (int i = 0; i < k; ++i) {
      // no more bad nodes
      if (!pq.size()) break;
      int l = pq.top().A, lf = pq.top().B, nlen;
      pq.pop();
      // inconsistent len: re-enqueue
      while ((nlen = len(lf)) != l) {
        pq.push({nlen, lf});
        l = pq.top().A, lf = pq.top().B;
        pq.pop();
      }
      // update nodes on path to root
      while (!good[lf]) {
        good[lf] = true;
        --ans;
        lf = anc[lf][0];
      } 
    }
    cout << ans << endl;
  }
}