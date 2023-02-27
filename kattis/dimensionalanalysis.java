import java.io.*;
import java.util.*;

import static java.lang.Math.*;
import static java.util.Arrays.*;

class dimensionalanalysis {

    public static void main(String[] args) throws IOException {
        input = new StringTokenizer(in.readLine());
        int n = Integer.parseInt(input.nextToken());
        Map<String, Integer> map = new HashMap<>();
        map.put("1", -1);
        int id = 0;
        List<String> eqs = new ArrayList<>();
        for (int i = 0; i < n; ++i) {
            eqs.add(in.readLine());
            input = new StringTokenizer(eqs.get(i));
            while (input.hasMoreTokens()) {
                String token = input.nextToken();
                if ("*".equals(token) || "/".equals(token) || "=".equals(token) || "1".equals(token)) {
                    continue;
                }
                if (!map.containsKey(token)) {
                    map.put(token, id++);
                }
            }
        }
        int c[][] = new int[n][id];
        for (int i = 0; i < n; ++i) {
            input = new StringTokenizer(eqs.get(i));
            int eq = 1, sgn = 1;
            while (input.hasMoreTokens()) {
                String token = input.nextToken();
                if ("*".equals(token)) {
                    sgn = eq;
                } else if ("/".equals(token)) {
                    sgn = -eq;
                } else if ("=".equals(token)) {
                    sgn = eq = -1;
                } else if (!"1".equals(token)) {
                    c[i][map.get(token)] += sgn;
                }
            }
        }
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < id; ++j) {
                c[i][j] = (c[i][j] + mmod) % mmod;
            }
        }
        gauss(c);
        boolean good = true;
        for (int i = 0; i < n; ++i) {
            int cnt0 = 0;
            for (int j = 0; j < id; ++j) {
                if (c[i][j] == 0) {
                    ++cnt0;
                }
            }
            if (cnt0 == id - 1) {
                good = false;
                break;
            }
        }
        out.println(good ? "valid" : "invalid");
        in.close();
        out.close();
    }

    // c[n][n + 1]
    // c[i][i] != 0
    static void gauss(int c[][]) {
        int n = c.length, m = c[0].length, row = 0, rowvar[] = new int[n];
        for (int i = 0; i < n; ++i) {
            if (i >= m) {
                break;
            }
            if (c[row][i] == 0) {
                for (int j = row + 1; j < n; ++j) {
                    if (c[j][i] != 0) {
                        int[] __swap = c[j];
                        c[j] = c[row];
                        c[row] = __swap;
                        break;
                    }
                }
                if (c[row][i] == 0) {
                    continue;
                }
            }
            rowvar[row] = i;
            for (int j = row + 1; j < n; ++j) {
                if (c[j][i] == 0) continue;
                int mul = mmul(c[j][i], minv(c[row][i]));
                for (int k = 0; k < m; ++k) c[j][k] = msub(c[j][k], mmul(c[row][k], mul));
            }
            ++row;
        }
        for (int i = row - 1; i >= 0; --i) {
            for (int j = i - 1; j >= 0; --j) {
                if (c[j][rowvar[i]] == 0) continue;
                int mul = mmul(c[j][rowvar[i]], minv(c[i][rowvar[i]]));
                for (int k = 0; k < m; ++k) c[j][k] = msub(c[j][k], mmul(c[i][k], mul));
            }
        }
    }

    static int mmod = 1000000007;

    static int madd(int a, int b) {
        return (a + b) % mmod;
    }

    static int madd(int... a) {
        int ans = a[0];
        for (int i = 1; i < a.length; ++i) {
            ans = madd(ans, a[i]);
        }
        return ans;
    }

    static int msub(int a, int b) {
        return (a - b + mmod) % mmod;
    }

    static int mmul(int a, int b) {
        return (int) ((long) a * b % mmod);
    }

    static int mmul(int... a) {
        int ans = a[0];
        for (int i = 1; i < a.length; ++i) {
            ans = mmul(ans, a[i]);
        }
        return ans;
    }

    static int minv(int x) {
        // return mpow(x, mmod - 2);
        return (exgcd(x, mmod)[0] % mmod + mmod) % mmod;
    }

    static int mpow(int a, long b) {
        if (a == 0) {
            return 0;
        }
        int ans = 1;
        while (b > 0) {
            if ((b & 1) > 0) {
                ans = mmul(ans, a);
            }
            a = mmul(a, a);
            b >>= 1;
        }
        return ans;
    }

    static BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
    static PrintWriter out = new PrintWriter(new OutputStreamWriter(System.out));
    static StringTokenizer input;

    // references
    // IBIG = 1e9 + 7
    // IMAX ~= 2e9
    // LMAX ~= 9e18

    // constants
    static final int IBIG = 1000000007;
    static final int IMAX = 2147483647;
    static final long LMAX = 9223372036854775807L;

    static int[] exgcd(int a, int b) {if (b == 0) return new int[] {1, 0, a}; int[] y = exgcd(b, a % b); return new int[] {y[1], y[0] - y[1] * (a / b), y[2]};}
}
