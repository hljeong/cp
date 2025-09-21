#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;

typedef long long ll;
typedef long double ld;
typedef pair<ll, ll> pl;
typedef pair<int, int> pi;

constexpr int inf = 0x3f3f3f3f;
constexpr ll infll = 0x3f3f3f3f3f3f3f3f;
constexpr double EPS = 1e-8;
constexpr double PI = atan(1) * 4;

template <typename T> using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

template <typename T> inline bool chmax(T& x, T y) {return x < y ? x = y, 1 : 0;}
template <typename T> inline bool chmin(T& x, T y) {return x > y ? x = y, 1 : 0;}
inline int LSB(int i) {return (i & -i);}

/*
    - Read carefully
    - Look for patterns/observations
    - Think backwards
*/

constexpr int MOD = 1e9+7;
constexpr ll LIMIT = (1LL << 62) - 1;

int n;
ll x = 1, res = 1;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    
    cin >> n;

    ll used;
    for (int i = 1; i <= n; i++){
        cin >> used;
        x *= 2;
        res = (res * 2) % MOD;
        if (x >= LIMIT){
            x = LIMIT;
        }

        if (x < used) return !printf("error\n");
        x -= used;
        res = (res - used % MOD + MOD) % MOD;
    }

    cout << res % MOD << endl;
    return 0;
}
