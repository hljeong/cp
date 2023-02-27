#include <bits/stdc++.h>

using namespace std;

#define ll long long

ll flat3(ll a1, ll b1, ll a2, ll b2, ll a3, ll b3){
  return (a1 + a2 + a3) * max({b1, b2, b3});
}

ll flat2(ll a1, ll b1, ll a2, ll b2, ll a3, ll b3){
  if(a1 >= a3){
    return max(a1+a2, a3) * max(b1+b3, b2);
  }else{
    return max(a1+a2, a3) * (b3+max(b1, b2));
  }S
}

void solve(){
  ll a1, b1, a2, b2, a3, b3;
  cin >> a1 >> b1 >> a2 >> b2 >> a3 >> b3;

  ll ans = LLONG_MAX;
  for(int flp_mask = 0; flp_mask < 8; flp_mask++){
    if(flp_mask & 1) swap(a1, b1);
    if(flp_mask & 2) swap(a2, b2);
    if(flp_mask & 4) swap(a3, b3);
    ans = min(ans, flat3(a1, b1, a2, b2, a3, b3));
    ans = min(ans, flat2(a1, b1, a2, b2, a3, b3));
    ans = min(ans, flat2(a1, b1, a3, b3, a2, b2));
    ans = min(ans, flat2(a2, b2, a1, b1, a3, b3));
    ans = min(ans, flat2(a2, b2, a3, b3, a1, b1));
    ans = min(ans, flat2(a3, b3, a1, b1, a2, b2));
    ans = min(ans, flat2(a3, b3, a2, b2, a1, b1));
    if(flp_mask & 4) swap(a3, b3);
    if(flp_mask & 2) swap(a2, b2);
    if(flp_mask & 1) swap(a1, b1);
  }
  cout << ans << endl;
}

int main(){
  int t;
  cin >> t;
  while(t--)
    solve();
}