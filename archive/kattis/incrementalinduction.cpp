#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

vector <int> in[5005], out[5005];
bool l[5005], r[5005];
int n, ki[5005], ko[5005];

int main(){
  cin >> n;
  for (int i = 2; i <= n; i++){
    string s;
    cin >> s;
    for (int j = 1; j <= s.length(); j++){
      if (s[j - 1] == '1'){
        in[j].push_back(i);
        out[i].push_back(j);
        ko[j]++;
      }
      else {
        out[j].push_back(i);
        in[i].push_back(j);
        ko[i]++;
      }
    }
  }
  
  for (int i = 1; i <= n; i++){
    l[i] = 1;
    // for (auto it : in[i]) printf("%d has %d in\n", i, it);
  }

  int res = 0, cur = 0;

  int best = -1, Min = -1;
  for (int it = 1; it <= n; it++){
    best = 0, Min = 0x3f3f3f3f;
    int bestki = 0x3f3f3f3f;

    for (int i = 1; i <= n; i++){
      if (!l[i]) continue;

      if (-ki[i] + ko[i] < Min){
        Min = -ki[i] + ko[i];
        best = i;
      }
      else if (ki[i] + ko[i] == Min){
        if (bestki > -ki[i]){
          best = i;
          bestki = -ki[i];
        }
      }
    }

    for (auto it : in[best]){
      if (l[it]){
        ki[it]++;
      }
    }

    for (auto it : out[best]){
      if (l[it]){
        ko[it]--;
      }
    }

    // printf("Best = %d, Min = %d\n", best, Min);
    r[best] = 1;
    l[best] = 0;
    cur += Min;
    res = max(res, cur);
  }

  cout << res << endl;
}
