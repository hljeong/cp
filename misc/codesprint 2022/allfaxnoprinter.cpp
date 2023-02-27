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

template<class T> bool ckmin(T& a, const T& b) { return b < a ? a = b, 1 : 0; }
template<class T> bool ckmax(T& a, const T& b) { return a < b ? a = b, 1 : 0; }

int main() {
  int n, k, max_cnt = 0, sim_cnt = 0;
  cin >> n >> k;
  priority_queue<int> sim;
  multiset<int> maxs;
  for (int i = 0; i < k; ++i) {
    sim.push(0);
    maxs.insert(0);
  }
  for (int i = 0; i < n; ++i) {
    int t, l;
    cin >> t >> l;
    if (t >= -sim.top()) {
      ++sim_cnt;
      sim.pop();
      sim.push(-(t + l));
    }
    auto tgt = maxs.upper_bound(t);
    if (tgt != maxs.begin()) {
      --tgt;
      ++max_cnt;
      maxs.erase(tgt);
      maxs.insert(t + l);
    } else if (t + l < *(maxs.rbegin())) {
      maxs.erase(prev(maxs.end()));
      maxs.insert(t + l);
    }
    cout << max_cnt - sim_cnt << endl;
  }
}