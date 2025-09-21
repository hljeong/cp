#include <bits/stdc++.h>
#define vc vector
using namespace std;
using ll = long long;
using vi = vc<int>;

const int N_MAX = 20;
const int M_MAX = 1000;

int n, k, m;
int b[N_MAX], p[N_MAX][N_MAX], q[N_MAX][N_MAX];
int bt[N_MAX][1<<(N_MAX-1)];

double pge[M_MAX+1], pge2[M_MAX+1], pge2r[M_MAX+1];

double dp[1<<(N_MAX+1)][N_MAX+1];
double recur(int mask, int k_left){
  if(dp[mask][k_left] != -1)
    return dp[mask][k_left];
  int i = 31-__builtin_clz(mask);
  int mask_p = mask-(1<<i);
  if(i+1 == n){
    if(bt[i][mask_p] + m <= 0)
      return dp[mask][k_left] = 0;
    if(k_left)
      return dp[mask][k_left] = pge2[max(1, 1-bt[i][mask_p])];
    else
      return dp[mask][k_left] = pge[max(1, 1-bt[i][mask_p])];
  }

  if(bt[i][mask-(1<<i)] + m <= 0)
    return dp[mask][k_left] = recur(mask+(1<<i), k_left);
  if(bt[i][mask-(1<<i)] >= 0)
    return dp[mask][k_left] = recur(mask+(1<<(i+1)), k_left);
  
  dp[mask][k_left] = recur(mask+(1<<(i+1)), k_left) * pge[max(1, 1-bt[i][mask_p])]
                      + recur(mask+(1<<i), k_left) * (1-pge[max(1, 1-bt[i][mask_p])]);
  if(k_left){
    dp[mask][k_left] = max(dp[mask][k_left], 
                        recur(mask+(1<<(i+1)), k_left-1) * pge2[max(1, 1-bt[i][mask_p])]
                        + recur(mask+(1<<i), k_left-1) * (1-pge2[max(1, 1-bt[i][mask_p])]));
    dp[mask][k_left] = max(dp[mask][k_left], 
                        recur(mask+(1<<(i+1)), k_left-1) * (1-pge2r[-bt[i][mask_p]])
                        + recur(mask+(1<<i), k_left-1) * pge2r[-bt[i][mask_p]]);
  }
  return dp[mask][k_left];
}

int main() {
  cin >> n >> k >> m;
  for(int i = 0; i < n; i++){
    cin >> b[i];
    for(int j = i+1; j < n; j++)
      cin >> p[i][j];
    for(int j = i+1; j < n; j++)
      cin >> q[i][j];
  }
  for(int i = 0; i < n; i++)
    for(int mask = 0; mask < (1<<i); mask++){
      bt[i][mask] = b[i];
      for(int j = 0; j < i; j++)
        bt[i][mask] += ((mask >> j) & 1 ? p[j][i] : q[j][i]);
    }
  for(int i = 1; i <= m; i++){
    pge[i] = 1.*(m-i+1)/m;
    pge2[i] = (1.-1.*(i-1)*(i-1)/m/m);
    pge2r[i] = (1.-1.*(m-i)*(m-i)/m/m);
  }
  pge2r[0] = 0;

  fill_n(&dp[0][0], (1<<N_MAX)*(N_MAX+1), -1);

  cout << setprecision(6) << fixed << recur(1, k) << endl;
}