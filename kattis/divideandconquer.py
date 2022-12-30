b, d = map(int, input().split())

if d == 2: 
  print("yes" if b % 2 == 1 else "no")
  exit(0)
e = d - 1
while e % 2 == 0: e //= 2
print("yes" if b % d != 0 and pow(b, e, d) != 1 else "no")