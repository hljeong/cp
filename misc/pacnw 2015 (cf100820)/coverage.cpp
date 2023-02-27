#include <bits/stdc++.h>

using namespace std;

#define M_PI atan(1.0)*4
double norm(double d){
  return fmod(fmod(d, 2*M_PI)+2*M_PI, 2*M_PI);
}

using T = double;
struct pt{
  T x, y;
  pt(T X, T Y) : x(X), y(Y) {}
  pt() : x(0), y(0) {}
  pt operator-(pt p) { return {x-p.x, y-p.y}; }
};

T abs(pt p){
  return sqrt(p.x*p.x + p.y*p.y);
}
T ang(pt p){
  return norm(atan2(p.y, p.x));
}
bool inter(pt a, pt b, double& l, double& r){
  if(abs(b-a) > 4.) return 0;
  l = r = ang(b-a);
  l -= acos(abs(b-a)/4.);
  r += acos(abs(b-a)/4.);
  l = norm(l);
  r = norm(r);
  return 1;
}

struct dsu_t{
  int n;
  vector<int> par, sz;
  dsu_t(int N) : n(N) {
    par.resize(n);
    for(int i = 0; i < n; i++)
      par[i] = i;
    sz.assign(n, 1);
  }
  int find(int a){
    if(par[a] == a) return a;
    return par[a] = find(par[a]);
  }
  void merge(int a, int b){
    a = find(a);
    b = find(b);
    if(a == b) return;
    if(sz[a] < sz[b]) swap(a, b);
    par[b] = a;
    sz[a] += sz[b];
  }
};

int main(){
  int n;
  cin >> n;
  pt p[n];
  for(int i = 0; i < n; i++)
    cin >> p[i].x >> p[i].y;
  dsu_t dsu(n);
  for(int i = 0; i < n; i++)
    for(int j = i+1; j < n; j++)
      if(abs(p[j]-p[i]) <= 2.)
        dsu.merge(i, j);
  
  int ans = 0;
  for(int i = 0, cmpi; i < n; i++){
    T l, r;
    cmpi = dsu.find(i);
    ans = max(ans, dsu.sz[cmpi]+1);
    vector<tuple<T, int, int>> events;
    for(int j = 0, cmpj; j < n; j++){
      cmpj = dsu.find(j);
      if(cmpi != cmpj && inter(p[i], p[j], l, r)){
        if(l <= r){
          events.push_back({l, 0, cmpj});
          events.push_back({r, 1, cmpj});
        }else{
          events.push_back({0, 0, cmpj});
          events.push_back({r, 1, cmpj});
          events.push_back({l, 0, cmpj});
        }
      }
    }
    sort(events.begin(), events.end());

    int cur = 1+dsu.sz[cmpi];
    map<int, int> cur_cmp;
    for(auto& [angle, t, cmp] : events){
      if(t == 1){
        // remove
        cur_cmp[cmp]--;
        if(cur_cmp[cmp] == 0)
          cur -= dsu.sz[cmp];
      }else{
        // add
        cur_cmp[cmp]++;
        if(cur_cmp[cmp] == 1)
          cur += dsu.sz[cmp];
      }
      ans = max(ans, cur);
    }    
  }
  cout << ans << endl;
}