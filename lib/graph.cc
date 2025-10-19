#include "../misc/tmpl.cc"

constexpr struct Directed {} directed;

struct Graph : vec<vi> {
  using base = vec<vi>;
  using base::begin;
  using base::end;
  using base::size;
  using base::operator[];

  vec<map<int, ll>> w;

  Graph(int n) : base(n), w(n) {}
  Graph(const Graph &g) = default;
  Graph(int n, int m, int off = 1) : Graph(n) {
    for (int i = 0; i < m; i++) {
      def(int, u, v);
      c(u - off, v - off);
    }
  }
  Graph(Directed, int n, int m, int off = 1) : Graph(n) {
    for (int i = 0; i < m; i++) {
      def(int, u, v);
      cto(u - off, v - off);
    }
  }

  void cto(int from, int to) { self[from].pb(to); }
  void c(int from, int to) { cto(from, to); cto(to, from); }

  Graph transpose() const {
    int n = size();
    Graph g(n);
    for (int u = 0; u < n; u++)
      for (int v : self[u])
        g.cto(v, u);
    return g;
  }
};
