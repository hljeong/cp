n, s = map(int, input().split())
p = []
for i in range(n): 
  t, b = input().split()
  b = int(b)
  p.append((t, b))
p.sort(key=lambda pp: -pp[1])
r = []
for pp in p: 
  if pp[1] <= s: 
    s -= pp[1]
    r.append(pp[0])
if s == 0: 
  print(len(r))
  for rr in r: print(rr)
else: 
  print(0)
