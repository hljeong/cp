// aka sos dp
static void zeta(int f[], int n) {
    for (int i = 0; i < n; ++i) {
        for (int mask = 0; mask < (1 << n); ++mask) {
            if ((mask & (1 << i)) != 0) {
                f[mask] += f[mask ^ (1 << i)];
            }
        }
    }
}

// aka mobius transformation
// aka inverse sos dp
static void mu(int f[], int n) {
    for (int i = 0; i < n; ++i) {
        for (int mask = 0; mask < (1 << n); ++mask) {
            if ((mask & (1 << i)) != 0) {
                f[mask] -= f[mask ^ (1 << i)];
            }
        }
    }
}

static void flip(int f[], int n) {
    for (int i = 0; i < 1 << (n - 1); ++i) {
        int __swap = f[i];
        f[i] = f[((1 << n) - 1) ^ i];
        f[((1 << n) - 1) ^ i] = __swap;
    }
}