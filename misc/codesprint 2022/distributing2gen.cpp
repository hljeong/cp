#include <bits/stdc++.h>
#define A first
#define B second
using namespace std;
using ll = long long;
using vi = vector<int>;
using vll = vector<ll>;

template<class T> bool ckmin(T& a, const T& b) { return b < a ? a = b, 1 : 0; }
template<class T> bool ckmax(T& a, const T& b) { return a < b ? a = b, 1 : 0; }

int main() {
  random_device rd;     //Get a random seed from the OS entropy device, or whatever
  mt19937_64 eng(rd()); //Use the 64-bit Mersenne Twister 19937 generator

  uniform_int_distribution<int> distr;
  
  for (int i = 3; i <= 20; ++i) {
    ofstream f;
    string id = "00" + to_string(i);
    id = id.substr(id.length() - 2);
    f.open("secret." + id + ".in");
    int n;
    if (i >= 5 && i <= 8) {
      n = 1000000;
    } else {
      n = (distr(eng) % 1000000) + 1; 
    }
    vi l(n);
    if (distr(eng) & 1) {
      int mn = (distr(eng) % 99) + 1;
      int tot = 0, cnt = 0;
      while (tot < n - cnt) {
        l[cnt] = (distr(eng) % 2) + mn;
        tot += l[cnt++];
      }
      while (cnt < n) {
        l[cnt++] = (distr(eng) % (100 - mn + 1)) + mn;
      }
    } else {
      for (int j = 0; j < n; ++j) l[j] = (distr(eng) % 100) + 1;
    }
    auto rng = default_random_engine{};
    shuffle(begin(l), end(l), rng);
    f << n << endl;
    for (int j = 0; j < n; ++j) {
      if (j) f << ' ';
      f << l[j];
    }
    f << endl;
    f.close();
    f.open("secret." + id + ".ans");
    vi freq(102);
    int mnn = 100;
    for (int j = 0; j < n; ++j) {
      ++freq[l[j]];
      ckmin(mnn, l[j]);
    }
    cout << mnn << ' ' << freq[mnn] << endl;
    string ans = freq[mnn] * (mnn - 1) + freq[mnn + 1] * mnn >= n - freq[mnn] - freq[mnn + 1] ? "no" : "yes";
    f << ans << endl;
    cout << ans << endl;
    f.close();
  }
}