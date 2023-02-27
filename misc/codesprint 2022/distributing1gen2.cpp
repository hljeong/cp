#include <bits/stdc++.h>
#define A first
#define B second
using namespace std;
using ll = long long;
using vi = vector<int>;
using vll = vector<ll>;

template<class T> bool ckmin(T& a, const T& b) { return b < a ? a = b, 1 : 0; }
template<class T> bool ckmax(T& a, const T& b) { return a < b ? a = b, 1 : 0; }

const int MAXN = 1e7, MAXM = 1e9;

int main() {
  random_device rd;     //Get a random seed from the OS entropy device, or whatever
  mt19937_64 eng(rd()); //Use the 64-bit Mersenne Twister 19937 generator

  uniform_int_distribution<unsigned long long> distr;
  
  ofstream f;
  string id = "21";
  f.open("secret." + id + ".in");
  ll n = 2, m = 1;
  f << n << ' ' << m << endl;
  f.close();
  f.open("secret." + id + ".ans");
  f << !!(m % n) << endl;
  f.close();

  id = "22";
  f.open("secret." + id + ".in");
  n = 2, m = 2;
  f << n << ' ' << m << endl;
  f.close();
  f.open("secret." + id + ".ans");
  f << !!(m % n) << endl;
  f.close();
}