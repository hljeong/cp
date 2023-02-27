#include <bits/stdc++.h>
#define vc vector
using namespace std;
using ll = long long;
using vi = vc<int>;

map <string, int> mp;
struct Person{
  string name;
  vector <string> Rank;

  bool operator<(const Person& p) const {
    for (int i = 0; i < Rank.size(); i++){
      if (mp[Rank[i]] > mp[p.Rank[i]]) return true;
      if (mp[Rank[i]] < mp[p.Rank[i]]) return false;
    }

    return name < p.name;
  }
};

string s;
int n;
vector <Person> v;

int main() {
  cin >> n;
  getline(cin, s);
  int Max = 0;
  mp["upper"] = 3;
  mp["middle"] = 2;
  mp["lower"] = 1;
  for (int i = 1; i <= n; i++){
    getline(cin, s);
    stringstream ss(s);

    string t;
    ss >> t;
    Person p;
    p.name = t.substr(0, t.size() - 1);
    while (ss >> t){
      p.Rank.push_back(t);
    }
    p.Rank.resize(p.Rank.size() - 1);
    Max = max(Max, (int)p.Rank.size());
    v.push_back(p);
  }

  for (auto& it : v){
    reverse(it.Rank.begin(), it.Rank.end());
    if (it.Rank.size() != Max){
      while (it.Rank.size() < Max){
        it.Rank.push_back("middle");
      }
    }
  }

  sort(v.begin(), v.end()) ;
  for (int i = 0; i < n; i++){
    printf("%s\n", v[i].name.c_str());
    // for (auto str : v[i].Rank) printf("%s ", str.c_str());
    // printf("\n");
  }
}