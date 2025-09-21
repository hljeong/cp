#include <bits/stdc++.h>
#define vc vector
using namespace std;
using ll = long long;
using vi = vc<int>;

int main() {
  int a[3], b[3];
  for(int i = 0; i < 3; i++)
    cin >> a[i];
  for(int i = 0; i < 3; i++)
    cin >> b[i];
  sort(a, a+3);
  sort(b, b+3);
  for(int i = 0; i < 3; i++)
    if(a[i] != b[i]){
      cout << "NO" << endl;
      return 0;
    }
  if(a[0]*a[0] + a[1]*a[1] == a[2]*a[2])
    cout << "YES" << endl;
  else
    cout << "NO" << endl;
}