#include <bits/stdc++.h>
#define A first
#define B second
using namespace std;
using ll = long long;
using vi = vector<int>;

const int maxn = 1e5 + 5;
ll dp[maxn];

int main() {
  int n, k;
  cin >> n >> k;
  vector<pair<int, ll>> jw;
  for (int i = 0; i < n; ++i) {
    int s, v;
    scanf("%d %d", &s, &v);
    jw.push_back({s, v});
  }
  sort(jw.begin(), jw.end(), [&](const pair<int, ll> &a, const pair<int, ll> &b) {
    return a.B * b.A < b.B * a.A;
  });
  if (n > k) n = k;
  for (int i = 0; i < n; ++i) for (int j = k; j >= jw[i].A; --j) {
    if (dp[j - jw[i].A] + jw[i].B > dp[j]) dp[j] = dp[j - jw[i].A] + jw[i].B;
  }
  for (int i = 1; i <= k; ++i) {
    printf("%lld ", dp[i]);
  }
  printf("\n");
}