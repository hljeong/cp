n = int(input())
for i in range(n): 
  d = input().split(',')
  for i in range(len(d)): 
    if d[i] == '': d[i] = '0'
  d = list(map(int, d))
  ret = 0
  for i in d: ret = ret * 60 + i
  print(ret)
