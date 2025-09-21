#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> g;
vector<int> ans;

pair<int, int> dfs_furthest(int u, int p){
  pair<int, int> q = {0, u};
  for(int v : g[u]){
    if(v == p) continue;
    auto r = dfs_furthest(v, u);
    r.first++;
    q = max(q, r);
  }
  return q;
}

bool dfs_lr_path(vector<int>& ord, int u, int p, int r){
  if(u == r){
    ord.push_back(u);
    return 1;
  }
  for(int v : g[u]){
    if(v == p) continue;
    if(dfs_lr_path(ord, v, u, r)){
      ord.push_back(u);
      return 1;
    }
  }
  return 0;
}

void dfs_rest(int u, int p){
  ans.push_back(u);
  for(int v : g[u]){
    if(v == p) continue;
    dfs_rest(v, u);
  }
}

int main(){
  int n;
  cin >> n;
  g.assign(n, vector<int>());
  for(int i = 1, a, b; i < n; i++){
    cin >> a >> b; a--, b--;
    g[a].push_back(b);
    g[b].push_back(a);
  }

  auto [d2, l] = dfs_furthest(0, -1);
  auto [d, r] = dfs_furthest(l, -1);

  if(d <= 2){
    cout << "NO" << endl;
    return 0;
  }

  // generate path
  vector<int> ord;
  dfs_lr_path(ord, l, -1, r);
  for(int i = 2; i < ord.size(); i++)
    ans.push_back(ord[i]);
  ans.push_back(ord[1]);
  ans.push_back(ord[0]);

  // dfs remaining
  for(int i = 1; i < ord.size()-1; i++){
    int u = ord[i];
    for(int v : g[u]){
      if(ord[i-1] == v || ord[i+1] == v) continue;
      dfs_rest(v, u);
    }
  }

  cout << "YES" << endl;
  for(int u : ans)
    cout << u+1 << ' ';
  cout << endl;
}