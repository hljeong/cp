#include <bits/stdc++.h>
#define A first
#define B second
using namespace std;
using ll = long long;
using vi = vector<int>;
using vll = vector<ll>;

template<class T> bool ckmin(T& a, const T& b) { return b < a ? a = b, 1 : 0; }
template<class T> bool ckmax(T& a, const T& b) { return a < b ? a = b, 1 : 0; }

const int maxn = 1e5;
const int maxm = 1e5;
random_device rd;
std::mt19937::result_type seed = rd() ^ (
            (std::mt19937::result_type)
            std::chrono::duration_cast<std::chrono::seconds>(
                std::chrono::system_clock::now().time_since_epoch()
                ).count() +
            (std::mt19937::result_type)
            std::chrono::duration_cast<std::chrono::microseconds>(
                std::chrono::high_resolution_clock::now().time_since_epoch()
                ).count() );
mt19937 rng(seed);
vector<set<int>> g;
ofstream f;
vi p;

int find(int i) {
  return i == p[i] ? i : (p[i] = find(p[i]));
}

void merge(int i, int j) {
  i = find(i);
  j = find(j);
  if (i != j) p[j] = i;
}

int randi(int l, int r) {
  return l + (rng() % (r - l + 1));
}

void close() {
  f.close();
}

void gen(int n, int m, int k, int t) {
  f << n << ' ' << m << ' ' << k << ' ' << t << endl;
  g = vector<set<int>>(2 * n, set<int>());
  p = vi(2 * n);
  for (int i = 0; i < 2 * n; ++i) p[i] = i;
  for (int i = 0; i < m; ++i) {
    int u = randi(1, n - 1), v = randi(0, n - 1);
    while (u == v) {
      u = randi(1, n - 1);
      v = randi(0, n - 1);
    }
    int e = randi(0, 1);
    if (find(2 * u) == find(2 * v)) e = 0;
    else if (find(2 * u) == find(2 * v + 1)) e = 1;
    f << (u + 1) << ' ' << (v + 1) << ' ' << (e ? "imposter" : "crewmate") << endl;
    g[2 * u].insert(2 * v + e);
    g[(2 * u) ^ 1].insert(2 * v + e ^ 1);
    g[2 * v + e].insert(2 * u);
    g[2 * v + e ^ 1].insert((2 * u) ^ 1);
    merge(2 * u, 2 * v + e);
    merge(2 * u + 1, 2 * v + e ^ 1);
  }
  close();
}

void gen_random() {
  ll n = randi(2, maxn / 10);
  ll m = randi(n - 1, maxm);
  int k = randi(2, n);
  int t = randi(1, m);
  gen(n, m, k, t);
}

void file(int id) {
  string sid = "00" + to_string(id);
  sid = sid.substr(sid.length() - 2);
  f.open("secret." + sid + ".in");
}

int main(int argc, char **argv) {
  for (int i = 2; i <= 5; ++i) {
    file(i);
    gen_random();
  }
  file(6);
  gen(maxn, maxm, randi(2, maxn), maxm / 2);
  file(7);
  gen(100, 100 * 99 / 2, randi(2, 100), 40);
  file(8);
  gen(maxn, 1, randi(2, maxn), 1);
  file(9);
  gen(100, 100 * 99 / 2, 1, 200);
  file(10);
  gen(maxn, maxm, 1, maxm);

  /*
  cout << "gen: " << atoi(argv[1]) << endl;
  file(atoi(argv[1]));
  gen_random();
  */
}
