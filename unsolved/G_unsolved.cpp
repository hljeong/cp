#include <bits/stdc++.h>
using namespace std;
using vi = vector<int>;

int f1(char a, char b) {
    return (a - '0') * 10 + (b - '0');
}

int t2i(string s) {
    return 4 * f1(s[0], s[1]) + f1(s[2], s[3]) / 15;
}

string i2t(int x) {
    int a = x / 4, b = (x % 4) * 15;
    string l = "00" + to_string(a), r = "00" + to_string(b);
    l = l.substr(l.length() - 2);
    r = r.substr(r.length() - 2);
    return l + r;
}

int main() {
    vi cons(192), gen(192), c(192), b(193), p(192);
    for (int i = 0; i < 192; ++i) cin >> cons[i];
    for (int i = 0; i < 192; ++i) cin >> gen[i];
    for (int i = 0; i < 192; ++i) p[i] = max(0, gen[i] - cons[i]);
    int t_;
    cin >> t_;
    for (int i = 0; i < t_; ++i) {
        string l, r;
        int cost;
        cin >> l >> r >> cost;
        int tl = t2i(l), tr = t2i(r);
        for (int j = tl; j < tr; ++j) c[j] = cost;
    }
    int T, D, perc, B, st, et;
    string stm, etm;
    cin >> T >> D >> perc >> stm >> etm;
    D /= 4;
    while (!cin.eof()) {
        st = t2i(stm);
        et = t2i(etm);
        B = T * perc / 100;
        b[st] = B;
        for (int i = st; i < et; ++i) {
            b[i + 1] = b[i] + p[i];
            if (b[i + 1] > T) b[i + 1] = T;
        }

        vector<int> sorted;
        int ans = et, mini = 1e9;

        if (b[et] + (et - st) * D < T) {
            cout << i2t(st) << endl;
            goto next;
        } else if (b[et] == T) {
            cout << i2t(et) << endl;
            goto next;
        }
        

        for (int x = et - 1; x >= st; --x) {
            int tot = 0, charge = 0;
            for (int i = x; i < et; ++i) {
                tot += c[i];
                charge += D;
                if (b[et] + charge >= T) {
                    break;
                }
            }
            // cout << tot << ' ' << mini << ' ' << b[x] + charge << ' ' << T << endl;
            if (b[et] + charge >= T && tot <= mini) {
                mini = tot;
                ans = x;
            }
        }

        cout << "ans ";
        cout << i2t(ans) << endl;

        next: 
        cin >> T >> D >> perc >> stm >> etm;
    }
}