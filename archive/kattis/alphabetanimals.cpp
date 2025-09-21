#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e5+5;

string s, t[maxn];
int v[500];
int n;

int main(){
  cin >> s >> n;

  for (int i = 1; i <= n; i++){
    cin >> t[i];
    v[t[i][0]]++;
  }

  for (int i = 1; i <= n; Si++){
    v[t[i][0]]--;
    if ((v[t[i].back()] == 0) && (t[i][0] == s.back())){
      return !printf("%s!\n", t[i].c_str());
    }

    v[t[i][0]]++
  }

  for (int i = 1; i <= n; i++){
    if (t[i][0] == s.back()) return !printf("%s\n", t[i].c_str());
  }

  printf("?\n");
}