#include <bits/stdc++.h>
#define A first
#define B second
#define vc vector
using namespace std;
using ll = long long;
using ld = long double;
using vi = vc<int>;
using vll = vc<ll>;
using pii = pair<int, int>;

template<class T> bool ckmin(T &a, const T &b) { return b < a ? a = b, 1 : 0; }
template<class T> bool ckmax(T &a, const T &b) { return a < b ? a = b, 1 : 0; }

int main() {
  int n, id = 0; cin >> n;
  map<string, int> mp;
  map<int, string> imp;
  vc<pair<string, string>> input(n);
  for (int i = 0; i < n; ++i) {
    cin >> input[i].A >> input[i].B;
    if (mp.find(input[i].A) == mp.end()) {
      mp[input[i].A] = id;
      imp[id++] = input[i].A;
    }
    if (mp.find(input[i].B) == mp.end()) {
      mp[input[i].B] = id;
      imp[id++] = input[i].B;
    }
  }
  vi p(id);
  for (int i = 0; i < id; ++i) p[i] = i;
  for (int i = 0; i < n; ++i) {
    p[mp[input[i].A]] = mp[input[i].B];
  }
  for (int i = 0; i < 24; ++i) {
    vi np(id);
    for (int j = 0; j < id; ++j) np[j] = p[p[j]];
    p = np;
  }
  for (int i = 0; i < n; ++i) {
    cout << input[i].A << ' ' << imp[p[mp[input[i].A]]] << endl;
  }
}
