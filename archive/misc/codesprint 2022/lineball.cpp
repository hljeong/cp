#include <bits/stdc++.h>
#define A first
#define B second
#define vc vector
#define rep(i, a, b) for(int i = 1; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int) (x).size()
using namespace std;
using ll = long long;
using ld = long double;
using vi = vc<int>;
using vll = vc<ll>;
using pii = pair<int, int>;

template<class T> bool ckmin(T& a, const T& b) { return b < a ? a = b, 1 : 0; }
template<class T> bool ckmax(T& a, const T& b) { return a < b ? a = b, 1 : 0; }

struct Dinic {
	struct Edge {
		int to, rev;
		ll c, oc;
		ll flow() { return max(oc - c, 0LL); } // if you need flows
	};
	vi lvl, ptr, q;
	vector<vector<Edge>> adj;
	Dinic(int n) : lvl(n), ptr(n), q(n), adj(n) {}
	void addEdge(int a, int b, ll c, ll rcap = 0) {
		adj[a].push_back({b, sz(adj[b]), c, c});
		adj[b].push_back({a, sz(adj[a]) - 1, rcap, rcap});
	}
	ll dfs(int v, int t, ll f) {
		if (v == t || !f) return f;
		for (int& i = ptr[v]; i < sz(adj[v]); i++) {
			Edge& e = adj[v][i];
			if (lvl[e.to] == lvl[v] + 1)
				if (ll p = dfs(e.to, t, min(f, e.c))) {
					e.c -= p, adj[e.to][e.rev].c += p;
					return p;
				}
		}
		return 0;
	}
	ll calc(int s, int t) {
		ll flow = 0; q[0] = s;
		rep(L,0,31) do { // 'int L=30' maybe faster for random data
			lvl = ptr = vi(sz(q));
			int qi = 0, qe = lvl[s] = 1;
			while (qi < qe && !lvl[t]) {
				int v = q[qi++];
				for (Edge e : adj[v])
					if (!lvl[e.to] && e.c >> (30 - L))
						q[qe++] = e.to, lvl[e.to] = lvl[v] + 1;
			}
			while (ll p = dfs(s, t, LLONG_MAX)) flow += p;
		} while (lvl[t]);
		return flow;
	}
	bool leftOfMinCut(int a) { return lvl[a] != 0; }
};

int main() {
  int n, m, id = 0, xcnt = 0, ycnt = 0;
  cin >> n >> m;
  map<int, int> xnode, ynode, ixnode, iynode;
  set<pii> es;
  map<int, bool> isx;
  for (int i = 0; i < n; ++i) {
    int x, y;
    cin >> x >> y;
    if (xnode.find(x) == xnode.end()) xnode[x] = id, isx[id] = true, ixnode[id++] = xcnt++;
    if (ynode.find(y) == ynode.end()) ynode[y] = id, isx[id] = false, iynode[id++] = ycnt++; 
    es.insert(make_pair(xnode[x], ynode[y]));
  }
  Dinic fg(id + 2);
  for (auto e : es) {
    fg.addEdge(1 + ixnode[e.A], 1 + xcnt + iynode[e.B], 1);
  }
  for (int i = 0; i < id; ++i) {
    if (isx[i]) fg.addEdge(0, 1 + ixnode[i], 1);
    else fg.addEdge(1 + xcnt + iynode[i], 1 + id, 1);
  }
  cout << fg.calc(0, 1 + id) << endl;
}