import java.io.*;
import java.util.*;

import static java.lang.Math.*;
import static java.util.Arrays.*;

/*
sample case:
7 7 2 3
3 1 imposter
2 5 imposter
4 3 crewmate
4 6 imposter
6 5 crewmate
6 7 crewmate
5 4 imposter
*/

class among_ourselves {

    public static void main(String[] args) throws IOException {
        int n = rni(), m = ni(), k = ni() - 1, t = ni();
        int statements[][] = new int[m][3];
        for (int i = 0; i < m; ++i) {
            statements[i][0] = rni() - 1;
            statements[i][1] = ni() - 1;
            statements[i][2] = n().charAt(0) == 'i' ? 1 : 0;
        }

        List<int[]> qrys = new ArrayList<>();
        for (int i = m - 1; i >= t; --i) {
            int u = statements[i][0], v = statements[i][1], opp = statements[i][2];
            qrys.add(new int[] {0, u, opp * n + v});
            qrys.add(new int[] {0, n + u, (1 - opp) * n + v});
        }
        qrys.add(new int[] {2, 0, k});
        qrys.add(new int[] {2, 0, n + k});
        for (int i = 0; i < m - t; ++i) {
            int u1 = statements[i][0], v1 = statements[i][1], opp1 = statements[i][2];
            int u2 = statements[i + t][0], v2 = statements[i + t][1], opp2 = statements[i + t][2];
            qrys.add(new int[] {0, u1, opp1 * n + v1});
            qrys.add(new int[] {0, n + u1, (1 - opp1) * n + v1});
            qrys.add(new int[] {1, u2, opp2 * n + v2});
            qrys.add(new int[] {1, n + u2, (1 - opp2) * n + v2});
            qrys.add(new int[] {2, 0, k});
            qrys.add(new int[] {2, 0, n + k});
        }

        boolean res[] = solve_dynamic_connectivity_offline(2 * n, qrys);
        for (int i = 0; i <= m - t; ++i) {
            if (res[2 * i] || res[2 * i + 1]) {
                pr(i + 1);
                pr(' ');
                prln(res[2 * i] ? "crewmate" : "imposter");
                if (res[2 * i] && res[2 * i + 1]) throw new RuntimeException();
                close();
                return;
            }
        }
        prln(-1);
        close();
    }

    // qry format (0-indexed):
    // 0 u v: connect u v
    // 1 u v: disconnect u v
    // 2 u v: check u v
    static boolean[] solve_dynamic_connectivity_offline(int n, List<int[]> qs) {
        int m = qs.size(), qid = 0;
        pdsu dsu = new pdsu(n, m);
        Map<p, Integer> open_edges = new HashMap<>();
        List<int[]> events = new ArrayList<>();
        for (int i = 0; i < m; ++i) {
            int e[] = qs.get(i), t = e[0];
            if (t == 0) {
                int u = e[1], v = e[2];
                open_edges.put(new p(u, v), events.size());
                events.add(new int[] {0, i, m, u, v});
            } else if (t == 1) {
                int u = e[1], v = e[2];
                p key = new p(u, v);
                events.get(open_edges.get(key))[2] = i - 1;
            } else if (t == 2) {
                int u = e[1], v = e[2];
                events.add(new int[] {1, i, u, v, qid++});
            }
        }
        boolean ans[] = new boolean[qid];
        if (m == 0) return ans;
        solve_dynamic_connectivity_offline_r(0, m - 1, dsu, events, ans);
        return ans;
    }

    static void solve_dynamic_connectivity_offline_r(int l, int r, pdsu dsu, List<int[]> qs, boolean[] ans) {
        dsu.save();
        if (l == r) {
            for (int q[] : qs) {
                if (q[0] == 0 && q[1] <= l && r <= q[2]) {
                    dsu.union(q[3], q[4]);
                }
            }
            for (int q[] : qs) {
                if (q[0] == 1 && q[1] == l){
                    ans[q[4]] = dsu.find(q[2]) == dsu.find(q[3]);
                }
            }
        } else {
            List<int[]> nqs = new ArrayList<>();
            for (int q[] : qs) {
                if (q[0] == 0 && q[1] <= l && r <= q[2]) {
                    dsu.union(q[3], q[4]);
                } else if (q[0] == 1 && l <= q[1] && q[1] <= r || q[0] == 0 && l <= q[2] && q[1] <= r) {
                    nqs.add(q);
                }
            }
            int m = l + (r - l) / 2;
            solve_dynamic_connectivity_offline_r(l, m, dsu, nqs, ans);
            solve_dynamic_connectivity_offline_r(m + 1, r, dsu, nqs, ans);
        }
        dsu.rollback();
    }

    static class p {
        int a, b;

        p(int a_, int b_) {
            a = a_;
            b = b_;
            if (b < a) {
                int __swap = a;
                a = b;
                b = __swap;
            }
        }

        @Override
        public boolean equals(Object o) {
            p p = (p) o;
            return a == p.a && b == p.b;
        }

        @Override
        public int hashCode() {
            return Objects.hash(a, b);
        }
    }

    static class pdsu {
        int n, par[], sz[], moves_stack[], mp, save_stack[], sp;

        pdsu() {
            this(200005);
        }

        pdsu(int size) {
            this(size, 2 * size);
        }

        pdsu(int size, int stack_size) {
            n = size;
            par = new int[n];
            sz = new int[n];
            moves_stack = new int[stack_size];
            save_stack = new int[stack_size];
            reset();
        }

        void reset() {
            mp = sp = 0;
            for (int i = 0; i < n; ++i) {
                sz[par[i] = i] = 1;
            }
        }

        int find(int i) {
            return i == par[i] ? i : find(par[i]);
        }

        boolean union(int i, int j) {
            return union(i, j, true);
        }

        boolean union(int i, int j, boolean save) {
            int a = find(i), b = find(j);
            if (sz[b] > sz[a]) {
                int __swap = a;
                a = b;
                b = __swap;
            }
            moves_stack[mp++] = b;
            if (a != b) {
                par[b] = a;
                sz[a] += sz[b];
                return true;
            }
            return false;
        }

        void save() {
            save_stack[sp++] = mp;
        }

        // could have backstepped below save resulting in unintentional behavior
        void rollback() {
            --sp;
            while (mp > save_stack[sp]) {
                backstep();
            }
        }

        void backstep() {
            int b = moves_stack[--mp], a = par[b];
            if (a != b) {
                par[b] = b;
                sz[a] -= sz[b];
            }
        }
    }

    static BufferedReader __i = new BufferedReader(new InputStreamReader(System.in));
    static PrintWriter __o = new PrintWriter(new OutputStreamWriter(System.out));
    static StringTokenizer input;
    static Random __r = new Random();

    // references
    // IBIG = 1e9 + 7
    // IMAX ~= 2e9
    // LMAX ~= 9e18

    // constants
    static final int IBIG = 1000000007;
    static final int IMAX = 2147483647;
    static final long LMAX = 9223372036854775807L;
    // math util
    static int minof(int a, int b, int c) {return min(a, min(b, c));}
    static int minof(int... x) {if (x.length == 1) return x[0]; if (x.length == 2) return min(x[0], x[1]); if (x.length == 3) return min(x[0], min(x[1], x[2])); int min = x[0]; for (int i = 1; i < x.length; ++i) if (x[i] < min) min = x[i]; return min;}
    static long minof(long a, long b, long c) {return min(a, min(b, c));}
    static long minof(long... x) {if (x.length == 1) return x[0]; if (x.length == 2) return min(x[0], x[1]); if (x.length == 3) return min(x[0], min(x[1], x[2])); long min = x[0]; for (int i = 1; i < x.length; ++i) if (x[i] < min) min = x[i]; return min;}
    static int maxof(int a, int b, int c) {return max(a, max(b, c));}
    static int maxof(int... x) {if (x.length == 1) return x[0]; if (x.length == 2) return max(x[0], x[1]); if (x.length == 3) return max(x[0], max(x[1], x[2])); int max = x[0]; for (int i = 1; i < x.length; ++i) if (x[i] > max) max = x[i]; return max;}
    static long maxof(long a, long b, long c) {return max(a, max(b, c));}
    static long maxof(long... x) {if (x.length == 1) return x[0]; if (x.length == 2) return max(x[0], x[1]); if (x.length == 3) return max(x[0], max(x[1], x[2])); long max = x[0]; for (int i = 1; i < x.length; ++i) if (x[i] > max) max = x[i]; return max;}
    static int powi(int a, int b) {if (a == 0) return 0; int ans = 1; while (b > 0) {if ((b & 1) > 0) ans *= a; a *= a; b >>= 1;} return ans;}
    static long powl(long a, int b) {if (a == 0) return 0; long ans = 1; while (b > 0) {if ((b & 1) > 0) ans *= a; a *= a; b >>= 1;} return ans;}
    static int fli(double d) {return (int) d;}
    static int cei(double d) {return (int) ceil(d);}
    static long fll(double d) {return (long) d;}
    static long cel(double d) {return (long) ceil(d);}
    static int gcd(int a, int b) {return b == 0 ? a : gcd(b, a % b);}
    static long gcd(long a, long b) {return b == 0 ? a : gcd(b, a % b);}
    static int[] exgcd(int a, int b) {if (b == 0) return new int[] {1, 0, a}; int[] y = exgcd(b, a % b); return new int[] {y[1], y[0] - y[1] * (a / b), y[2]};}
    static long[] exgcd(long a, long b) {if (b == 0) return new long[] {1, 0, a}; long[] y = exgcd(b, a % b); return new long[] {y[1], y[0] - y[1] * (a / b), y[2]};}
    static int randInt(int min, int max) {return __r.nextInt(max - min + 1) + min;}
    static long mix(long x) {x += 0x9e3779b97f4a7c15L; x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9L; x = (x ^ (x >> 27)) * 0x94d049bb133111ebL; return x ^ (x >> 31);}
    // array util
    static void reverse(int[] a) {for (int i = 0, n = a.length, half = n / 2; i < half; ++i) {int swap = a[i]; a[i] = a[n - i - 1]; a[n - i - 1] = swap;}}
    static void reverse(long[] a) {for (int i = 0, n = a.length, half = n / 2; i < half; ++i) {long swap = a[i]; a[i] = a[n - i - 1]; a[n - i - 1] = swap;}}
    static void reverse(double[] a) {for (int i = 0, n = a.length, half = n / 2; i < half; ++i) {double swap = a[i]; a[i] = a[n - i - 1]; a[n - i - 1] = swap;}}
    static void reverse(char[] a) {for (int i = 0, n = a.length, half = n / 2; i < half; ++i) {char swap = a[i]; a[i] = a[n - i - 1]; a[n - i - 1] = swap;}}
    static void shuffle(int[] a) {int n = a.length - 1; for (int i = 0; i < n; ++i) {int ind = randInt(i, n); int swap = a[i]; a[i] = a[ind]; a[ind] = swap;}}
    static void shuffle(long[] a) {int n = a.length - 1; for (int i = 0; i < n; ++i) {int ind = randInt(i, n); long swap = a[i]; a[i] = a[ind]; a[ind] = swap;}}
    static void shuffle(double[] a) {int n = a.length - 1; for (int i = 0; i < n; ++i) {int ind = randInt(i, n); double swap = a[i]; a[i] = a[ind]; a[ind] = swap;}}
    static void rsort(int[] a) {shuffle(a); sort(a);}
    static void rsort(long[] a) {shuffle(a); sort(a);}
    static void rsort(double[] a) {shuffle(a); sort(a);}
    static int[] copy(int[] a) {int[] ans = new int[a.length]; for (int i = 0; i < a.length; ++i) ans[i] = a[i]; return ans;}
    static long[] copy(long[] a) {long[] ans = new long[a.length]; for (int i = 0; i < a.length; ++i) ans[i] = a[i]; return ans;}
    static double[] copy(double[] a) {double[] ans = new double[a.length]; for (int i = 0; i < a.length; ++i) ans[i] = a[i]; return ans;}
    static char[] copy(char[] a) {char[] ans = new char[a.length]; for (int i = 0; i < a.length; ++i) ans[i] = a[i]; return ans;}
    // input
    static void r() throws IOException {input = new StringTokenizer(rline());}
    static int ri() throws IOException {return Integer.parseInt(rline());}
    static long rl() throws IOException {return Long.parseLong(rline());}
    static double rd() throws IOException {return Double.parseDouble(rline());}
    static int[] ria(int n) throws IOException {int[] a = new int[n]; r(); for (int i = 0; i < n; ++i) a[i] = ni(); return a;}
    static void ria(int[] a) throws IOException {int n = a.length; r(); for (int i = 0; i < n; ++i) a[i] = ni();}
    static int[] riam1(int n) throws IOException {int[] a = new int[n]; r(); for (int i = 0; i < n; ++i) a[i] = ni() - 1; return a;}
    static void riam1(int[] a) throws IOException {int n = a.length; r(); for (int i = 0; i < n; ++i) a[i] = ni() - 1;}
    static long[] rla(int n) throws IOException {long[] a = new long[n]; r(); for (int i = 0; i < n; ++i) a[i] = nl(); return a;}
    static void rla(long[] a) throws IOException {int n = a.length; r(); for (int i = 0; i < n; ++i) a[i] = nl();}
    static double[] rda(int n) throws IOException {double[] a = new double[n]; r(); for (int i = 0; i < n; ++i) a[i] = nd(); return a;}
    static void rda(double[] a) throws IOException {int n = a.length; r(); for (int i = 0; i < n; ++i) a[i] = nd();}
    static char[] rcha() throws IOException {return rline().toCharArray();}
    static void rcha(char[] a) throws IOException {int n = a.length, i = 0; for (char c : rline().toCharArray()) a[i++] = c;}
    static String rline() throws IOException {return __i.readLine();}
    static String n() {return input.nextToken();}
    static int rni() throws IOException {r(); return ni();}
    static int ni() {return Integer.parseInt(n());}
    static long rnl() throws IOException {r(); return nl();}
    static long nl() {return Long.parseLong(n());}
    static double rnd() throws IOException {r(); return nd();}
    static double nd() {return Double.parseDouble(n());}
    // output
    static void pr(int i) {__o.print(i);}
    static void prln(int i) {__o.println(i);}
    static void pr(long l) {__o.print(l);}
    static void prln(long l) {__o.println(l);}
    static void pr(double d) {__o.print(d);}
    static void prln(double d) {__o.println(d);}
    static void pr(char c) {__o.print(c);}
    static void prln(char c) {__o.println(c);}
    static void pr(char[] s) {__o.print(new String(s));}
    static void prln(char[] s) {__o.println(new String(s));}
    static void pr(String s) {__o.print(s);}
    static void prln(String s) {__o.println(s);}
    static void pr(Object o) {__o.print(o);}
    static void prln(Object o) {__o.println(o);}
    static void prln() {__o.println();}
    static void pryes() {prln("yes");}
    static void pry() {prln("Yes");}
    static void prY() {prln("YES");}
    static void prno() {prln("no");}
    static void prn() {prln("No");}
    static void prN() {prln("NO");}
    static boolean pryesno(boolean b) {prln(b ? "yes" : "no"); return b;};
    static boolean pryn(boolean b) {prln(b ? "Yes" : "No"); return b;}
    static boolean prYN(boolean b) {prln(b ? "YES" : "NO"); return b;}
    static void prln(int... a) {for (int i = 0, len = a.length - 1; i < len; pr(a[i]), pr(' '), ++i); if (a.length > 0) prln(a[a.length - 1]); else prln();}
    static void prln(long... a) {for (int i = 0, len = a.length - 1; i < len; pr(a[i]), pr(' '), ++i); if (a.length > 0) prln(a[a.length - 1]); else prln();}
    static void prln(double... a) {for (int i = 0, len = a.length - 1; i < len; pr(a[i]), pr(' '), ++i); if (a.length > 0) prln(a[a.length - 1]); else prln();}
    static <T> void prln(Collection<T> c) {int n = c.size() - 1; Iterator<T> iter = c.iterator(); for (int i = 0; i < n; pr(iter.next()), pr(' '), ++i); if (n >= 0) prln(iter.next()); else prln();}
    static void h() {prln("hlfd"); flush();}
    static void flush() {__o.flush();}
    static void close() {__o.close();}
}