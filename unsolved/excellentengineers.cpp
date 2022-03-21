#include <bits/stdc++.h>
#define A first
#define B second
using namespace std;
using ll = long long;

int main() {
  int T;
  cin >> T;
  while (T--) {
    int n;
    cin >> n;
    vector<vector<int>> r(n, vector<int>(3));
    for (int i = 0; i < n; ++i) cin >> r[i][0] >> r[i][1] >> r[i][2];
    
    // sort by rank of skill 1
    sort(r.begin(), r.end(), [&](const vector<int> &a, const vector<int> &b) {
      return a[0] < b[0];
    }); 
    
    // maintain pareto front with increasing skill 2 (=> decreasing skill 3)
    auto cmp = [&](int a, int b) {return r[a][1] < r[b][1];};
    set<int, decltype(cmp)> pf(cmp);
    int ans = 0;
    for (int i = 0; i < n; ++i) {
      // remove anything on the pareto front that is worse than i
      auto rem = pf.lower_bound(i);
      while (rem != pf.end() && r[*rem][2] > r[i][2]) {
        rem = pf.erase(rem);
      }
      
      // if i belongs to the pareto front
      if (rem == pf.begin() || r[*(--rem)][2] > r[i][2]) {
        pf.insert(i);
        ++ans;
      }
    }

    cout << ans << endl;
  }
}