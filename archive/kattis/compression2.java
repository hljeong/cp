import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.Scanner;
import java.util.StringTokenizer;

class compression2 {
    static class FastReader {
        BufferedReader br;
        StringTokenizer st;

        public FastReader()
        {
            br = new BufferedReader(
                    new InputStreamReader(System.in));
        }

        String next()
        {
            while (st == null || !st.hasMoreElements()) {
                try {
                    st = new StringTokenizer(br.readLine());
                }
                catch (IOException e) {
                    e.printStackTrace();
                }
            }
            return st.nextToken();
        }

        int nextInt() { return Integer.parseInt(next()); }

        long nextLong() { return Long.parseLong(next()); }

        double nextDouble()
        {
            return Double.parseDouble(next());
        }

        String nextLine()
        {
            String str = "";
            try {
                if(st.hasMoreTokens()){
                    str = st.nextToken("\n");
                }
                else{
                    str = br.readLine();
                }
            }
            catch (IOException e) {
                e.printStackTrace();
            }
            return str;
        }
    }
    static long dp[][][];
    public static void main(String[] args){
        FastReader sc = new FastReader();
        int n = sc.nextInt();
        long c = sc.nextInt();
        long[] arr = new long[n];
        for (int i = 0; i < n; i++){
            arr[i] = sc.nextInt();
        }
        dp = new long[n][31][2];
        for (long[][] a : dp){
            for (long[] b : a){
                Arrays.fill(b, Long.MAX_VALUE);
            }
        }
        long min = Long.MAX_VALUE;
        min = Math.min(min, memoize(0,0,0,arr,c));
        System.out.println(min);
    }
    static long memoize(int cur, int bits, int mode, long[] arr, long c){
        if (cur >= arr.length){
            return 0;
        }
        if (dp[cur][bits][mode] != Long.MAX_VALUE){
            return dp[cur][bits][mode];
        }
        long min = Long.MAX_VALUE;
        long mode1max = (1L << bits);
        boolean success = false;
        if (cur != 0 && mode == 0 && arr[cur] >= 0 && mode1max > arr[cur]){
            success = true;
            min = Math.min(min, bits+memoize(cur+1,bits,mode,arr,c));
        }

        if(cur != 0 && mode == 1){
            long normalize = arr[cur]-arr[cur-1]+ (bits == 0 ? 0 : 1L << (bits - 1));
            if (mode1max > normalize && normalize >= 0) {
                success = true;
                min = Math.min(min, bits + memoize(cur + 1, bits, mode, arr, c));
            }
        }
        int start = 0;
        int end = 31;
        if (success) {
            end = bits;
        }else{
            start = bits;
        }
        for (int i = start; i < end; i++){
            long temp1 = (1L << i);
            if (temp1 > arr[cur]) {
                min = Math.min(min, c + i + memoize(cur + 1, i, 0, arr, c));
            }
            long normalize = 0;
            if (cur == 0) {
                normalize = arr[cur] + (i == 0 ? 0 : 1L << (i - 1));
            }else{
                normalize = arr[cur]-arr[cur-1]+ (i == 0 ? 0 : 1L << (i - 1));
            }
            if (normalize >= 0 && temp1 > normalize) {
                min = Math.min(min, i + c + memoize(cur + 1, i, 1, arr, c));
            }
        }
        dp[cur][bits][mode] = min;
        return min;
    }
}