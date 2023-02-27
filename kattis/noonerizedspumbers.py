t = input().split(' ');
a = t[0]
b = t[2]
c = t[4]
op = (lambda x, y: x + y) if t[1] == '+' else (lambda x, y: x * y)
for i in range(1, len(a)): 
  for j in range(1, len(b)): 
    na = b[:j] + a[i:]
    nb = a[:i] + b[j:]
    if op(int(na), int(nb)) == int(c): 
      print(na, t[1], nb, '=', c)
      exit()
for i in range(1, len(a)): 
  for j in range(1, len(c)): 
    na = c[:j] + a[i:]
    nc = a[:i] + c[j:]
    if op(int(na), int(b)) == int(nc): 
      print(na, t[1], b, '=', nc)
      exit()
for i in range(1, len(b)): 
  for j in range(1, len(c)): 
    nb = c[:j] + b[i:]
    nc = b[:i] + c[j:]
    if op(int(a), int(nb)) == int(nc): 
      print(a, t[1], nb, '=', nc)
      exit()