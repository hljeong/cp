#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll, ll> pl;

const ll MOD1 = 1e9+7, base1 = 101;
const ll MOD2 = 1e8+7, base2 = 103;

int n;
string s[505][505];
vector <pl> precomp[505][505];
vector <pl> radix;

void kill(){
  printf("NONE\n");
  exit(0);
}

ll mod(ll a, ll b, ll modular, ll base){
  return (a * base + b) % modular;
}

void Hash(string s, int i, int j){
  pl h = {0, 0};
  for (char c : s){
    h = make_pair(mod(h.first, c, MOD1, base1), mod(h.second, c, MOD2, base2));
    precomp[i][j].push_back(h);
  }
}

bool solve(int idx){
  vector <pl> hashes;
  vector <int> lengths;
  hashes.push_back(precomp[1][2][idx - 1]);
  lengths.push_back(idx);
  for (int i = 2; i <= n; i++){
    hashes.push_back({(precomp[1][i].back().first - (radix[s[1][i].length() - idx].first * precomp[1][i][idx - 1].first) % MOD1 + MOD1) % MOD1, 
    (precomp[1][i].back().second - (radix[s[1][i].length() - idx].second * precomp[1][i][idx - 1].second) % MOD2 + MOD2) % MOD2});
    lengths.push_back(s[1][i].length() - idx);
  }
  
  // for (auto it : lengths) printf("Length %d with idx = %d\n", it, idx);
  for (int i = 1; i <= n; i++){
    for (int j = 1; j <= n; j++){
      if (i == j) continue;
      pl shouldHash = {(hashes[i - 1].first * radix[lengths[j - 1]].first + hashes[j - 1].first) % MOD1, 
      (hashes[i - 1].second * radix[lengths[j - 1]].second + hashes[j - 1].second) % MOD2};

      if (shouldHash != precomp[i][j].back()){
        // printf("Failing on %d %d for index %d\n", i, j, idx);
        return false;
      }
    }
  }

  return true;
}

// void print(string it){
//     printf("Hash of %s is {%lld, %lld}\n", it.c_str(), Hash(it).first, Hash(it).second);
// }

int main(){
  cin >> n;
  for (int i = 1; i <= n; i++){
    for (int j = 1; j <= n; j++){
      cin >> s[i][j];
      Hash(s[i][j], i, j);
      if (s[i][j].length() < 2 && i != j) kill();
    }
  }

  radix.push_back({1, 1});
  for (int i = 1; i <= 1000000; i++){
    radix.push_back({(radix.back().first * base1) % MOD1, (radix.back().second * base2) % MOD2});
  }

  int idx = 0;
  bool good = true;
  while (good){
    if (idx >= s[1][2].length() - 1) break;
    char c = s[1][2][idx];

    for (int i = 2; i <= n; i++){
      if (idx >= s[1][i].length()){
        good = false;
        break;
      }

      if (s[1][i][idx] != c){
        good = false;
        break;
      }
    }
    if (good) idx++;
  }

  if (idx <= 0) kill();

  vector <int> solutions;
  // Try all possible s_1 values
  for (int i = 1; i <= idx; i++){
    if (solve(i)){
      solutions.push_back(i);
    }
  } 
  
  if (solutions.size() == 0) kill();
  if (solutions.size() == 1){
    printf("UNIQUE\n");
    vector <string> names;
    names.push_back(s[1][2].substr(0, solutions[0]));
    for (int i = 2; i <= n; i++){
      names.push_back(s[1][i].substr(solutions[0]));
    }

    for (auto it : names) printf("%s\n", it.c_str());
  }
  else{
    printf("MANY\n");
  }
}
