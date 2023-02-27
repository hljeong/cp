#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int maxn = 3e5+5;

int n, p[maxn]; 
ll sum[maxn], flow[maxn], res[maxn];
vector <int> adj[maxn], child[maxn];

void die(){
  printf("impossible\n");
  exit(0);
}

ll flood(int node){
  if (child[node].empty()){
    return flow[node];
  }

  ll f = 0;
  for (auto it : child[node]){
    sum[node] += flood(it);
  }

  f = sum[node];
  if (flow[node] != 0) f = flow[node];
  return f;
}

bool check_initial(int node){
  if (flow[node] > 0 && sum[node] > flow[node]) return false;
  bool ret = true;
  for (auto it : child[node]){
    ret |= check_initial(it);
  }

  return ret;
}

void solve(int node, vector <int>& unknown){
  int sz = unknown.size();
  if (child[node].empty()){
    if (flow[node] == 0){
      unknown.push_back(node);
      // printf("%d is leaf\n", node);
    }
    
    return;
  }

  for (auto it : child[node]){
    solve(it, unknown);
  }
  
  // for (auto it : unknown) printf("Node %d has %d\n", node, it);
  if (flow[node] > 0){
    if (unknown.size() - sz == flow[node] - sum[node]){
      for (int i = sz; i < unknown.size(); i++){
        res[unknown[i]] = 1;
      }
    }
    else if (unknown.size() - sz == 1){
      for (int i = sz; i < unknown.size(); i++){
        res[unknown[i]] = flow[node] - sum[node];
      }
    }
    else {
      // printf("Die at %d, sizes are %d && %lld\n", node, (int)unknown.size(), flow[node] - sum[node]);
      die();
    }
    
    unknown.resize(sz);
  }

  return;
}

void check(int node){
  bool zero = res[node] == 0;
  for (auto it : child[node]){
    check(it);
    if (res[it] == 0){
      die();
    }

    if (zero) res[node] += res[it];
  }

  if (flow[node] > 0 && res[node] != flow[node]){
    die();
  }
}

int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  cin >> n;
  for (int i = 2; i <= n; i++){
    cin >> p[i];
    child[p[i]].push_back(i);
  }

  for (int i = 1; i <= n; i++){
    cin >> flow[i];
    res[i] = flow[i];
  }

  // for (int i = 1; i <= n; i++){
  //   cout << sum[i] << " " << flow[i] << " " << i << endl;
  // }

  flood(1);
  if (!check_initial(1)) return !printf("impossible\n");
  vector <int> unknown;
  solve(1, unknown);
  check(1);

  for (int i = 1; i <= n; i++){
    printf("%lld\n", res[i]);
  }

  return 0;
}