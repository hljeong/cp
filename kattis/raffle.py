n, p = map(int, input().split())
ret = p / (n + 1)
r = 2
while (n - p + r) / (n + r) * r / (r - 1) > 1: 
  ret *= (n - p + r) / (n + r) * r / (r - 1)
  r += 1
print(ret)