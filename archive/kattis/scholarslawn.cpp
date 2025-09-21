#include <bits/stdc++.h>

using namespace std;

#define ind(i, j) min((i), (j))][max((i), (j))
const double EPS = 1e-9;

typedef double T;
struct pt{
  T x, y;
  pt(){}
  pt(T X, T Y) : x(X), y(Y) { }
  pt operator-(pt p){ return pt(x-p.x, y-p.y); }
  pt operator*(T t){ return pt(x*t, y*t); }
  pt operator/(T t){ return pt(x/t, y/t); }
};

T dot(pt p, pt q) { return p.x*q.x+p.y*q.y; } 
T cross(pt p, pt q) { return p.x*q.y-p.y*q.x; }
T orient(pt a, pt b, pt c) { return cross(b-a, c-a); }
T sq(pt a) { return a.x*a.x+a.y*a.y; }
double abs(pt a) { return sqrt(sq(a)); }

bool onSeg(pt a, pt b, pt p){
  if(fabs(orient(a, b, p)) > EPS) return 0;
  return dot(b-a, p-a) >= 0 && dot(a-b, p-b) >= 0;
}
bool inter(pt a, pt b, pt c, pt d, pt& p){
  T oa = orient(c, d, a),
    ob = orient(c, d, b),
    oc = orient(a, b, c),
    od = orient(a, b, d);
  if(oa*ob < 0 && oc*od < 0){
    p = (a*ob - b*oa) / (ob-oa);
    return 1;
  }
  if(onSeg(c, d, a)){ p = a; return 1; }
  if(onSeg(c, d, b)){ p = b; return 1; }
  if(onSeg(a, b, c)){ p = c; return 1; }
  if(onSeg(a, b, d)){ p = d; return 1; }
  return 0;
}

int main(){
  int n;
  cin >> n;
  pt pa[n+1], pb[n+1];
  for(int i = 0; i < n; i++)
    cin >> pa[i].x >> pa[i].y >> pb[i].x >> pb[i].y;

  pt ps;
  double vs;
  cin >> ps.x >> ps.y >> vs;

  double vf;
  cin >> pa[n].x >> pa[n].y >> pb[n].x >> pb[n].y >> vf;

  bool isx[n+1][n+1];
  pt px[n+1][n+1];
  for(int i = 0; i <= n; i++)
    for(int j = i; j <= n; j++){
      if(i == j){ isx[i][j] = 0; continue; }
      isx[i][j] = inter(pa[i], pb[i], pa[j], pb[j], px[i][j]);
    }

  double d[n+1][n+1];
  priority_queue<tuple<double, int, int>> pq;
  fill_n(&d[0][0], (n+1)*(n+1), DBL_MAX);
  for(int i = 0; i < n; i++)
    if(onSeg(pa[i], pb[i], ps))
      for(int j = 0; j <= n; j++)
        if(isx[ind(i, j)]){
          d[ind(i, j)] = abs(px[ind(i, j)]-ps);
          pq.push({-d[ind(i, j)], min(i, j), max(i, j)});
        }
  while(pq.size()){
    auto [dc, ic, jc] = pq.top();
    dc = -dc;
    pq.pop();
    if(dc > d[ind(ic, jc)]) continue;
    if(ic != n) for(int j = 0; j <= n; j++){
      if(j == jc || !isx[ind(ic, j)]) continue;
      if(d[ind(ic, j)] <= dc + abs(px[ind(ic, jc)]-px[ind(ic, j)])) continue;
      d[ind(ic, j)] = dc + abs(px[ind(ic, jc)]-px[ind(ic, j)]);
      pq.push({-d[ind(ic, j)], min(ic, j), max(ic, j)});
    }
    if(jc != n) for(int i = 0; i <= n; i++){
      if(i == ic || !isx[ind(i, jc)]) continue;
      if(d[ind(i, jc)] <= dc + abs(px[ind(ic, jc)]-px[ind(i, jc)])) continue;
      d[ind(i, jc)] = dc + abs(px[ind(ic, jc)]-px[ind(i, jc)]);
      pq.push({-d[ind(i, jc)], min(i, jc), max(i, jc)});
    }
  }

  double ans = DBL_MAX;
  for(int i = 0; i < n; i++)
    if(isx[ind(i, n)] && abs(px[i][n]-pa[n])/vf > d[ind(i, n)]/vs-EPS)
      ans = min(ans, abs(px[i][n]-pa[n])/vf);
  if(ans == DBL_MAX)
    cout << "Impossible" << endl;
  else
    cout << setprecision(10) << fixed << ans << endl;
}