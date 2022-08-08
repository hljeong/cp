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

template<class T> bool ckmin(T& a, const T& b) { return b < a ? a = b, 1 : 0; }
template<class T> bool ckmax(T& a, const T& b) { return a < b ? a = b, 1 : 0; }

// find where first of each distinct char is
// a b * * c * * * d *
// a b b a c a c a d d

char q1(int i) {
  cout << "? 1 " << (i + 1) << endl << flush;
  char ans;
  cin >> ans;
  return ans;
}

int q2(int l, int r) {
  cout << "? 2 " << (l + 1) << ' ' << (r + 1) << endl << flush;
  int ans;
  cin >> ans;
  return ans;
}

void g(string s) {
  cout << "! " << s << endl << flush;
}

int main() {
  int n;
  cin >> n;
  string s(n, ' '); 
  vi inds;
  for (int i = 0; i < n; ++i) {
    int q = q2(0, i);
    if (q > inds.size()) {
      s[i] = q1(i);
      inds.push_back(i);
    }
  }
  int cur = 0;
  for (int i = 0; i < n; ++i) {
    if (cur < inds.size() && i == inds[cur]) {
      ++cur;
      continue;
    }
    vi ninds;
    set<char> sc;
    for (int j = i - 1; j >= 0; --j) {
      if (sc.find(s[j]) == sc.end()) {
        ninds.push_back(j);
        sc.insert(s[j]);
      }
    }
    int ind = -1;
    for (int l = 0, r = cur; l < r; ) {
      int m = l + (r - l) / 2, q = q2(ninds[m], i);
      set<char> st; 
      for (int j = ninds[m]; j < i; ++j) st.insert(s[j]);
      if (q == st.size()) {
        ind = ninds[m];
        r = m;
      } else {
        l = m + 1;
      }
    }
    s[i] = s[ind];
  }
  g(s);
}