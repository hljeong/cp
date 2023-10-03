import java.io.*;
import java.util.*;

import static java.util.Arrays.*;

public class findtheroot {
  public static void main(String[] args) throws IOException {
    BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
    int m = Integer.parseInt(in.readLine());
    StringTokenizer input = new StringTokenizer(in.readLine());
    int fs[] = new int[m];
    for (int i = 0; i < m; ++i) fs[i] = Integer.parseInt(input.nextToken());
    sort(fs);
    for (int fui : fs) {
      if (fui == fs[m - 1] / 2) {
        System.out.println("yes");
        return;
      }
    }
    System.out.println("no");
  }
}
