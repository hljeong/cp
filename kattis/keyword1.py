n = int(input())
s = set()
for i in range(n): 
  s.add(input().lower().replace('-', ' '))
print(len(s))