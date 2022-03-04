// solve x = a[i] (mod m[i])
// https://codeforces.com/blog/entry/61290
// https://ideone.com/4VodS8
static int crt(int a[], int m[]) {
    int ans = a[0], lcm = m[0], n = a.length;
    for (int i = 1; i < n; ++i) {
        int e[] = exgcd(lcm, m[i]), x = e[0], d = e[1];
        if ((a[i] - ans) % d != 0) return -1;
        ans += x * (a[i] - ans) / d % (m[i] / d) * lcm;
        lcm *= m[i] / d;
        ans %= lcm;
        if (ans < 0) ans += lcm;
    }
    return ans;
}

static long crt(long a[], long m[]) {
    long ans = a[0], lcm = m[0], n = a.length;
    for (int i = 1; i < n; ++i) {
        long e[] = exgcd(lcm, m[i]), x = e[0], d = e[2];
        if ((a[i] - ans) % d != 0) return -1;
        ans += x * (a[i] - ans) / d % (m[i] / d) * lcm;
        lcm *= m[i] / d;
        ans %= lcm;
        if (ans < 0) ans += lcm;
    }
    return ans;
}