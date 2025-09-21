#include <bits/stdc++.h>

using namespace std;

int main(){
  int n, m, s, d;
  cin >> n >> m >> s >> d;
  pair<int, int> c[s];
  for(int i = 0; i < s; i++){
    cin >> c[i].first;
    c[i].second = i;
  }
  sort(c, c+s);
  int it = 0;
  int ans[s];
  fill(ans, ans+s, 0);
  while(it < s && n){
    ans[c[it].second] = min(n, d-c[it].first);
    n -= min(n, d-c[it].first);
    it++;
  }
  int cnt = 0;
  for(int i = it; i < s; i++)
    cnt += c[i].first;
  if(cnt < m)
    cout << "impossible" << endl;
  else{
    for(int i = 0; i < s; i++)
      cout << ans[i] << ' ';
    cout << endl;
  }
}
