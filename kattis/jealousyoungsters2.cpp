#include <bits/stdc++.h>

using namespace std;

#define vc vector
using ll = long long;
using vi = vc<int>;

vi gs(vc<vi> &a, vc<vi> &b) {
  int n = a.size(), m = b.size();
  vi p(n), asgn(m, -1);
  vc<vi> bpos(m, vi(n));
  for (int i = 0; i < m; ++i)
    for (int j = 0; j < n; ++j)
      bpos[i][b[i][j]] = j;
  queue<int> q;
  for (int i = 0; i < n; ++i) q.push(i);
  while (q.size()) {
    int i = q.front(); q.pop();
    int match = a[i][p[i]];
    if (asgn[match] != -1) {
      if (bpos[match][i] < bpos[match][asgn[match]]) {
        q.push(asgn[match]);
        asgn[match] = i;
      } else q.push(i);
    } else asgn[match] = i;
    ++p[i];
  }
  vi ret(n, -1);
  for (int i = 0; i < m; ++i)
    if (asgn[i] >= 0)
      ret[asgn[i]] = i;
  return ret;
}

int main(){
  int n, m, e;
  ll d;
  cin >> n >> m >> d >> e;
  
  // preference of toys (total time played, kid)
  vector<pair<ll, int>> toy_pref[m];
  ll playtime[n][m];
  fill_n(&playtime[0][0], n*m, 0);
  // preference of kid (first time played, toy)
  vector<pair<ll, int>> kid_pref[n];
  ll firstplay[n][m];
  fill_n(&firstplay[0][0], n*m, LLONG_MAX);

  // current toy the kid is playing
  int cur_toy[n];
  fill(cur_toy, cur_toy+n, -1);
  // current kid the toy is being used by
  int cur_kid[m];
  fill(cur_kid, cur_kid+m, -1);
  // kid start time playing
  ll cur_start[n];
  for(int i = 0; i < e; i++){
    ll s;
    int k, t;
    cin >> s >> k >> t;
    
    if(t == 0){
      if(cur_toy[k-1] == -1) continue;
      playtime[k-1][cur_toy[k-1]] += s - cur_start[k-1];
      cur_kid[cur_toy[k-1]] = -1;
      cur_toy[k-1] = -1;
    }else{
      if(cur_kid[t-1] >= 0){
        playtime[cur_kid[t-1]][t-1] += s - cur_start[cur_kid[t-1]];
        cur_toy[cur_kid[t-1]] = -1;
        cur_kid[t-1] = -1;
      }
      if(cur_toy[k-1] >= 0){
        playtime[k-1][cur_toy[k-1]] += s - cur_start[k-1];
        cur_kid[cur_toy[k-1]] = -1;
        cur_toy[k-1] = -1;
      }
      firstplay[k-1][t-1] = min(firstplay[k-1][t-1], s);
      cur_kid[t-1] = k-1;
      cur_toy[k-1] = t-1;
      cur_start[k-1] = s;
    }
  }
  for(int k = 1; k <= n; k++) if(cur_toy[k-1] >= 0){
      playtime[k-1][cur_toy[k-1]] += d - cur_start[k-1];
      cur_kid[cur_toy[k-1]] = -1;
      cur_toy[k-1] = -1;
  }
  for(int t = 1; t <= m; t++){
    for(int k = 1; k <= n; k++)
      toy_pref[t-1].push_back({playtime[k-1][t-1], k-1});
    sort(toy_pref[t-1].begin(), toy_pref[t-1].end());
    // reverse(toy_pref[t-1].begin(), toy_pref[t-1].end());
    // cout << "toy (" << t << ") : ";
    // for(auto& [a, b] : toy_pref[t-1])
    //   cout << "[" << a << ", " << b+1 << "] ";
    // cout << endl;
  }
  for(int k = 1; k <= n; k++){
    for(int t = 1; t <= m; t++)
      kid_pref[k-1].push_back({firstplay[k-1][t-1], t-1});
    sort(kid_pref[k-1].begin(), kid_pref[k-1].end());
    // cout << "kid (" << k << ") : ";
    // for(auto& [a, b] : kid_pref[k-1])
    //   cout << "[" << a << ", " << b+1 << "] ";
    // cout << endl;
  }
  if (m < n) {
    cout << "impossible" << endl;
    return 0;
  }
  /*
  vi kptr(n), asgn(m , -1);
  queue<int> q;
  for (int i = 0; i < n; ++i) {
    q.push(i);
  }
  while (q.size()) {
    int i = q.front(); q.pop();
    int toy = kid_pref[i][kptr[i]].second;
    if (asgn[toy] != -1) {
      if (playtime[i][toy] < playtime[asgn[toy]][toy]) {
        q.push(asgn[toy]);
        asgn[toy] = i;
      } else {
        q.push(i);
      }
    } else {
      asgn[toy] = i;
    }
    ++kptr[i];
  }
  vi ret(n);
  for (int i = 0; i < m; ++i) {
    if (asgn[i] >= 0)
      ret[asgn[i]] = i;
  }
  for (int i = 0; i < n; ++i) {
    cout << (ret[i] + 1) << " \n"[i == n - 1];
  }
  */
  vc<vi> a(n, vi(m)), b(m, vi(n));
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      a[i][j] = kid_pref[i][j].second;
      b[j][i] = toy_pref[j][i].second;
    }
  }
  vi ret = gs(a, b);
  for (int i = 0; i < n; ++i) {
    cout << (ret[i] + 1) << " \n"[i == n - 1];
  }
}
