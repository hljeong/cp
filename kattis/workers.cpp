#include <bits/stdc++.h>
#include <bits/extc++.h>

using namespace std;

template<class T> bool ckmin(T &a, const T &b) { return b < a ? a = b, 1 : 0; }

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

const ll INF = numeric_limits<ll>::max() / 4;
typedef vector<ll> VL;

struct MCMF {
	int N;
	vector<vi> ed, red;
	vector<VL> cap, flow, cost;
	vi seen;
	VL dist, pi;
	vector<pii> par;

	MCMF(int N) :
		N(N), ed(N), red(N), cap(N, VL(N)), flow(cap), cost(cap),
		seen(N), dist(N), pi(N), par(N) {}

	void addEdge(int from, int to, ll cap, ll cost) {
		this->cap[from][to] = cap;
		this->cost[from][to] = cost;
		ed[from].push_back(to);
		red[to].push_back(from);
	}

	void path(int s) {
		fill(all(seen), 0);
		fill(all(dist), INF);
		dist[s] = 0; ll di;

		__gnu_pbds::priority_queue<pair<ll, int>> q;
		vector<decltype(q)::point_iterator> its(N);
		q.push({0, s});

		auto relax = [&](int i, ll cap, ll cost, int dir) {
			ll val = di - pi[i] + cost;
			if (cap && val < dist[i]) {
				dist[i] = val;
				par[i] = {s, dir};
				if (its[i] == q.end()) its[i] = q.push({-dist[i], i});
				else q.modify(its[i], {-dist[i], i});
			}
		};

		while (!q.empty()) {
			s = q.top().second; q.pop();
			seen[s] = 1; di = dist[s] + pi[s];
			for (int i : ed[s]) if (!seen[i])
				relax(i, cap[s][i] - flow[s][i], cost[s][i], 1);
			for (int i : red[s]) if (!seen[i])
				relax(i, flow[i][s], -cost[i][s], 0);
		}
		rep(i,0,N) pi[i] = min(pi[i] + dist[i], INF);
	}

	ll maxflow(int s, int t) {
		ll totflow = 0, totcost = 0;
		while (path(s), seen[t]) {
			ll fl = INF;
			for (int p,r,x = t; tie(p,r) = par[x], x != s; x = p)
				fl = min(fl, r ? cap[p][x] - flow[p][x] : flow[x][p]);
			totflow += fl;
			for (int p,r,x = t; tie(p,r) = par[x], x != s; x = p)
				if (r) flow[p][x] += fl;
				else flow[x][p] -= fl;
		}
		rep(i,0,N) rep(j,0,N) totcost += cost[i][j] * flow[i][j];
		return totcost;
	}

	// If some costs can be negative, call this before maxflow:
	void setpi(int s) { // (otherwise, leave this out)
		fill(all(pi), INF); pi[s] = 0;
		int it = N, ch = 1; ll v;
		while (ch-- && it--)
			rep(i,0,N) if (pi[i] != INF)
				for (int to : ed[i]) if (cap[i][to])
					if ((v = pi[i] + cost[i][to]) < pi[to])
						pi[to] = v, ch = 1;
		assert(it >= 0); // negative cost cycle
	}
};

int main(){
  int n;
  cin >> n;
  int da[n][n], db[n][n], dc[n][n], dd[n][n];
  for(int i = 0; i < n; i++)
    for(int j = 0; j < n; j++)
      cin >> da[i][j] >> db[i][j];
  for(int i = 0; i < n; i++)
    for(int j = 0; j < n; j++)
      cin >> dc[i][j] >> dd[i][j];
  int s = 4*n, t = 4*n+1, best = INT_MAX;
  int pref, asna[n], asnb[n];
  for(int i = 0; i <= n; i++){
    MCMF mcmf(4*n+2);
    for(int j = 0; j < n; j++){
      mcmf.addEdge(s, j, 1, 0);
      mcmf.addEdge(n+j, 2*n+j, 1, 0);
      mcmf.addEdge(3*n+j, t, 1, 0);
    }
    for(int j = 0; j < n; j++){
      for(int k = 0; k < n; k++)
        mcmf.addEdge(j, n+k, 1, (k < i ? da[j][k] : db[j][k]));
      for(int k = 0; k < n; k++)
        mcmf.addEdge(2*n+k, 3*n+j, 1, (k < i ? dc[j][k] : dd[j][k]));
    }
    if(ckmin(best, (int)mcmf.maxflow(s, t))){
      pref = i;
      for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++){
          if(mcmf.flow[i][n+j])
            asna[i] = j;
          if(mcmf.flow[2*n+i][3*n+j])
            asnb[i] = j;
        }
    }
  }
  cout << best << endl;
  for(int i = 0; i < n; i++)
    cout << i+1 << ' ' << asna[i]+1 << (asna[i] < pref ? 'A' : 'B') << ' ' << asnb[asna[i]]+1 << endl;
}