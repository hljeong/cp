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
  int ans[s];
  fill(ans, ans+s, 0);
  sort(c, c+s);
  for(int i = 0; i < s; i++){
    ans[c[i].second] = min(n, d-c[i].first);
    n -= min(n, d-c[i].first);
  }
  int cnt = 0;
  for(int i = 0; i < s; i++)
    if(!ans[c[i].second])
      cnt += c[i].first;
  if(cnt < m)
    cout << "impossible" << endl;
  else{
    for(int i = 0; i < s; i++)
      cout << ans[i] << ' ';
    cout << endl;
  }
}
