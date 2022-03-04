#include <bits/stdc++.h>
#define A first
#define B second
using namespace std;
using ll = long long;
using vi = vector<int>;

void p(int n, int x) {
  for (int i = 0; i < n; ++i) cout << x << ' ';
}

int main() {
  p(16, 0);
  p(32, 300);
  p(32, 600);
  p(16, 300);
  p(16, 0);
  p(36, 600);
  p(44, 300);
  cout << endl;
  p(32, 0);
  p(32, 300);
  p(16, 200);
  p(48, 0);
  p(16, 300);
  p(32, 400);
  p(16, 0);
  cout << endl;
  cout << "5" << endl;
  cout << "0000 0730 10" << endl;
  cout << "0730 1500 20" << endl;
  cout << "1500 2000 40" << endl;
  cout << "2000 3200 10" << endl;
  cout << "3200 4800 20" << endl;
  cout << "12000 1200 0 1600 2000" << endl;
  cout << "12000 6000 0 3800 4200" << endl;
  cout << "12000 6000 0 3200 4200" << endl;
  cout << "12000 2000 0 3200 4200" << endl;
  cout << "12000 2000 59 3200 4200" << endl;
  cout << "12000 2000 59 1600 4200" << endl;
}