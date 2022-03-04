static int[] exgcd(int a, int b) {
  if (b == 0) return new int[] {1, 0};
  int[] y = exgcd(b, a % b);
  return new int[] {y[1], y[0] - y[1] * (a / b)};
}