
#include <bits/stdc++.h>

using namespace std;

const int C_MAX = 2e6+5;

int main(){
  int r, s, n;
  cin >> r >> s >> n;
  int a[r], b[s], c[n];
  int a_t = 0, b_t = 0;
  for(int i = 0; i < r; i++) cin >> a[i], a_t += a[i];
  for(int j = 0; j < s; j++) cin >> b[j], b_t += b[j];
  for(int k = 0; k < n; k++) cin >> c[k];
  bool sum[C_MAX], dp[r][s][n+1];
  fill(sum, sum+C_MAX, 0);
  sum[0] = 1;
  for(int i = 1; i < C_MAX; i++)
    sum[i] = (i-a_t >= 0 ? sum[i-a_t] : 0) || (i-b_t >= 0 ? sum[i-b_t] : 0);
  int a_p[r][r], b_p[s][s];
  for(int i = 0; i < r; i++)
    for(int j = 0; j < r; j++){
      int sumij = 0;
      for(int k = i; k%r != j; k++)
        sumij += a[k%r];
      a_p[i][j] = sumij;
    }
  for(int i = 0; i < s; i++)
    for(int j = 0; j < s; j++){
      int sumij = 0;
      for(int k = i; k%s != j; k++)
        sumij += b[k%s];
      b_p[i][j] = sumij;
    }
  fill_n(&dp[0][0][0], r*s*(n+1), 0);
  dp[0][0][0] = 1;
  for(int k = 0; k < n; k++)
    for(int i = 0; i < r; i++)
      for(int j = 0; j < s; j++)
        if(dp[i][j][k])
          for(int ip = 0; ip < r; ip++)
            for(int jp = 0; jp < s; jp++)
              if(c[k] - a_p[i][ip] - b_p[j][jp] >= 0 && sum[c[k] - a_p[i][ip] - b_p[j][jp]])
                dp[ip][jp][k+1] |= 1;
  bool ans = 0;
  for(int i = 0; i < r; i++)
    for(int j = 0; j < s; j++)
      ans |= dp[i][j][n];
  cout << (ans ? "Yes" : "No") << endl;
}