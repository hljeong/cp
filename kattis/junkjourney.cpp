#include <bits/stdc++.h>

using namespace std;

int n, x, y, xt, yt;

void d(){ y--; cout << "down\n";  }
void u(){ y++; cout << "up\n";    }
void l(){ x--; cout << "left\n";  }
void r(){ x++; cout << "right\n"; }

int main(){
  cin >> n >> x >> y >> xt >> yt;
  x -= xt;
  y -= yt;
  
  while(y != -35) d();
  r();
  while(y != -70) d();
  l();
  while(y != -35) u();
  while(x !=  34) r();
  while(x != -35){
    while(y !=  -1) u();
    while(y != -35) d();
    l();
  }
  while(y !=  0) u();
  while(y != 35){
    while(x !=  -1) r();
    while(x != -35) l();
    u();
  }
  while(x !=  0) r();
  while(y !=  1) d();
  for(int i = 55; i >= 2; i--){
    while(y != 35) u();
    while(x !=  i) r();
    while(y !=  0){ d(); l(); r(); }
    while(y != 35) u();
    while(x !=  0) l();
    while(y !=  1) d();
  }
}