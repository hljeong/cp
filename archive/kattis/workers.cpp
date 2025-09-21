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

template<class T> bool ckmin(T &a, const T &b) { return b < a ? a = b, 1 : 0; }
template<class T> bool ckmax(T &a, const T &b) { return a < b ? a = b, 1 : 0; }
struct Edge
{
    int from, to, capacity, cost;
};

vector<vector<int>> adj, cost, capacity;

const int INF = 1e9;

void shortest_paths(int n, int v0, vector<int>& d, vector<int>& p) {
    d.assign(n, INF);
    d[v0] = 0;
    vector<bool> inq(n, false);
    queue<int> q;
    q.push(v0);
    p.assign(n, -1);

    while (!q.empty()) {
        int u = q.front();
        q.pop();
        inq[u] = false;
        for (int v : adj[u]) {
            if (capacity[u][v] > 0 && d[v] > d[u] + cost[u][v]) {
                d[v] = d[u] + cost[u][v];
                p[v] = u;
                if (!inq[v]) {
                    inq[v] = true;
                    q.push(v);
                }
            }
        }
    }
}
int n;

int min_cost_flow(int N, vector<Edge> edges, int K, int s, int t,map<int,int> &save) {
    adj.assign(N, vector<int>());
    cost.assign(N, vector<int>(N, 0));
    capacity.assign(N, vector<int>(N, 0));
    for (Edge e : edges) {
        adj[e.from].push_back(e.to);
        adj[e.to].push_back(e.from);
        cost[e.from][e.to] = e.cost;
        cost[e.to][e.from] = -e.cost;
        capacity[e.from][e.to] = e.capacity;
    }

    int flow = 0;
    int cost = 0;
    vector<int> d, p;
    while (flow < K) {
        shortest_paths(N, s, d, p);
        if (d[t] == INF)
            break;

        // find max flow on that path
        int f = K - flow;
        int cur = t;
        while (cur != s) {
            f = min(f, capacity[p[cur]][cur]);
            cur = p[cur];
        }

        // apply flow
        flow += f;
        cost += f * d[t];
        cur = t;
        while (cur != s) {
            capacity[p[cur]][cur] -= f;
            capacity[cur][p[cur]] += f;
            cur = p[cur];
        }
    }
    for(int i=0;i<n;i++){
      for(int j=n;j<2*n;j++){
        if(capacity[i][j]==0)
          save[i]=j;
      }
    }
    for(int i=n;i<2*n;i++){
      for(int j=2*n;j<3*n;j++){
        if(capacity[i][j]==0)
          save[i]=j;
      }
    }
    assert(flow==n);
    if (flow < K)
        return -1;
    else
        return cost;
}

int main() {
    cin>>n;
    int road1[n][2*n]{};
    for(int i=0;i<n;i++){
      for(int j=0;j<2*n;j++){
        cin>>road1[i][j];
      }
    }
    int road2[n][2*n]{};
    for(int i=0;i<n;i++){
      for(int j=0;j<2*n;j++){
        cin>>road2[i][j];
      }
    }
    map<int,int> ansInfo;
    int ans=INT_MAX;
    int a_cnt=-1;
    for(int a=0;a<=n;a++){
      vector<Edge> graph;
      for(int z=0;z<n;z++){
        graph.push_back({3*n,z,1,0});
        int idx=n;
        for(int i=0;i<a;i++){
          int curr=idx;
          graph.push_back({z,curr,1,road1[z][2*i]});
          graph.push_back({curr,2*n+z,1,road2[z][2*i]});
          idx++;
        }
        for(int i=a;i<n;i++){
          int curr=idx;
          graph.push_back({z,curr,1,road1[z][2*i+1]});
          graph.push_back({curr,2*n+z,1,road2[z][2*i+1]});
          idx++;
        }
        graph.push_back({2*n+z,3*n+1,1,0});
      }
      // for(auto a:graph){
      //   cout<<a.from<< "->"<<a.to<<"cap"<<a.capacity<<" cost"<<a.cost<<"\n";
      // }
      // cout<<"\n";
      map<int,int> save;
      
      int cost=min_cost_flow(3*n+2,graph,n, 3*n,3*n+1,save );
      
      if(ans>cost){
        ans=cost;
          ansInfo=save;
          a_cnt=a;
      }
    }
     cout<<ans<<"\n";
    for(int i=0;i<n;i++){
        int mid = ansInfo[i];
        int last = ansInfo[mid];
        mid-=n;
        last-=2*n;
        cout<<i+1<< " "<<mid+1<<(mid<a_cnt?'A':'B')<<" "<<last+1<<"\n";
      }
}