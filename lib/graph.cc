#include "../misc/tmpl.cc"

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

  void cto(int from, int to, ll weight) { (*this)[from].pb(to); w[from][to] += weight; }
  void c(int from, int to, ll weight = 1) { cto(from, to, weight); cto(to, from, weight); }
};
