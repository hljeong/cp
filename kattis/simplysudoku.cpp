#include <bits/stdc++.h>
#define A first
#define B second
#define vc vector
#define pb push_back
using namespace std;
using ll = long long; using ld = long double;
using vi = vc<int>; using vll = vc<ll>;
using si = set<int>; using sll = set<ll>;
using pii = pair<int, int>; using mii = map<int, int>;

template<class T> bool ckmin(T &a, const T &b) { return b < a ? a = b, 1 : 0; }
template<class T> bool ckmax(T &a, const T &b) { return b > a ? a = b, 1 : 0; }

const int inf = 1e9 + 7;
const int mod = inf;
const ll infll = 0x3f3f3f3f3f3f3f3fll;

int g[9][9];

int sq(int i, int j){
  return i/3*3+j/3;
}

bool add(){
  bool notis[9][9][9];
  fill_n(&notis[0][0][0], 9*9*9, 0);
  for(int i = 0; i < 9; i++)
    for(int j = 0; j < 9; j++){
      if(g[i][j] == 0) continue;
      for(int jp = 0; jp < 9; jp++)
        notis[i][jp][g[i][j]-1] |= 1;
      for(int ip = 0; ip < 9; ip++)
        notis[ip][j][g[i][j]-1] |= 1;
      for(int ip = 0; ip < 9; ip++)
        for(int jp = 0; jp < 9; jp++)
          if(sq(i, j) == sq(ip, jp))
            notis[ip][jp][g[i][j]-1] |= 1;
    }
  
  for(int i = 0; i < 9; i++)
    for(int j = 0; j < 9; j++){
      if(g[i][j]) continue;
      int cnt = 9, d;
      for(int k = 0; k < 9; k++){
        cnt -= notis[i][j][k];
        if(!notis[i][j][k]) d = k+1;
      }
      if(cnt == 1){
        g[i][j] = d;
        return 1;
      }
    }

  for(int i = 0; i < 9; i++){
    set<pair<int, int>> poss[9];
    for(int j = 0; j < 9; j++)
      for(int k = 0; k < 9; k++)
        if(g[i][j] == 0 && !notis[i][j][k])
          poss[k].insert({i, j});
    for(int k = 0; k < 9; k++)
      if(poss[k].size() == 1){
        g[(*poss[k].begin()).A][(*poss[k].begin()).B] = k+1;
        return 1;
      }
  }

  for(int j = 0; j < 9; j++){
    set<pair<int, int>> poss[9];
    for(int i = 0; i < 9; i++)
      for(int k = 0; k < 9; k++)
        if(g[i][j] == 0 && !notis[i][j][k])
          poss[k].insert({i, j});
    for(int k = 0; k < 9; k++)
      if(poss[k].size() == 1){
        g[(*poss[k].begin()).A][(*poss[k].begin()).B] = k+1;
        return 1;
      }
  }
  
  for(int s = 0; s < 9; s++){
    set<pair<int, int>> poss[9];
    for(int i = 0; i < 9; i++)
      for(int j = 0; j < 9; j++) if(sq(i, j) == s)
        for(int k = 0; k < 9; k++)
          if(g[i][j] == 0 && !notis[i][j][k])
            poss[k].insert({i, j});
    for(int k = 0; k < 9; k++)
      if(poss[k].size() == 1){
        g[(*poss[k].begin()).A][(*poss[k].begin()).B] = k+1;
        return 1;
      }
  }

  return 0;
}

int main(){
  for(int i = 0; i < 9; i++)
    for(int j = 0; j < 9; j++)
      cin >> g[i][j];
  while(add());
  bool noteasy = 0;
  for(int i = 0; i < 9; i++)
    for(int j = 0; j < 9; j++)
      noteasy |= g[i][j] == 0;
  cout << (noteasy ? "Not easy" : "Easy") << endl;
  for(int i = 0; i < 9; i++){
    for(int j = 0; j < 9; j++)
      cout << (g[i][j] ? (char)(g[i][j]+'0') : '.') << ' ';
    cout << endl;
  }
}